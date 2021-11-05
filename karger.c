#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct Graph{
	int src;
	int dest;
};

struct DisjointSet{
	int parent,rank;
};

struct Graph* AddEdge(int a, int b, struct Graph* arr[])
{	
	struct Graph *tmp = malloc(sizeof(struct Graph));
	tmp->src = a;
	tmp->dest = b;
	return tmp;
}

int find(int a, struct DisjointSet *belongs[])
{
	if(a!=belongs[a]->parent)
		belongs[a]->parent = find(belongs[a]->parent, belongs);
	return belongs[a]->parent;
}

void Union(int c1, int c2, struct DisjointSet *belongs[], int E)
{
	int x = find(c1, belongs);
	int y = find(c2, belongs);

	if(belongs[x]->rank > belongs[y]->rank)
		belongs[x]->parent = y;
	else if(belongs[x]->rank < belongs[y]->rank)
		belongs[y]->parent = x;
	else
	{
		belongs[y]->parent = x;
		belongs[x]->rank+=1;
	}
	//if(x!=y)
	//	belongs[x] = y;
}

void KargerAlgo(struct Graph* arr[], int n, int E)
{	
	int g=20;
	int cnt=0;
	while(g--)
	{
		struct DisjointSet *belongs[n];
	for(int i=0;i<n;i++)
	{
		struct DisjointSet *tmp = (struct DisjointSet*)malloc(sizeof(struct DisjointSet));
		tmp->parent=i;
		tmp->rank=0;
		belongs[i]=tmp;
	}

	int vert = n;
	while(vert>2)
	{
		int i = rand()%E;
		//printf("Random edge is: %d\n", i);
		int c1 = find(arr[i]->src,belongs);
		int c2 = find(arr[i]->dest,belongs);
		//printf("###### %d ### %d\n",c1,c2);
		if(c1==c2)
			continue;

		else
		{	
			//printf("Contracting Edge: %d %d \n",arr[i]->src,arr[i]->dest);
			vert--;
			Union(c1, c2, belongs, E);
		}
	}

	int minedge=0;
	for(int i=0;i<E;i++)
	{
		int c1 = find(arr[i]->src,belongs);
		int c2 = find(arr[i]->dest,belongs);
		if(c1!=c2)
			minedge++;
	}
	//printf("Cut is: %d\n",minedge);
	if(minedge==2)
		cnt++;
}
printf("@@@@@@@ %d\n", cnt);
}

void printAll(struct Graph* arr[], int E)
{
	for(int i=0;i<E;i++)
	{
		printf("Src: %d  Dest: %d  \n",arr[i]->src,arr[i]->dest);
	}
}

int main()
{
	int n,e,x,y,z,ch,s,t;
	scanf("%d%d",&n,&e);
	int E=e;
	struct Graph* arr[E];
	for(int i=0;i<n;i++)
	{
		struct Graph* tmp = (struct Graph*)malloc(sizeof(struct Graph));
		tmp->src=0;
		tmp->dest=0;
		arr[i]=tmp;
	}
	for(int i=0;i<E;i+=1)
	{
		scanf("%d%d",&x,&y);
		arr[i] = AddEdge(x,y,arr);
	}
	srand(time(NULL));
	while(1)
	{	
		printf("\nEnter choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printAll(arr, E);
					break;
			case 2: KargerAlgo(arr,n,E);
					break;
			case 3: exit(0);
		}
	}
}