/* Dynamic Programming C implementation of LCS problem */
#include<stdio.h>
#include<string.h>
#define max(a,b) (a>b)?a:b

int LCS( char *X, char *Y, int m, int n ) 
{ 
	int C[m+1][n+1]; 

	for (int i=0; i<=m; i++) 
	{ 
		for (int j=0; j<=n; j++) 
		{ 
			if (i == 0 || j == 0) 
				C[i][j] = 0; 

			else if (X[i-1] == Y[j-1]) 
				C[i][j] = C[i-1][j-1] + 1; 

			else
				C[i][j] = max(C[i-1][j], C[i][j-1]); 
		} 
	} 
	return C[m][n]; 
} 

int main() 
{ 
	char X[100]; 
	char Y[100]; 
	scanf("%s",X);
	scanf("%s",Y);
	int m = strlen(X); 
	int n = strlen(Y); 

	printf("Ans is %d",LCS(X,Y,m,n ));  
} 
