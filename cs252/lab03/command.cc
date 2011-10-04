/*
 * CS354: Shell project
 *
 * Template file.
 * You will need to add more code here to execute the command table.
 *
 * NOTE: You are responsible for fixing any bugs this code may have!
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>

#include "command.h"

SimpleCommand::SimpleCommand()
{
	// Creat available space for 5 arguments
	_numberOfAvailableArguments = 5;
	_numberOfArguments = 0;
	_arguments = (char **) malloc( _numberOfAvailableArguments * sizeof( char * ) );
}

void
SimpleCommand::insertArgument( char * argument )
{
	if ( _numberOfAvailableArguments == _numberOfArguments  + 1 ) {
		// Double the available space
		_numberOfAvailableArguments *= 2;
		_arguments = (char **) realloc( _arguments, _numberOfAvailableArguments * sizeof( char * ) );
	}
	
	_arguments[ _numberOfArguments ] = argument;

	// Add NULL argument at the end
	_arguments[ _numberOfArguments + 1] = NULL;
	
	_numberOfArguments++;
}

Command::Command()
{
	// Create available space for one simple command
	_numberOfAvailableSimpleCommands = 1;
	_simpleCommands = (SimpleCommand **)
		malloc( _numberOfSimpleCommands * sizeof( SimpleCommand * ) );

	_numberOfSimpleCommands = 0;
	_outFile = 0;
	_inputFile = 0;
	_errFile = 0;
	_background = 0;
	
	_append = 0;
}

void
Command::insertSimpleCommand( SimpleCommand * simpleCommand )
{
	if ( _numberOfAvailableSimpleCommands == _numberOfSimpleCommands ) {
		_numberOfAvailableSimpleCommands *= 2;
		_simpleCommands = (SimpleCommand **) realloc( _simpleCommands,
			 _numberOfAvailableSimpleCommands * sizeof( SimpleCommand * ) );
	}
	
	_simpleCommands[ _numberOfSimpleCommands ] = simpleCommand;
	_numberOfSimpleCommands++;
}

void
Command:: clear()
{
	for ( int i = 0; i < _numberOfSimpleCommands; i++ ) {
		for ( int j = 0; j < _simpleCommands[ i ]->_numberOfArguments; j ++ ) {
			free ( _simpleCommands[ i ]->_arguments[ j ] );
		}
		
		free ( _simpleCommands[ i ]->_arguments );
		free ( _simpleCommands[ i ] );
	}

	if ( _outFile ) {
		free( _outFile );
	}

	if ( _inputFile ) {
		free( _inputFile );
	}

	if ( _errFile ) {
		free( _errFile );
	}

	_numberOfSimpleCommands = 0;
	_outFile = 0;
	_inputFile = 0;
	_errFile = 0;
	_background = 0;
}

void
Command::print()
{
	printf("\n\n");
	printf("              COMMAND TABLE                \n");
	printf("\n");
	printf("  #   Simple Commands\n");
	printf("  --- ----------------------------------------------------------\n");
	
	for ( int i = 0; i < _numberOfSimpleCommands; i++ ) {
		printf("  %-3d ", i );
		for ( int j = 0; j < _simpleCommands[i]->_numberOfArguments; j++ ) {
			printf("\"%s\" \t", _simpleCommands[i]->_arguments[ j ] );
		}
		printf("\n");
	}

	printf( "\n\n" );
	printf( "  Output       Input        Error        Background\n" );
	printf( "  ------------ ------------ ------------ ------------\n" );
	printf( "  %-12s %-12s %-12s %-12s\n", _outFile?_outFile:"default",
		_inputFile?_inputFile:"default", _errFile?_errFile:"default",
		_background?"YES":"NO");
	printf( "\n\n" );
	
}

void
Command::execute()
{
    if (_numberOfSimpleCommands == 0)
    {   
        prompt();
        return;
    }
    
    if (strcmp(_simpleCommands[0]->_arguments[0], "exit") == 0)
    {
        printf("Thank you for using Matt's Awesome Shell. Goodbye!\n\n");
        exit(1);
    }

    // print();
	
    int defaultin = dup(0);
    int defaultout = dup(1);
    int defaulterr = dup(2);
    
    int fdin;
    int fdout;
    int fderr;
    
    if (_inputFile == 0)
    {
        fdin = dup(defaultin);
    }
    else
    {
        fdin = open(_inputFile, O_RDONLY);
    }
    
    int pid;
	
    int i;
    for (i = 0; i < _numberOfSimpleCommands; i++)
    {
	    dup2(fdin, 0);
	    close(fdin);
	    
	    if (i == _numberOfSimpleCommands - 1)
	    {
	        if (_outFile == 0)
            {
                fdout = dup(defaultout);
            }
            else
            {
                if (_append)
                    fdout = open(_outFile, O_WRONLY|O_APPEND|O_TRUNC, 0600);
                else
                    fdout = open(_outFile, O_WRONLY|O_CREAT|O_TRUNC, 0600);
            }
            
            if (_errFile == 0)
            {
                fderr = dup(defaulterr);
            }
            else
            {
                if (_append)
                    fderr = open(_errFile, O_WRONLY|O_APPEND|O_TRUNC, 0600);
                else
                    fderr = open(_errFile, O_WRONLY|O_CREAT|O_TRUNC, 0600);
            }
        }
        else
        {
            int fdpipe[2];
            pipe(fdpipe);
            fdout = fdpipe[0];
            fdin = fdpipe[1];
        }
        
        dup2(fdout, 1);
        close(fdout);
        
        dup2(fderr, 2);
        close(fderr);
    
        pid = fork();
	if (pid == -1)
	{
	    perror(_simpleCommands[i]->_arguments[0]);
	    
	    clear();
	    prompt();
	    return;
	}
        if (pid == 0)
        {
            execvp(_simpleCommands[i]->_arguments[0], _simpleCommands[i]->_arguments);
            perror(_simpleCommands[i]->_arguments[0]);
                
            clear();
            prompt();
            return;
        }
    }
    
    dup2(defaultin, 0);
    dup2(defaultout, 1);
    dup2(defaulterr, 2);
    
    close(defaultin);
    close(defaultout);
    close(defaulterr);
    
    if (_background == 0)
    {
        waitpid(pid, 0, 0);
    }
    
    clear();
    prompt();
}

// Shell implementation

void
Command::prompt()
{
    if (isatty(0))
    {
    	printf("mash> ");
    	fflush(stdout);
    }
}

Command Command::_currentCommand;
SimpleCommand * Command::_currentSimpleCommand;

int yyparse(void);

extern "C" void disp(int sig)
{
    printf("\n");
    Command::_currentCommand.prompt();
}

main()
{
    struct sigaction signalAction;
    
    signalAction.sa_handler = disp;
    sigemptyset(&signalAction.sa_mask);
    signalAction.sa_flags = SA_RESTART;
    
    int error = sigaction(SIGINT, &signalAction, NULL);
    if ( error )
    {
        perror("sigaction");
        exit(-1);
    }
    
    Command::_currentCommand.prompt();
    yyparse();
}

