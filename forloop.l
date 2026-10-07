%{
#include "exp10.tab.h"
%}
%%
for { return FOR; }
[a-zA-Z][a-zA-Z0-9]* { return ID; }
[0-9]+ { return NUM; }
"<"|">"|"<="|">="|"=="|"!=" { return RELOP; }
"=" { return '='; }
"++" { return INC; }
";" { return ';'; }
"(" { return '('; }
")" { return ')'; }
[ \t\n] ;
. { return yytext[0]; }
%%
int yywrap()
{
return 1;
}

YACC Program
%{
#include <stdio.h>
int yylex();
void yyerror(char *s);
%}
%token FOR ID NUM RELOP INC
%%
start : FOR '(' assign ';' condition ';' increment ')'
{
printf("Valid FOR Statement\n");
}
;
assign : ID '=' NUM
;
condition : ID RELOP NUM
;
increment : ID INC
;
%%
int main()
{
printf("Enter FOR Statement:\n");
yyparse();
return 0;
}
void yyerror(char *s)

{
printf("InvalidFORStatement\n");
}
