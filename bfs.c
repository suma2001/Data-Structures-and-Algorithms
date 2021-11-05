#include<stdio.h>
#include<stdlib.h>

struct Graph{
	int data;
	int start;
	int end;
	int color;
	struct Graph* next;
};

void AddEdge(int a,int b,struct Graph* arr[], int n)
{
	for(int i=0;i<n;i++)
	{
		if(arr[i]->data==a)
		{
			struct Graph *tmp = (struct Graph*)malloc(sizeof(struct Graph));
			tmp->data=b;
			tmp->start=0;
			tmp->end=0;
			tmp->next=NULL;
			struct Graph* A = arr[i]->next;
			if(A==NULL)
				arr[i]->next=tmp;
			else
			{
				while(A->next!=NULL)
					A=A->next;

				A->next=tmp;
			}
		}

	if(arr[i]->data==b)
		{
			struct Graph *tmp = (struct Graph*)malloc(sizeof(struct Graph));
			tmp->data=a;
			tmp->start=0;
			tmp->end=0;
			tmp->next=NULL;
			struct Graph* A = arr[i]->next;
			if(A==NULL)
				arr[i]->next=tmp;
			else
			{
				while(A->next!=NULL)
					A=A->next;

				A->next=tmp;
			}
		}
	}
}

int DFS(int u, struct Graph* arr[], int n, int visited[], int cur_t)
{
	int ind,ind1;
	for(int i=0;i<n;i++)
	{
		if(arr[i]->data==u)
		{
			ind=i;
			break;
		}
	}
	arr[ind]->start = cur_t;
	cur_t++;

	printf("%d ",arr[ind]->data);
	visited[ind]=1;
	struct Graph* tmp = arr[ind]->next;
	while(tmp!=NULL)
	{
		for(int i=0;i<n;i++)
		{
			if(arr[i]->data==tmp->data)
			{
				ind1=i;
				break;
			}
		}
			if(visited[ind1]==0)
			{
				cur_t=DFS(tmp->data, arr, n, visited, cur_t);
				cur_t++;
			}
		tmp=tmp->next;
	}
	arr[ind]->end=cur_t;
	return cur_t;

}

void BFS(struct Graph* que[], struct Graph* arr[],int n,int visited[],int begin,int last)
{	
	int ind;
	if(begin==0 && begin==last)
	{
		printf("Level 0: ");
		printf("%d\n ",arr[begin]->data);
		arr[begin]->color=0;
		que[last++]=arr[begin];
		visited[0]=1;
	}
	struct Graph* tmp;
	if(begin<n)
	{
		printf("\nLevel %d: ",begin+1);
		tmp=que[begin]->next;
		while(tmp!=NULL)
		{
			for(int i=0;i<n;i++)
			{
				if(arr[i]->data==tmp->data)
				{
					ind=i;
					break;
				}
			}
			if(visited[ind]==0)
			{
				que[last++]=arr[ind];
				visited[ind]=1;
				printf("%d ",arr[ind]->data);

			}
			tmp=tmp->next;
		}
		begin++;
		BFS(que,arr,n,visited,begin,last);
	}
}

void printGraph(struct Graph* arr[], int n)
{
	for(int i=0;i<n;i++)
	{	
		printf("%d: ",arr[i]->data);
		struct Graph *tmp = arr[i]->next;
		while(tmp!=NULL)
		{
			printf("%d ",tmp->data);
			tmp=tmp->next;
		}
		printf("\n");
	}
}

void isBipartite(int u,struct Graph* que[],struct Graph* arr[], int visited[],int n)
{	
	int ind,ind1;
	int begin=0;
	int last=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]->data==u)
		{
			ind=i;
			break;
		}
	}
	arr[u]->color=1;
	visited[u]=1;
	que[last++]=arr[u];
	printf("##%d ",begin);
	while(begin<last)
	{	
		printf("ENter");
		struct Graph *tmp = que[begin]->next;
		printf("1. %d ",begin);
		while(tmp!=NULL)
		{
			for(int i=0;i<n;i++)
				if(arr[i]->data==tmp->data)
				{
					ind1=i;
					break;
				}
				//begin++;
			printf(" ##2. %d ",begin);
			printf("\n %d %d \n",que[begin]->color,tmp->color);
			if(visited[ind1]==0/* &&arr[ind1]->color==0&& arr[ind1]!=tmp*/)
			{	
				printf("Enqueue\n");
				//(arr[ind1]->color) = (tmp->color == 1)?2:1;
				if(que[begin]->color==1)
					arr[ind1]->color=0;
				else
					arr[ind1]->color=1;
				que[last++]=arr[ind1];
				visited[ind1]=1;
				printf("\nColor of %d is %d:   and data in tmp is %d\n",arr[ind1]->data,arr[ind1]->color,tmp->data);
			}

			else if(que[begin]->color == tmp->color)
			{	
				printf("$$$%d %d ",que[begin]->color,tmp->color);
				printf("Not Bipartite");
				return;
			}
			tmp=tmp->next;
		}
		begin++;
	}
	printf("Bipartite");
	return;
}

int main()
{
	int n;
	scanf("%d",&n);
	printf("Enter vertices: ");
	struct Graph *arr[n],*que[n];
	for(int i=0;i<n;i++)
	{
		struct Graph *node = (struct Graph*)malloc(sizeof(struct Graph));
		scanf("%d",&(node->data));
		node->next=NULL;
		arr[i]=node;
	}
	int ch,x,y;
	int visited[n];
	while(1)
	{
		printf("Enter choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: scanf("%d%d",&x,&y);
					AddEdge(x,y,arr,n);
					break;
			case 2: printGraph(arr,n);
					break;
			case 3: 
					for(int i=0;i<n;i++)
						visited[i]=0;	
					DFS(arr[0]->data,arr,n,visited,0);
					break;
			case 4: 
					for(int i=0;i<n;i++)
						visited[i]=0;
					BFS(que,arr,n,visited,0,0);
			case 5: 
					for(int i=0;i<n;i++)
						visited[i]=0;
					isBipartite(0,que,arr,visited,n);
			case 6: exit(0);
		}
	}
}