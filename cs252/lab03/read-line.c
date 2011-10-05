/*
 * CS354: Operating Systems. 
 * Purdue University
 * Example that shows how to read one line with simple editing
 * using raw terminal.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_BUFFER_LINE 2048

int line_length;
char line_buffer[MAX_BUFFER_LINE];

int curs_pos;

int history_index = 0;
char **history;

int history_length = 0;

char * read_line()
{
    tty_raw_mode();

    line_length = 0;
    curs_pos = 0;

    while (1)
    {
        char ch;
        read(0, &ch, 1);
        
        if (ch>=32 && ch<=125)
        {
            // It is a printable character. 

            // Do echo
            write(1,&ch,1);

            // If max number of character reached return.
            if (line_length==MAX_BUFFER_LINE-2) break; 

            // move chars after cursor + 1
            int i;
            for (i = line_length + 1; i > curs_pos; i--)
            {
                line_buffer[i] = line_buffer[i - 1];
            }

            // add char to buffer.
            line_buffer[curs_pos]=ch;
            line_length++;
            
            curs_pos++;
            
            // reprint display
            for (i = curs_pos; i < line_length; i++)
            {
                ch = line_buffer[i];
                write(1,&ch,1);
            }
            
            // Erase leftover char
            ch = 32;
            write(1,&ch,1);
            
            ch = 8;
            write(1,&ch,1);
            
            // return character position
            for (i = curs_pos; i < line_length; i++)
            {
                ch = 27;
                write(1,&ch,1);
                ch = 91;
                write(1,&ch,1);
                ch = 68;
                write(1,&ch,1);
            }
        }
        else if (ch==10)
        {
            // <Enter> was typed. Return line
            
            // insert this line to history
            if (history_length == 0)
            {
                history = malloc(sizeof(char*) * 100);
            }
            
            history[history_length] = malloc(sizeof(char) * MAX_BUFFER_LINE);
            strncpy(history[history_length], line_buffer, line_length);
            
            history_length++;
            
            // Print newline
            write(1,&ch,1);            
            break;
        }
        else if (ch == 8 || ch == 127)
        {
            // <backspace> was typed. Remove previous character read.

            // If at front of line
            if (line_length==0 || curs_pos==0) continue;

            // move chars after cursor + 1
            int i;
            for (i = curs_pos; i < line_length; i++)
            {
                line_buffer[i - 1] = line_buffer[i];
            }
            
            line_length--;
            curs_pos--;
            
            // Write a space to erase the last character read
            ch = 32;
            write(1,&ch,1);
            
            // Go back one character
            ch = 8;
            write(1,&ch,1);                     
            
            // Go back one character
            ch = 8;
            write(1,&ch,1); 
            
            // reprint display
            for (i = curs_pos; i < line_length; i++)
            {
                ch = line_buffer[i];
                write(1,&ch,1);
            }
            
            // Erase leftover char
            ch = 32;
            write(1,&ch,1);
            
            ch = 8;
            write(1,&ch,1);
            
            // return character position
            for (i = curs_pos; i < line_length; i++)
            {
                ch = 27;
                write(1,&ch,1);
                ch = 91;
                write(1,&ch,1);
                ch = 68;
                write(1,&ch,1);
            }
        }
        else if (ch == 4)
        {
            // <delete> was typed. remove next char

            // If at end of line
            if (curs_pos==line_length) continue;
            
            // Write a space to erase the last character read
            ch = 32;
            write(1,&ch,1);

            // Go back one character
            ch = 8;
            write(1,&ch,1);
            
            // move chars after cursor + 1
            int i;
            for (i = curs_pos; i < line_length - 1; i++)
            {
                line_buffer[i] = line_buffer[i + 1];
            }
            
            line_length--;
            
            // reprint display
            for (i = curs_pos; i < line_length; i++)
            {
                ch = line_buffer[i];
                write(1,&ch,1);
            }
            
            // Erase leftover char
            ch = 32;
            write(1,&ch,1);
            
            ch = 8;
            write(1,&ch,1);
            
            // return character position
            for (i = curs_pos; i < line_length; i++)
            {
                ch = 27;
                write(1,&ch,1);
                ch = 91;
                write(1,&ch,1);
                ch = 68;
                write(1,&ch,1);
            }
        }
        else if (ch == 1)
        {
            // <home> was typed.

            // If at front of line
            if (line_length==0 || curs_pos==0) continue;
            
            // Go back to front
            int i = 0;
            for (i =0; i < curs_pos; i++)
            {
                ch = 27;
                write(1,&ch,1);
                ch = 91;
                write(1,&ch,1);
                ch = 68;
                write(1,&ch,1);
            }

            curs_pos = 0;
        }
        else if (ch == 5)
        {
            // <end> was typed.

            // If at front of line
            if (line_length==0 || curs_pos==line_length) continue;
            
            // Go to end
            int i = 0;
            for (i = curs_pos; i < line_length; i++)
            {
                ch = 27;
                write(1,&ch,1);
                ch = 91;
                write(1,&ch,1);
                ch = 67;
                write(1,&ch,1);
            }

            curs_pos = line_length;
        }
        else if (ch==27)
        {
            char ch1; 
            char ch2;
            read(0, &ch1, 1);
            read(0, &ch2, 1);
            if (ch1==91 && ch2==65)
            {
                // Up arrow. Print next line in history.
                
                // check for history
                if (history_length == 0) continue; 
                
                // Erase old line
                // Print backspaces
                int i = 0;
                for (i =0; i < line_length; i++)
                {
                    ch = 8;
                    write(1,&ch,1);
                }

                // Print spaces on top
                for (i =0; i < line_length; i++)
                {
                    ch = ' ';
                    write(1,&ch,1);
                }

                // Print backspaces
                for (i =0; i < line_length; i++)
                {
                    ch = 8;
                    write(1,&ch,1);
                }    

                // Copy line from history
                if (history_index < history_length)
                    history_index++;
                
                strcpy(line_buffer, history[history_length - history_index]);
                line_length = strlen(line_buffer);
                
                // echo line
                write(1, line_buffer, line_length);
                
                curs_pos = line_length;
            }
            else if (ch1==91 && ch2==66)
            {
                // Down arrow. Print prev line in history.
                
                // Erase old line
                // Print backspaces
                int i = 0;
                for (i =0; i < line_length; i++)
                {
                    ch = 8;
                    write(1,&ch,1);
                }

                // Print spaces on top
                for (i =0; i < line_length; i++)
                {
                    ch = ' ';
                    write(1,&ch,1);
                }

                // Print backspaces
                for (i =0; i < line_length; i++)
                {
                    ch = 8;
                    write(1,&ch,1);
                }    
                
                printf("history_index = %d\n", history_index);
                printf("history_length = %d\n", history_length);
                
                // Copy line from history
                if (history_index > 0)
                {
                    history_index--;                    
                    strcpy(line_buffer, history[history_length - history_index]);
                    line_length = strlen(line_buffer);
                    
                    // echo line
                    write(1, line_buffer, line_length);
                }

                curs_pos = line_length;
            }
            else if (ch1==91 && ch2==68)
            {
                // left arrow
                
                // If at front of line
                if (curs_pos==0) continue;
                
                // Go back one character
                ch = 27;
                write(1,&ch,1);
                ch = 91;
                write(1,&ch,1);
                ch = 68;
                write(1,&ch,1);
                
                curs_pos--;
            }
            else if (ch1==91 && ch2==67)
            {
                // right arrow
                
                // If at end of line
                if (curs_pos==line_length) continue;
                
                // Go forward one character
                ch = 27;
                write(1,&ch,1);
                ch = 91;
                write(1,&ch,1);
                ch = 67;
                write(1,&ch,1);
                
                curs_pos++;
            }
            else if (ch1==91 && ch2==51)
            {
                char ch3;
                read(0, &ch3, 1);
                
                if (ch3==126)
                {
                    // <delete> was typed. remove next char

                    // If at end of line
                    if (curs_pos==line_length) continue;
                    
                    // Write a space to erase the last character read
                    ch = 32;
                    write(1,&ch,1);

                    // Go back one character
                    ch = 8;
                    write(1,&ch,1);
                    
                    // move chars after cursor + 1
                    int i;
                    for (i = curs_pos; i < line_length - 1; i++)
                    {
                        line_buffer[i] = line_buffer[i + 1];
                    }
                    
                    line_length--;
                    
                    // reprint display
                    for (i = curs_pos; i < line_length; i++)
                    {
                        ch = line_buffer[i];
                        write(1,&ch,1);
                    }
                    
                    // Erase leftover char
                    ch = 32;
                    write(1,&ch,1);
                    
                    ch = 8;
                    write(1,&ch,1);
                    
                    // return character position
                    for (i = curs_pos; i < line_length; i++)
                    {
                        ch = 27;
                        write(1,&ch,1);
                        ch = 91;
                        write(1,&ch,1);
                        ch = 68;
                        write(1,&ch,1);
                    }
                }
            }
        }
    }

    // Add eol and null char at the end of string
    line_buffer[line_length]=10;
    line_length++;
    line_buffer[line_length]=0;
    
    return line_buffer;
}

