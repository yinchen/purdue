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
        expandWildcardsIfNecessary($1);
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

void expandWildcard(char * prefix, char *suffix) { 
    if (suffix[0]== 0) { 
        // suffix is empty. Put prefix in argument.
        Command::_currentCommand->insertArgument(strdup(prefix)); 
        return; 
    } 
    // Obtain the next component in the suffix 
    // Also advance suffix. 
    char * s = strchr(suffix, '/'); 
    char component[1024]; 
    if (s!=NULL){ // Copy up to the first “/”
        strncpy(component,suffix, s-suffix); 
        suffix = s + 1; 
    } 
    else { // Last part of path. Copy whole thing. 
        strcpy(component, suffix); 
        suffix = suffix + strlen(suffix); 
    }
    // Now we need to expand the component 
    char newPrefix[1024]; 
    if (strchr(arg, '*') == 0 &&
        strchr(arg, '?') == 0) { 
        // component does not have wildcards 
        sprintf(newPrefix,"%s/%s", prefix, component); 
        expandWildcard(newPrefix, suffix); 
        return; 
    } 
    
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
    *r='$'; r++; *r=0;
    
    char * expbuf = compile(reg, 0, 0);
    char * dir; 
    
    if (prefix == NULL || strlen(prefix) == 0) dir ="."; else dir=prefix; 
    DIR * d=opendir(dir); 
    if (d==NULL) return; 
    
    while ((ent = readdir(d))!= NULL)
    { 
        if (advance(ent->d_name, expbuf))
        { 
            sprintf(newPrefix,"%s/%s", prefix, ent->d_name);
            expandWildcard(newPrefix,suffix); 
        } 
    } 
    close(d); 
}

void
expandWildcardsIfNecessary(char * arg)
{
    expandWildcard(NULL, arg);
    return;
    
    if (strchr(arg, '*') == 0 &&
        strchr(arg, '?') == 0) { 
        // printf("   Yacc: insert argument \"%s\"\n", arg);
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

    struct dirent * ent; 
    int maxEntries = 20; 
    int nEntries = 0; 
    char** array = (char**) malloc(maxEntries*sizeof(char*)); 
    while ((ent = readdir(dir))!= NULL) { 
        // Check if name matches 
        if (advance(ent->d_name, expbuf) ) { 
            if (nEntries == maxEntries) { 
                maxEntries *=2;  
                array = (char**)realloc(array, maxEntries*sizeof(char*)); 
                assert(array!=NULL); 
            } 
            if (ent->d_name[0] == '.')
            {
                if (arg[0] == '.')
                {
                    array[nEntries]= strdup(ent->d_name); 
                    nEntries++; 
                }
            }
            else
            {
                array[nEntries]= strdup(ent->d_name); 
                nEntries++; 
            }
        } 
    }
     
    closedir(dir);
    
    // Add arguments 
    for (int i = 0; i < nEntries; i++) {  
        // printf("   Yacc: insert argument \"%s\"\n", array[i]);
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
