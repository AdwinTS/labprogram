#include <stdio.h>
#include<stdlib.h>

#define MAX 10

int episol[MAX][MAX];
int visited[MAX];
int n;
void eclosure(int state)
{
    visited[state]=1;
    printf("%d",state);
    for(int i=0;i<n;i++)
        {
            if (episol[state][i] && !visited[i])
            {
                eclosure(i);
            }
        }
}

int main()
{
    printf("enter no of states: ");
    scanf("%d",&n);
    printf("enter episolon tranisition matrix:\n");
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                {
                    scanf("%d",&episol[i][j]);
                }
        }
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                {
                    visited[j]=0;
                }

            printf("\neclosure of (%d){",i);
            eclosure(i);
            printf("}\n");
        }



   return 0; 
}
