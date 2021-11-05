#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Graph{
	int src;
	int dest;
	int weight;
	struct Graph* next;
};

int min(int a, int b)
{
	if(a<b)
		return a;
	else
		return b;
}

void AddEdge(int a, int b, int w, struct Graph* arr[])
{	
	struct Graph* T = arr[a];
	while(T->next!=NULL)
	{
		T=T->next;
	}
	struct Graph *tmp = malloc(sizeof(struct Graph));
	tmp->src = a;
	tmp->dest = b;
	tmp->weight = w;
	tmp->next=NULL;
	T->next=tmp;

}

void printAll(struct Graph* arr[], int n)
{
	for(int i=0;i<n;i++)
	{
		struct Graph *T = arr[i]->next;
		printf("%d : ",arr[i]->src);
		while(T!=NULL)
		{
			printf("%d(%d) ",T->dest,T->weight);
			T=T->next;
		}
		printf("\n");
	}
}

int BFS(struct Graph *arr[], int s, int t, int parent[], int n)
{	
	int que[n],visited[n];
	for(int i=0;i<n;i++)
	{
		que[i]=0;
		visited[i]=0;
	}
	que[0] = s;
	visited[s]=1;
	//parent[s]=-1;
	int start=0;
	int end=0;

	while(start<=end && end<n)
	{	
		printf("%d ",que[start]);
		int k =que[start];
		struct Graph * T = arr[k]->next;
		while(T!=NULL)
		{
			if(visited[T->dest]==0)
			{	
				parent[T->dest] = k;
				visited[T->dest]=1;
				que[++end] = T->dest;
				if(T->dest==t)
					return 1;
			}
			T=T->next;
		}
		start++;
	}
	return 0;

}

void Flow(struct Graph* arr[], int s, int t, int n, int e)
{
	
	int parent[n];
	int maxflow = 0;
	int f[n][n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			f[i][j]=0;
			f[j][i]=0;
		}

	struct Graph* temp;
	for(int i=0;i<n;i++){
		temp=arr[i]->next;
		while(temp!=NULL){
			f[temp->src][temp->dest]=temp->weight;
			temp=temp->next;
		}
	}
	while(BFS(arr, s, t, parent, n))
	{	
		int path_flow = INT_MAX;
		for(int i=t;i!=s;i=parent[i])
		{
			int x = parent[i];
			path_flow = min(path_flow, f[x][i]);
		}

		for(int i=t;i!=s;i=parent[i])
		{
			int x = parent[i];
			f[x][i]-=path_flow;
			f[i][x]+=path_flow;
		}
		
		struct Graph *temp, *prev;
		for(int i=0;i<n;i++){
			temp=arr[i]->next;
			prev=arr[i];
				while (temp != NULL) 
					    {
					        while (temp != NULL && f[temp->src][temp->dest]!=0) 
					        { 
					            prev = temp; 
					            temp = temp->next; 
					        } 
					        if(temp==NULL)
					        	break;
					        prev->next = temp->next; 
					  
					        free(temp); 
					        temp = prev->next; 
					    } 
					}
		maxflow +=path_flow;
	
	}

	printf("Max Flow is: %d\n",maxflow);
}

int main()
{
	int n,e,x,y,z,ch,s,t;
	scanf("%d%d",&n,&e);
	struct Graph* arr[n];
	for(int i=0;i<n;i++)
	{
		struct Graph* tmp = (struct Graph*)malloc(sizeof(struct Graph));
		tmp->src=i;
		tmp->dest=i;
		tmp->weight = 0;
		tmp->next=NULL;
		arr[i]=tmp;
	}
	for(int i=0;i<e;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		AddEdge(x,y,z,arr);
	}
	
	while(1)
	{	
		printf("\nEnter choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printAll(arr, n);
					break;
			case 2: scanf("%d%d",&s,&t);	
					Flow(arr,s,t,n,e);
					break;
			case 3: exit(0);
		}
	}
}