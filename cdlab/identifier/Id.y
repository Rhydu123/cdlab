%{
    #include<stdio.h>
    #include<stdlib.h>
    int yylex(void);
    int yyerror(char *s);
%}

%token digit letter

%%
s : letter p           
  ;

p : letter p            
  | digit p          
  |                    
  ;

%%


int main() 
{
    printf("\nEnter the name for testing: ");
    yyparse(); 
    printf("\nIt's an identifier\n");
    return 0;
}
int yyerror(char *s)
{
    printf("\nNot an identifier\n");
    exit(0);
}

/*-----------OUTPUT--------------
Enter the name for testing: expression1

It's an identifier

Enter the name for testing: 1exp

Not an identifier
*/
