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
#include "command.h"
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
        printf("   Yacc: Execute command\n");
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
        printf("   Yacc: insert argument \"%s\"\n", $1);
        expandWildcardsIfNecessary($1);
    }
    ;

command_word:
    WORD {
        printf("   Yacc: insert command \"%s\"\n", $1);
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
        printf("   Yacc: insert output \"%s\"\n", $2);
        if (Command::_currentCommand._outFile)
            yyerror("Ambiguous output redirect.\n");
        Command::_currentCommand._outFile = $2;
    }
    | GREATGREAT WORD {
        printf("   Yacc: insert output \"%s\"\n", $2);
        Command::_currentCommand._append = 1;
        if (Command::_currentCommand._outFile)
            yyerror("Ambiguous output redirect.\n");
        Command::_currentCommand._outFile = $2;
    }
    | GREATAMPERSAND WORD {
        printf("   Yacc: insert output \"%s\"\n", $2);
        if (Command::_currentCommand._outFile)
            yyerror("Ambiguous output redirect.\n");
        Command::_currentCommand._outFile = $2;
        Command::_currentCommand._errFile = $2;
    }
    | GREATGREATAMPERSAND WORD {
        printf("   Yacc: insert output \"%s\"\n", $2);
        Command::_currentCommand._append = 1;
        if (Command::_currentCommand._outFile)
            yyerror("Ambiguous output redirect.\n");
        Command::_currentCommand._outFile = $2;
        Command::_currentCommand._errFile = $2;
    }
    | LESS WORD {
        printf("   Yacc: insert input \"%s\"\n", $2);
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

void
expandWildcardsIfNecessary(char * arg)
{
    if (strchr(arg, '*') == 0 &&
        strchr(arg, '?') == 0) { 
        Command::_currentSimpleCommand->insertArgument(arg); 
        return; 
    }
    
    // 1. Convert wildcard to regular expression 
    // Convert “*” -> “.*”
    //         “?” -> “.”
    //         “.” -> “\.”  and others you need 
    // Also add ^ at the beginning and $ at the end to match 
    // the beginning ant the end of the word. 
    // Allocate enough space for regular expression 
    char * reg = (char*)malloc(2*strlen(arg)+10);  
    char * a = arg; 
    char * r = reg; 
    *r = '^'; r++; // match beginning of line 
    while (*a) { 
        if (*a == '*') { *r='.'; r++; *r='*'; r++; } 
        else if (*a == '?') { *r='.'; r++;} 
        else if (*a == '.') { *r='\\'; r++; *r='.'; r++;} 
        else { *a=*r; r++;} 
        a++; 
    } 
    *r='$'; r++; *r=0;// match end of line and add null char

    // 2. compile regular expression 
    char * expbuf = compile(reg, 0, 0);  
    if (expbuf==NULL) { 
        perror("compile"); 
        return; 
    } 

    // 3. List directory and add as arguments the entries  
    // that match the regular expression 
    DIR * dir = opendir("."); 
    if (dir == NULL) { 
        perror("opendir"); 
        return; 
    } 

    closedir(dir);
    
    struct dirent * ent; 
    int maxEntries = 20; 
    nEntries = 0; 
    array = (char**) malloc(maxEntries*sizeof(char*)); 
    while ( (ent = readdir(dir))!= NULL) { 
        // Check if name matches 
        if (advance(ent->d_name, expbuf) ) { 
            if (nEntries == maxEntries) { 
                maxEntries *=2;  
                array = (char**)realloc(array, maxEntries*sizeof(char*)); 
                assert(array!=NULL); 
            } 
            array[nEntries]= strdup(ent->d_name); 
            nEntries++; 
        } 
    }
     
    // Add arguments 
    for (int i = 0; i < nEntries; i++) {  
        Command::_currentSimpleCommand->insertArgument(array[i]); 
    } 
    free(array);
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
