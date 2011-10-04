%token  <string_val> WORD
%token  NOTOKEN, AMPERSAND, GREAT, GREATAMPERSAND, GREATGREAT, GREATGREATAMPERSAND, LESS, PIPE, NEWLINE

%union  {
    char *string_val;
}

%{
extern "C" int yylex();
#define yylex yylex
#include <stdio.h>
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
		Command::_currentCommand.execute();
	}
	| NEWLINE 
	| error NEWLINE { yyerrok; }
        |
	;

command_and_args:
	command_word arg_list {
		Command::_currentCommand.insertSimpleCommand( Command::_currentSimpleCommand );
	}
	;

arg_list:
	arg_list argument
	| /* can be empty */
	;

argument:
	WORD {
        	Command::_currentSimpleCommand->insertArgument( $1 );
	}
	;

command_word:
	WORD {
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
	    Command::_currentCommand._outFile = $2;
	}
	| GREATGREAT WORD {
	    Command::_currentCommand._append = 1;
	    Command::_currentCommand._outFile = $2;
	}
	| GREATAMPERSAND WORD {
	    Command::_currentCommand._outFile = $2;
	    Command::_currentCommand._errFile = $2;
	}
	| GREATGREATAMPERSAND WORD {
	    Command::_currentCommand._append = 1;
	    Command::_currentCommand._outFile = $2;
	    Command::_currentCommand._errFile = $2;
	}
	| LESS WORD {
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
yyerror(const char * s)
{
	fprintf(stderr,"%s", s);
}

#if 0
main()
{
	yyparse();
}
#endif
