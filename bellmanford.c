#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

struct Edge{
    int start,end,weight;
};

struct Edge *AddEdge(int a, int b, int w)
{
    struct Edge *tmp = (struct Edge*)malloc(sizeof(struct Edge));
    tmp->start=a;
    tmp->end=b;
    tmp->weight=w;
    return tmp;
}

void BellMan_Ford(struct Edge *arr[], int n, int e)
{
    int dist[n];
    for(int i=0;i<n;i++)
        dist[i]=INT_MAX;
    dist[0]=0;
    int parent[n];
    for(int i=0;i<n;i++)
        parent[i]=-1;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<e;j++)
        {
            int u = arr[j]->start;
            int v = arr[j]->end;
            int w = arr[j]->weight;

            if(dist[u]!=INT_MAX && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
        //printf("%d ",dist[i]);
    }
    for(int j=0;j<e;j++)
        {
            int u = arr[j]->start;
            int v = arr[j]->end;
            int w = arr[j]->weight;

            if(dist[u]!=INT_MAX && dist[u] + w < dist[v])
            {
                printf("Neg Cycle detected!!");
            }
        }

    for(int i=0;i<n;i++)
    {
        printf("The distance from source is %d.\n", dist[i]);
    }
}

void printGraph(struct Edge* arr[], int n)
{   
    int cost=0;
    for(int i=0;i<n;i++)
    {
        printf("%d %d %d\n",arr[i]->start,arr[i]->end,arr[i]->weight);
        cost+=arr[i]->weight;
    }
    printf("Total cost is: %d\n",cost);
}

int main()
{
    int n,e,k=0;
    scanf("%d%d",&n,&e);
    struct Edge *arr[e];
    
    for(int i=0;i<e;i++)
    {
        struct Edge *node = (struct Edge*)malloc(sizeof(struct Edge));
        node->start=0;
        node->end=0;
        node->weight=0;
        arr[i]=node;
    }
    int ch,x,y,w;
    while(1)
    {   
        printf("Enter choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: scanf("%d%d%d",&x,&y,&w);
                    struct Edge *T = AddEdge(x,y,w);
                    arr[k]=T;
                    k++;
                    break;
            case 2: printGraph(arr,e);
                    break;
            case 3: BellMan_Ford(arr, n, e);
                    break;
            case 4:exit(0);
        }
    }
}
