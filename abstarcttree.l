%{
#include<stdio.h>
#include "exp10.tab.h"
%}

%%
[a-zA-Z][a-zA-Z0-9]* {return ID;}
"+"    {return '+';}
"*"    {return '*';}    
"("    {return '(';} 
")"    {return ')';} 
\n      {return '\n';}
[\t]       ;
.       {return yytext[0];}
%%

int yywrap()
    {
       return 1;
    }

%{
    #include<stdio.h>
    #include<stdlib.h>
    int yylex();
    void yyerror(char *s);
%}

%token ID

%left'+'
%left'*'



%%
input:expr'\n'
    {
        printf("Valid expression\n");
    }
    ;
expr:expr '+' term
    {
        printf("Create + Node\n");
        
    }|term
    ;
term:term '*' factor
    {
        printf("Create * Node\n");
    }|factor
    ;
factor:ID
    {
        printf("Create ID Node\n");
    }|'(' expr ')'
    ;   
%%

int main()
{
    printf("enter expression:");
    yyparse();
    return 0;
}
void yyerror(char *s)
{
    printf("Invalid Expression\n");
}
