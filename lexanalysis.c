#include<stdio.h>
#include<ctype.h>

int main()
{
    char str[100],ch;
    printf("enter the expression:");
    fgets(str,sizeof(str),stdin);
    int i=0;
    while((ch=str[i])!='\0')
        {
            if (ch==' '|| ch=='\t'||ch=='\n')
            {
                i++;
                continue;
            }
            if(isalpha(ch))
            {
                printf("%c: Identifier\n",ch);
            }
            else if(isdigit(ch))
            {
                printf("%c",ch);
                i++;
                while(isdigit(str[i]))
                    {
                        printf("%c",str[i]);
                i++;
                    }
                printf(":Number\n");
            }
            else{
                printf("%c: Operator\n",ch);
            }
            i++;
            
        }

    return 0;
}a
