#include <stdio.h>
#include <stdlib.h>
int n,m,vis[1024],q[1024],r=0,f=0,t[10][2];
int main() {

    printf("Enter no of states:");
    scanf("%d",&n);
    printf("Enter no of transiistions:");
    scanf("%d",&m);

    printf("enter transisition from_input to input(0/1) to end:\n");

    for(int i=0;i<m;i++)
        {
            int u,c,v;
            printf("Transistion %d",i+1);
            scanf("%d%d%d",&u,&c,&v);
            t[u][c]|=1<<v;
        }
    printf("\ndfa transisition:\n");

    vis[1]=1;
    q[r++]=1;
    while (f<r)
        {
            int s=q[f++];
            printf("{");
            for(int i=0;i<n;i++)
                {
                    if (s&(1<<i))
                    {
                        printf("%d",i);
                    }
                }
            printf("}");
            for(int c=0;c<2;c++)
                {
                    int ns=0;
                    for(int i=0;i<n;i++)
                {
                    if (s&(1<<i))
                    {
                        ns|=t[i][c];
                    }
                }
            printf("----%d---{",c);
            for(int i=0;i<n;i++)
                {
                    if (ns&(1<<i))
                    {
                        printf("%d",i);
                    }
                }
            printf("}");

                if(!vis[ns])
                {
                    vis[ns]=1;
                    q[r++]=ns;
                }
                    
                }
            printf("\n");
        }
    
    
    
    return 0;
}3
