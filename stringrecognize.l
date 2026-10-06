%{
#include<stdio.h>
%}

%%
.*Adwin.* {printf("Rejected\n");}
.* {printf("Accepted\n");} 
%%

int yywrap()
    {
       return 1;
    }

int main()
{
    printf("enter expression:");
    yylex();
    return 0;
}
