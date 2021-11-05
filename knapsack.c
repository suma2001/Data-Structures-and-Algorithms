#include<stdio.h>
#define max(a,b) (a>b)?a:b
int unboundedKnapsack(int W, int n, int wt[], int val[]) 
{ 
    int K[n+1][W+1];
  
    for (int i = 0; i <= n; i++) 
   { 
       for (int j = 0; j <= W; j++) 
       { 
           if (i==0 || j==0) 
               K[i][j] = 0; 
           else if (wt[i-1] <= j) 
                 K[i][j] = max(val[i-1] + K[i-1][j-wt[i-1]],  K[i-1][j]); 
           else
                 K[i][j] = K[i-1][j]; 
       } 
   } 
   return K[n][W];
} 
int main()
{
  	int W,n;
  	scanf("%d%d",&W,&n);
  	int val[n],wt[n];
    for(int i=0;i<n;i++)
    	scanf("%d",&val[i]);
    for(int j=0;j<n;j++)
    	scanf("%d",&wt[j]);

    printf("%d ", unboundedKnapsack(W,n,wt,val));
}