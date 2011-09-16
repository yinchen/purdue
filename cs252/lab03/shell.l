
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

[^ \t\n][^ \t\n]*  {
    yylval.string_val = strdup(yytext);
	return WORD;
}

. {
	return NOTOKEN;
}

%%
	
