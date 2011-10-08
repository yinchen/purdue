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

(([\\][^])*([^ \\ & > < | \t \n])*)*  {
    yylval.string_val = strdup(yytext);
    return WORD;
}

\n  { return NEWLINE; }

[ \t]  { /* Discard spaces and tabs */ }    

"&"  { return AMPERSAND; }

">"  { return GREAT; }

">&"  { return GREATAMPERSAND; }

">>"  { return GREATGREAT; }

">>&"  { return GREATGREATAMPERSAND; }

"<"  { return LESS; }

"|"  { return PIPE; }

["][^"]*["]  {
    yylval.string_val = strdup(yytext+1);
    if(yylval.string_val[yyleng-2] == '"')
        yylval.string_val[yyleng-2] = 0;
    return WORD;
}

[\`][^\`]*[\`]  {
    yylval.string_val = strdup(yytext+1);
    if(yylval.string_val[yyleng-2] == '`')
        yylval.string_val[yyleng-2] = 0;
    return SHELLWORD;
}

[^ ^\\&<>|\t\n][^ ^\\&<>|\t\n]*  {
    yylval.string_val = strdup(yytext);
    return WORD;
}

.  {
    return NOTOKEN;
}

%%
    
