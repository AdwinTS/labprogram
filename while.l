%{
#include "exp11.tab.h"
%}

%%
while { return WHILE; }
[a-zA-Z][a-zA-Z0-9]* { return ID; }
[0-9]+ { return NUM; }
"<"|">"|"<="|">="|"=="|"!=" { return RELOP; }
"=" { return '='; }
";" { return ';'; }
"(" { return '('; }
")" { return ')'; }
"++" { return INC; }
[ \t\n] ;
. { return yytext[0]; }
%%

int yywrap()
{
    return 1;
}


%{
#include <stdio.h>

int yylex();
void yyerror(char *s);
%}

%token WHILE ID NUM RELOP INC

%%

start : WHILE '(' condition ')' ID INC
{
    printf("Valid WHILE Statement\n");
}
;

condition : ID RELOP NUM
;

%%

int main()
{
    printf("Enter WHILE Statement:\n");
    yyparse();
    return 0;
}

void yyerror(char *s)
{
    printf("Invalid WHILE Statement\n");
}
