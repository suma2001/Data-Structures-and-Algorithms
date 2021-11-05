#include<stdio.h>
#define max(a,b) (a>b)?a:b
int unboundedKnapsack(int W, int n, int wt[], int val[]) 
{ 
    int dp[W+1]; 
    for(int i=0;i<W+1;i++)
    	dp[i]=0;
  
    int ans = 0; 
    for (int i=0; i<=W; i++) 
      for (int j=0; j<n; j++) 
         if (wt[j] <= i) 
            dp[i] = max(dp[i], dp[i-wt[j]]+val[j]); 
  
    return dp[W]; 
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