#include<stdio.h>
int main()
{
    int n,a[20][2],mark[20][20]={0},f[20];
    printf("enter no of states:");
    scanf("%d",&n);
    printf("enter transistion table (for input 0 and 1):\n");
    for(int i=0;i<n;i++)
        {
            printf("for state %d: ",i);
            scanf("%d%d",&a[i][0],&a[i][1]);
        }
    printf("enter final states 0 for nonfinal 1 for final:");
    for(int i=0;i<n;i++)
        {
            scanf("%d",&f[i]);
        }
    for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
                {
                    if (f[i]!=f[j])
                    {
                        mark[i][j]=1;
                    }
                }
        }
    int change;
    do
        {
            change=0;
            for(int i=0;i<n;i++)
                {
                    for(int j=i+1;j<n;j++)
                        {
                            if(!mark[i][j])
                            {
                                for(int k=0;k<2;k++)
                                    {
                                        int x=a[i][k];
                                        int y=a[j][k];
                                        if(x>y)
                                        {
                                            int t=x;
                                            x=y;
                                            y=t;
                                        }
                                        if(mark[x][y])
                                        {
                                            mark[i][j]=1;
                                            break;
                                        }
                                    }
                            }
                        }
                }
        }while(change);
        printf("\nEquivalent states:\n");
        for(int i=0;i<n;i++)
            {
                for(int j=i+1;j<n;j++)
                    {
                        if(!mark[i][j])
                        {
                            printf("%d and %d may be equivalent\n",i,j);
                        }
                    }
            }

    return 0;
}
