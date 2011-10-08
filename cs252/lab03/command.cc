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
#include <regexpr.h>
#include <pwd.h>

#include "command.h"

extern char **environ;

int *backgroundPIDs;

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
        _arguments = (char **) realloc( _arguments, _numberOfAvailableArguments * sizeof(char *));
    }
    
    // insert environment variables
    char* finalString = (char*)malloc(2048);
    if (strchr(argument, '$'))
    {
        int j=0;
        int k=0;
        while(argument[j] != '\0')
        {
            if(argument[j] == '$')
            {
                char* var = (char*)malloc(strlen(argument));
                j+=2;
                while(argument[j] != '}')
                {
                    var[k] = argument[j];
                    k++;
                    j++;
                }
                var[k] = '\0';
                strcat(finalString, getenv(var));
                free(var);
                k = 0;
            }
            else
            {
                char* temp = (char*)malloc(strlen(argument));
                while(argument[j] != '\0' && argument[j] != '$')
                {
                    temp[k] = argument[j];
                    k++;
                    j++;
                }
                k=0;
                strcat(finalString, temp);
                free(temp);
                j--;
            }
            j++;
        }
        _arguments[_numberOfArguments] = strdup(finalString);
    }
    
    // insert home directory
    if (argument[0] == '~')
    {
        if (strlen(argument) == 1)
        {
            argument = strdup(getenv("HOME"));
        }
        else
        {
            argument = strdup(getpwnam(argument+1)->pw_dir);
        }
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
    
    if (_hasError)
    {
        _hasError = 0;
        
        clear();
        prompt();
        return;
    }
    
    if (strcmp(_simpleCommands[0]->_arguments[0], "setenv") == 0)
    {
        int result = setenv(_simpleCommands[0]->_arguments[1], _simpleCommands[0]->_arguments[2], 1);
        if (result != 0)
            perror("setenv");
        
        clear();
        prompt();
        return;
    }
    
    if (strcmp(_simpleCommands[0]->_arguments[0], "unsetenv") == 0)
    {
        int result = unsetenv(_simpleCommands[0]->_arguments[1]);
        if (result != 0)
            perror("unsetenv");
        
        clear();
        prompt();
        return;
    }
    
    if (strcmp(_simpleCommands[0]->_arguments[0], "cd") == 0)
    {
        char **p = environ;                
        while(*p != NULL)
        {
            if (strncmp(*p, "HOME", 4) == 0)
            {
                break;
            }
            p++;
        }
        
        char *home = (char*)malloc(strlen(*p) - 5);
        strcpy(home, *p+5);
        
        int result;
        if (_simpleCommands[0]->_numberOfArguments > 1)
            result = chdir(_simpleCommands[0]->_arguments[1]);
        else
            result = chdir(home);
        
        if (result != 0)
            perror("chdir");
        
        clear();
        prompt();
        return;
    }

    // print();
    
    int defaultin = dup(0);
    int defaultout = dup(1);
    int defaulterr = dup(2);
    
    int fdin = 0;
    int fdout = 0;
    int fderr = 0;
    
    if (_inputFile == 0)
    {
        fdin = dup(defaultin);
    }
    else
    {
        fdin = open(_inputFile, O_RDONLY);
    }
    
    if (_errFile == 0)
    {
        fderr = dup(defaulterr);
    }
    else
    {
        if (_append)
            fderr = open(_errFile, O_WRONLY|O_CREAT|O_APPEND, 0600);
        else
            fderr = open(_errFile, O_WRONLY|O_CREAT|O_TRUNC, 0600);
    }
    dup2(fderr, 2);
    close(fderr);
    
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
                    fdout = open(_outFile, O_WRONLY|O_CREAT|O_APPEND, 0600);
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
                    fderr = open(_errFile, O_WRONLY|O_CREAT|O_APPEND, 0600);
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
            if (strcmp(_simpleCommands[i]->_arguments[0], "printenv") == 0)
            {
                char **p = environ;
                
                while(*p != NULL)
                {
                    printf("%s\n", *p);
                    p++;
                }
                
                exit(0);
            }
        
            execvp(_simpleCommands[i]->_arguments[0], _simpleCommands[i]->_arguments);
            perror(_simpleCommands[i]->_arguments[0]);
                
            _exit(1);
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
        
        clear();
        prompt();
    }
    else
    {
        int y;
        for (y = 0; y < 1024; y++)
        {
            if (backgroundPIDs[y] == 0)
                break;
        }
        backgroundPIDs[y] = pid;
        
        clear();
    }
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

extern "C" void killzombie(int sig)
{
    int pid = wait3(0, 0, NULL);
    while(waitpid(-1, NULL, WNOHANG) > 0);
    
    int found = 0;
    
    int y;
    for (y = 0; y < 1024; y++)
    {
        if (backgroundPIDs[y] == pid)
            found = 1;
    }
    
    if (found == 1)
    {
        printf("[%d] exited.\n", pid);    
        Command::_currentCommand.prompt();
    }
}

int main(int argc, char* argv[])
{
    backgroundPIDs = (int*)malloc(sizeof(int) * 1024);
    
    struct sigaction signalAction1;
    
    signalAction1.sa_handler = disp;
    sigemptyset(&signalAction1.sa_mask);
    signalAction1.sa_flags = SA_RESTART;
    
    int error1 = sigaction(SIGINT, &signalAction1, NULL);
    if (error1)
    {
        perror("sigaction");
        exit(-1);
    }
    
    struct sigaction signalAction2;
    
    signalAction2.sa_handler = killzombie;
    sigemptyset(&signalAction2.sa_mask);
    signalAction2.sa_flags = SA_RESTART;
    
    int error2 = sigaction(SIGCHLD, &signalAction2, NULL );
    if (error2) 
    {
        perror("sigaction");
        exit(-1);
    }
    
    if (strcmp(argv[1], "--debug") == 0)
    {
        printf("Launching mash in debug mode.\n");
    }
    
    Command::_currentCommand.prompt();
    yyparse();
}

