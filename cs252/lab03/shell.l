
/*
 *
 * CS-413 Spring 98
 * shell.l: lexical analyzer for shell
 * You have to extend it.
 *
 */

%{

#include <string.h>
#include "y.tab.h"

char * read_line();

int mygetc(FILE * f) {
  static char *p;
  char ch;

  if (!isatty(0)) {
    // stdin is not a tty. Call real getc
    return getc(f);
  }

  // stdin is a tty. Call our read_line.

  if (p==NULL || *p == 0) {
    char * s = read_line();
    p = s;
  }

  ch = *p;
  p++;

  return ch;
}

#undef getc
#define getc(f) mygetc(f)

%}

%%

\n  { return NEWLINE; }

[ \t]  { /* Discard spaces and tabs */ }    

"&"  { return AMPERSAND; }

">"  { return GREAT; }

">&"  { return GREATAMPERSAND; }

">>"  { return GREATGREAT; }

">>&"  { return GREATGREATAMPERSAND; }

"<"  { return LESS; }

"|"  { return PIPE; }

\"[^\n\"]*\"  {
    yylval.string_val = strdup(yytext+1);
    yylval.string_val[strlen(yylval.string_val) - 1] = '\0';
    return WORD;
}

[^ \t\n][^ \t\n]*  {
    char *buff = strdup(yytext);
    char *word = (char*)malloc(strlen(buff)+2+1);
    
    int i = 0;
    while (buff[i] != NULL)
    {
        if (i+3 <= strlen(buff))
        {
            if (buff[i] != ' ' &&
                buff[i+1] == '>' &&
                buff[i+2] != ' ')
            {
                word[i] = buff[i];
                word[i+1] = ' ';
                word[i+2] = '>';
                word[i+3] = ' ';
            }
            else
            {
                word[i] = buff[i];
            }
        }
        else
        {
            word[i] = buff[i];
        }
    }
    
    yylval.string_val = strdup(word);
    
    return WORD;
}

.  {
    return NOTOKEN;
}

%%
    
