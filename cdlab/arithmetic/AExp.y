%{
  #include<stdio.h>
  #include<stdlib.h>
  int yylex(void);
  int yyerror(char* s);
%}

%token NUMBER ID
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'

%%
expr :expr'+'expr  { printf("Addition\n"); }
     |expr'-'expr  { printf("Subtraction\n"); }
     |expr'*'expr  { printf("Multiplication\n"); }
     |expr'/'expr  { printf("Division\n"); }
     |expr'%'expr  { printf("Modulo\n"); }
     |'-'NUMBER     { printf("Negation of a number\n"); }
     |'-'ID         { printf("Negation of an ID\n"); }
     |'('expr')'   {  }
     |NUMBER         { printf("Number: %d\n", $1); }
     |ID             { printf("ID\n"); }
     ;

%%

int main(){
  printf("Enter the expression: ");
  yyparse();
  printf("Expression is valid\n");
  return 0;
}

int yyerror(char *s)
{
  printf("\nExpression is invalid\n");
  exit(0);
}
/*_______________OUTPUT______________________________
Enter the expression: a+b
ID
ID
Addition
Expression is valid
*/
