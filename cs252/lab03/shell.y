%token  <string_val> WORD
%token  NOTOKEN, AMPERSAND, GREAT, GREATAMPERSAND, GREATGREAT, GREATGREATAMPERSAND, LESS, PIPE, NEWLINE

%union  {
    char *string_val;
}

%{
extern "C" int yylex();
#define yylex yylex
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <regexpr.h>
#include <assert.h>
#include "command.h"

void geterror();
void sortArrayStrings();
void expandWildcard(char*,char*);
static int MAXFILENAME = 1024;

char** array;
int maxEntries = 10;
int nEntries = 0;
void reset();

int wilds = 0;
int found = 0;

%}

%%

goal:    
    commands
    ;

commands: 
    command
    | commands command 
    ;

command:
    simple_command
    ;

simple_command:    
    pipe_list io_modifier_list background_opt NEWLINE {
        // printf("   Yacc: Execute command\n");
        Command::_currentCommand.execute();
    }
    | NEWLINE {
        Command::_currentCommand.prompt();
    }
    | error NEWLINE { yyerrok; }
    ;

command_and_args:
    command_word arg_list {
        Command::_currentCommand.
            insertSimpleCommand( Command::_currentSimpleCommand );
    }
    ;

arg_list:
    arg_list argument
    | /* can be empty */
    ;

argument:
    WORD {
	char* arg = $1;
	char* temparg;
	
	if(strchr(arg, '\\') == NULL)
	{
		temparg = strdup(arg);
	}
	else
	{
		temparg = (char*)malloc(strlen(arg));
		int j = 0;
		int k = 0;
		while(arg[j])
		{
			if(arg[j] != '\\')
			{
			    temparg[k] = arg[j];
			    k++;
			}
		        else if(arg[j] == '\\' && arg[j+1] == '\\')
		        {
			    temparg[k] = '\\';
			    k++;
			    j++;
			}
			j++;
		}
	}
	
	expandWildcard(NULL, temparg);
	
	if(!found){
	array[0] = strdup(temparg);
	nEntries++;
	}
	if(wilds)
	sortArrayStrings();
	insertArgs();
	reset();
    }
    ;

command_word:
    WORD {
        // printf("   Yacc: insert command \"%s\"\n", $1);
        Command::_currentSimpleCommand = new SimpleCommand();
        Command::_currentSimpleCommand->insertArgument( $1 );
    }
    | /* can be empty */
    ;

pipe_list:
    pipe_list PIPE command_and_args
    | command_and_args
    ;

io_modifier:
    GREAT WORD {
        // printf("   Yacc: insert output \"%s\"\n", $2);
        if (Command::_currentCommand._outFile)
            yyerror("Ambiguous output redirect.\n");
        Command::_currentCommand._outFile = $2;
    }
    | GREATGREAT WORD {
        // printf("   Yacc: insert output \"%s\"\n", $2);
        Command::_currentCommand._append = 1;
        if (Command::_currentCommand._outFile)
            yyerror("Ambiguous output redirect.\n");
        Command::_currentCommand._outFile = $2;
    }
    | GREATAMPERSAND WORD {
        // printf("   Yacc: insert output \"%s\"\n", $2);
        if (Command::_currentCommand._outFile)
            yyerror("Ambiguous output redirect.\n");
        Command::_currentCommand._outFile = $2;
        Command::_currentCommand._errFile = $2;
    }
    | GREATGREATAMPERSAND WORD {
        // printf("   Yacc: insert output \"%s\"\n", $2);
        Command::_currentCommand._append = 1;
        if (Command::_currentCommand._outFile)
            yyerror("Ambiguous output redirect.\n");
        Command::_currentCommand._outFile = $2;
        Command::_currentCommand._errFile = $2;
    }
    | LESS WORD {
        // printf("   Yacc: insert input \"%s\"\n", $2);
        Command::_currentCommand._inputFile = $2;
    }
    ;

io_modifier_list:
    io_modifier_list io_modifier
    | io_modifier
    | /* empty */
    ;

background_opt:
    AMPERSAND {
        Command::_currentCommand._background = 1;
    }
    | /* empty */
    ;

%%

void expandWildcard(char* prefix, char* suffix)
{
	if(array == NULL)
		array = (char**)malloc(maxEntries*sizeof(char*));
		
	if(suffix[0] == 0)
	{
		found = 1;
		if(nEntries == maxEntries)
		{
			maxEntries *= 2;
			array = (char**)realloc(array, maxEntries*sizeof(char*));
		}
		
		array[nEntries] = strdup(prefix);
		nEntries++;
		return;
	}
		
	if(strchr(suffix, '*') || strchr(suffix, '?'))
		wilds = 1;

	char* s = strchr(suffix, '/');

	char component[MAXFILENAME];
	if(s != NULL)
	{
		if(s-suffix != 0)
		{
			strncpy(component, suffix, s-suffix);
			component[strlen(suffix)-strlen(s)] = 0;
		}
		else
		{
			component[0] = '\0';
		}
		suffix = s + 1;
	}
	else
	{
		strcpy(component, suffix);
		suffix = suffix + strlen(suffix);
	}
	
	char newPrefix[MAXFILENAME];

	if(strchr(component, '*') == NULL && strchr(component, '?') == NULL)
	{
		if(prefix == NULL && component[0] != '\0')
			sprintf(newPrefix, "%s", component);
		else if(component[0] != '\0')
			sprintf(newPrefix,"%s/%s", prefix, component);

		if(component[0] != '\0')
			expandWildcard(newPrefix, suffix);
		else
			expandWildcard("", suffix);
		
		return;
	}

	char * reg = (char*)malloc(2*strlen(component)+10); 
	char * a = component;
	char * r = reg;
	*r = '^'; r++; // match beginning of line
	while (*a)
	{
		if (*a == '*') { *r='.'; r++; *r='*'; r++; }
		else if (*a == '?') { *r='.'; r++;}
		else if (*a == '.') { *r='\\'; r++; *r='.'; r++;}
		else { *r=*a; r++;}
		a++;
	}
	*r='$'; r++; *r=0;

	char *expbuf = (char*)malloc(strlen(reg));
	compile(reg, expbuf, &expbuf[strlen(expbuf)+1], '$');
	if(expbuf == NULL)
	{
		perror("compile");
		return;
	}

	char* dir2;
	if(prefix == NULL)
	{
		dir2 = ".";
	}else if(!strcmp("", prefix))
	{
		dir2 = strdup("/");
	}
	else
	{
		dir2 = prefix;
	}

	DIR *dir = opendir(dir2);
	if(dir == NULL)
	{
		//perror("opendir");
		return;
	}

	struct dirent *ent;

	while ((ent = readdir(dir))!= NULL)
	{
		if (advance(ent->d_name, expbuf))
		{
			if(ent->d_name[0] == '.')
			{
				if(component[0] == '.')
				{
					if(prefix == NULL)
					{
						sprintf(newPrefix,"%s",ent->d_name);
					}
					else
					{
						sprintf(newPrefix,"%s/%s", prefix, ent->d_name);
					}
					expandWildcard(newPrefix,suffix);
				}
			}
			else
			{
				if(prefix == NULL)
				{
					sprintf(newPrefix,"%s",ent->d_name);
				}
				else
				{
					sprintf(newPrefix,"%s/%s", prefix, ent->d_name);
				}
				expandWildcard(newPrefix,suffix);
			}
		}
	}

	closedir(dir);
	return;
}

void reset()
{
    free(array);
    nEntries = 0;
    maxEntries = 10;
    array = NULL;
    found = 0;
    wilds = 0;

    return;
}

void sortArrayStrings()
{
    int i;
    for(i = 0; i < nEntries-1; i++)
    {
        int j=0;
        for(; j<nEntries-1; j++)
        {
            char* one = array[j];
            char* two = array[j+1];
            if(strcmp(one, two) > 0)
            {
                char* three = array[j];
                array[j] = two;
                array[j+1] = three;
            }
        }
    }

    return;
}

void insertArgs()
{
    int j;
    for(j = 0; j < nEntries; j++)
    {
        Command::_currentSimpleCommand->insertArgument(strdup(array[j]));
        fflush(0);
    }
    return;
}

void
yyerror(const char * s)
{
    Command::_currentCommand._hasError = 1;
    fprintf(stderr,"%s", s);
}

#if 0
main()
{
    yyparse();
}
#endif
