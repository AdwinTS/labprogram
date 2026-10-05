#include <stdio.h>
#include<stdlib.h>

#define MAX 20

int episol[MAX][MAX];
int trans0[MAX][MAX],trans1[MAX][MAX];
int result0[MAX][MAX],result1[MAX][MAX];
int final[MAX];
int n;

int main()
{
    int n;
    printf("enter no of states:");
    scanf("%d",&n);

    printf("enter episolon transistion matrix:\n");

    for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                {
                    scanf("%d",&episol[i][j]);
                }
        }

    printf("enter transistion matrix for input 0:\n");

    for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                {
                    scanf("%d",&trans0[i][j]);
                }
        }

    printf("enter transistion matrix for input 1:\n");

    for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                {
                    scanf("%d",&trans1[i][j]);
                }
        }

    printf("enter final states(0 or 1):\n");
    for(int i=0;i<n;i++)
        {
            scanf("%d",&final[i]);
        }

    for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                {
                    if (episol[i][j])
                    {
                        for(int k=0;k<n;k++)
                            {
                                if (trans0[j][k])
                                {
                                    result0[i][k]=1;
                                }
                                if (trans1[j][k])
                                {
                                    result1[i][k]=1;
                                }
                            }
                    }
                }
        }

    printf("\n nfa transistion table:--\n");
    printf("\n input 0 \n");

    for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                {
                    printf("%d ",result0[i][j]);
                }
            printf("\n");
        }

    printf("\n input 1 \n");

    for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                {
                    printf("%d ",result1[i][j]);
                }
            printf("\n");
        }

    return 0;
}
