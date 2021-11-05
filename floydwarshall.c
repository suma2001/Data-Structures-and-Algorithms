#include<stdio.h>
#include<limits.h>
#define INF 100000
int main()
{
	int n,e;
	scanf("%d",&n);
	printf("Enter edges: ");
	scanf("%d",&e);
	int x,y,w;

	int G[n][n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(i==j)
				G[i][j]=0;
			else
				G[i][j]=INF;
	for(int i=0;i<e;i++)
	{
		scanf("%d%d%d",&x,&y,&w);
		G[x][y]=w;
	}

	int D[n][n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			D[i][j] = G[i][j];

	for(int k=0;k<n;k++)
	{
		for(int u=0;u<n;u++)
		{
			for(int v=0;v<n;v++)
			{
				if(D[u][k] + D[k][v] < D[u][v])
					D[u][v] = D[u][k]+D[k][v];
			}
		}
	}

	printf("Result is: \n\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(D[i][j]==INF)
				printf("INF");
			else
				printf("%d  ", D[i][j]);
		}
		printf("\n");
	}
}
