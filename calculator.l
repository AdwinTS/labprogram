%{
#include<stdio.h>
#include "exp9.tab.h"
%}

%%
[0-9]+ {yylval=atoi(yytext);return NUM;}
[+\-*/()] {return yytext[0];}
\n        {return 0;}
[\t]       ;
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

%token NUM

%left'+''-'
%left'*''/'



%%
input:expr
    {
        printf("Result:%d\n",$1);
    }
    ;
expr:expr '+' expr
    {
        $$=$1+$3;
    }
    |expr '-' expr
    {
            $$=$1-$3;
    }
    |expr '*' expr
    {
            $$=$1*$3;
    }
    |expr '/' expr
    {
            $$=$1/$3;
    }
    |'(' expr ')'
    {
            $$=$2;
    }
    |NUM
    {
            $$=$1;
    }
    
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
