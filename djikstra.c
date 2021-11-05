#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Graph{
	int src;
	int dest;
	int weight;
	struct Graph* next;
};

void AddEdge(struct Graph* arr[],int a, int b, int w)
{
	struct Graph* tmp = malloc(sizeof(struct Graph));
	tmp->src=a;
	tmp->dest=b;
	tmp->weight=w;
	tmp->next=NULL;
	struct Graph* T = arr[a];
	if(T->next==NULL)
		arr[a]->next = tmp;
	else
	{
		while(T->next!=NULL)
			T=T->next;
		T->next=tmp;
	}

	struct Graph* tmp1 = malloc(sizeof(struct Graph));
	tmp1->src=b;
	tmp1->dest=a;
	tmp1->weight=w;
	tmp1->next=NULL;
	struct Graph* P = arr[b];
	if(P->next==NULL)
		arr[b]->next = tmp1;
	else
	{
		while(P->next!=NULL)
			P=P->next;
		P->next=tmp1;
	}

}

void printGraph(struct Graph* arr[], int n)
{
	for(int i=0;i<n;i++)
	{
		struct Graph* tmp = arr[i]->next;
		printf("%d : ",arr[i]->src);
		while(tmp!=NULL)
		{
			printf("%d ",tmp->dest);
			tmp=tmp->next;
		}
		printf("\n");
	}
}

int mindistance(int dist[], int visited[], int n)
{
	int min=INT_MAX;
	int ind;

	for(int i=0;i<n;i++)
		if(visited[i]==0 && dist[i]<=min)
		{
			min=dist[i];
			ind=i;
		}
	return ind;
}

void printDistance(int dist[], int n)
{
	for(int i=0;i<n;i++)
		printf("%d %d\n",i,dist[i]);
}

void Dijkstra(struct Graph* arr[], int s, int n)
{
	int dist[n];
	int visited[n];

	for(int i=0;i<n;i++)
	{
		dist[i]=INT_MAX;
		visited[i]=0;
	}
	dist[s]=0;

	for(int i=0;i<n-1;i++)
	{
		int u = mindistance(dist, visited, n);
		visited[u]=1;

		struct Graph *tmp = arr[u]->next;
		while(tmp!=NULL)
		{
			if(visited[tmp->dest]==0 && dist[u]!=INT_MAX && dist[u] + tmp->weight < dist[tmp->dest])
				dist[tmp->dest] = dist[u] + tmp->weight;
			tmp=tmp->next;
		}
	}

	printDistance(dist,n);

}

int minkey(int key[], int visited[], int n)
{
	int min=INT_MAX;
	int ind;

	for(int i=0;i<n;i++)
		if(visited[i]==0 && key[i]<min)
		{
			min=key[i];
			ind=i;
		}
	return ind;
}

void printPrims(struct Graph* arr[], int parent[], int n)
{
	for(int i=1;i<n;i++)
	{
		int x=parent[i];
		struct Graph* tmp=arr[x]->next;
		while(tmp!=NULL)
		{
			if(tmp->dest==i)
			{
				printf("%d-%d : %d\n",x,i,tmp->weight);
				break;
			}
			tmp=tmp->next;
		}
	}
}

void prims(struct Graph* arr[], int n)
{
	int parent[n], key[n], visited[n];
	for(int i=0;i<n;i++)
	{
		key[i]=INT_MAX;
		visited[i]=0;
	}
	key[0]=0;
	parent[0]=-1;
	for(int i=0;i<n-1;i++)
	{
		int u=minkey(key,visited,n);
		visited[u]=1;

		struct Graph *tmp = arr[u]->next;
		while(tmp!=NULL)
		{
			if(visited[tmp->dest]==0 && tmp->weight < key[tmp->dest])
			{
				parent[tmp->dest]=u;
				key[tmp->dest]=tmp->weight;
			}
			tmp=tmp->next;
		}
	}
	printPrims(arr, parent, n);
}
int main()
{
	int n;
	scanf("%d",&n);
	struct Graph* arr[n];
	for(int i=0;i<n;i++)
	{
		struct Graph* tmp = malloc(sizeof(struct Graph));
		tmp->src=i;
		tmp->dest=i;
		tmp->weight=0;
		tmp->next=NULL;
		arr[i]=tmp;
	}
	int ch,x,y,w;
	while(1)
	{	
		printf("Enter choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: scanf("%d%d%d",&x,&y,&w);
					AddEdge(arr,x,y,w);
					break;
			case 2: printGraph(arr,n);
					Dijkstra(arr,0,n);
					break;
			case 3: prims(arr,n);
					break;
			case 4: exit(0);
		}
	}
}