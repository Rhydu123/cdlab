%{
    #include <stdio.h>
    FILE *yyout; 
%}

KEYWORD     "if"|"else"|"while"|"for"|"int"|"float"|"void"|"char"|"return"
SYMBOL      ";"|","|"("|")"|"{"|"}"
OPERATOR    "+"|"-"|"*"|"="|"/"|"%"|">"|"<"

%%
{KEYWORD}          {fprintf(yyout, "\nKEYWORD: %s ", yytext);}
{SYMBOL}           {fprintf(yyout, "\nSYMBOL: %s ", yytext);}
[0-9]+             {fprintf(yyout, "\nNUMBER: %s ", yytext);}
{OPERATOR}         {fprintf(yyout, "\nOPERATOR: %s ", yytext);}
[A-Za-z_][A-Za-z0-9_]* {fprintf(yyout, "\nIDENTIFIER: %s ", yytext);}
[ \t\n]+           {}
.                  {fprintf(yyout, "Unknown Character: %s\n", yytext);}
%%

int main() {
    FILE *input_file = fopen("sample.txt", "r");
    yyout = fopen("tokens.txt", "w");

    yyin = input_file;
    yylex(); 

    fclose(input_file);
    fclose(yyout);

    return 0;
}

int yywrap() {
    return 1;
}
