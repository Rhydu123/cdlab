%{
    #include <stdio.h>
    #include "AEXp.tab.h"
%}
%%

[0-9]+      { yylval = atoi(yytext); return NUMBER; }
[a-zA-Z]+   { return ID; }
[\t ]+      { /* skip whitespace */ }
\n          { return 0; } 
.           { return yytext[0]; } 

%%

int yywrap()
{
    return 1;
}
