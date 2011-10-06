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
    char *buff = "";
    char *word = strdup(yytext);
    
    int j;
    j = 0;

    int i;
    i = 0;
    while (i < strlen(buff) + 1)
    {
        if (buff[i] == '\\')
        {
            word[j] = buff[i+1];
            i = i + 2;
        }
        else
        {
            word[j] = buff[i];
            i++;
        }

        j++;
    }

    yylval.string_val = strdup(yytext);
    return WORD;
}

.  {
    return NOTOKEN;
}

%%
    
