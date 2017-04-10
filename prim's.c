#include <stdio.h>
#include <limits.h>
#include<stdbool.h>

void print(int n, int graph[n][n],int parent[])
{
   int i;
   printf("\nthe minimum spanning tree looks like:\n");

   for (i = 1; i < n; i++)
      printf("Edge:- %d - %d  weight:- %d \n", parent[i], i, graph[i][parent[i]]);

}




int minimum(int n,int key[], bool finalset[])
{
   int min = 1000;
   int minimum;
   int i;
   for(i=0;i<n;i++){
     if (finalset[i] == false && key[i] < min){
         minimum = i;
         min = key[i];
   }
   }
   return minimum;
}



void primalgo(int n,int graph[n][n])
{
     int i;
     int j;

     int key[n];
     bool finalset[n];
     int parent[n];

     for (i = 0; i < n; i++)
     {
        key[i] = 1000;
        finalset[i] = false;
     }
     key[0] = 0;
     parent[0] = -1;

     for (i = 0; i < n-1; i++)
     {
        int u = minimum(n,key, finalset);
        finalset[u] = true;
        for (j = 0; j < n; j++)
            {
                if (graph[u][j] && finalset[j] == false && graph[u][j] <  key[j])
            {
                parent[j]  = u;
                key[j] = graph[u][j];
            }
            }

     }
     print(n,graph,parent);
}



void main()
{
int v;
int i;
int j;
printf("\nenter the number of vertices:");
scanf("%d",&v);
int graph[v][v];
printf("\nenter the adjacency matrix for the graph:");
printf("\n");
for(i=0;i<v;i++)
    for(j=0;j<v;j++)
    scanf("%d",&graph[i][j]);

primalgo(v,graph);
}
