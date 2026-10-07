%{
#include "exp12.tab.h"
%}

%%
switch { return SWITCH; }
case { return CASE; }
default { return DEFAULT; }
break { return BREAK; }
[a-zA-Z][a-zA-Z0-9]* { return ID; }
[0-9]+ { return NUM; }
"=" { return '='; }
":" { return ':'; }
";" { return ';'; }
"(" { return '('; }
")" { return ')'; }
"{" { return '{'; }
"}" { return '}'; }
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

%token SWITCH CASE DEFAULT BREAK ID NUM

%%

start : SWITCH '(' ID ')' '{' cases DEFAULT ':' statement '}'
{
    printf("Valid SWITCH Statement\n");
}
;

cases : CASE NUM ':' statement BREAK ';'
      | cases CASE NUM ':' statement BREAK ';'
;

statement : ID '=' NUM ';'
;

%%

int main()
{
    printf("Enter SWITCH Statement:\n");
    yyparse();
    return 0;
}

void yyerror(char *s)
{
    printf("Invalid SWITCH Statement\n");
}
