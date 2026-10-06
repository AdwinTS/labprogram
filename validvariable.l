%{
#include "exp7.tab.h"
%}

%%
[a-zA-Z][a-zA-Z0-9]* {return ID;}
. {return yytext[0];}
%%

int yywrap()
    {
       return 1;
    }

%{
    #include<stdio.h>
    int yylex();
    void yyerror(char *s);
%}

%token ID

%%
start:ID
    {
        printf("Valid Variable\n");
    }
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
    printf("Invalid Variable\n");
}
