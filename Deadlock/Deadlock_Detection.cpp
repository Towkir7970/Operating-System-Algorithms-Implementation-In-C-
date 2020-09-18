#include<bits/stdc++.h>
using namespace std;

vector<int> graph[100];
int color[100], cycle[100], ara[100];
int nodes, edges, top=-1, track;

void print()
{
    int j=0, i;
    while(cycle[top]!=track){
        ara[j]=cycle[top];
        color[cycle[top]]=-1;
        top--;
        j++;
    }
    ara[j]=cycle[top];

    for(i=j; i>0; i--)
        printf("%d-->", ara[i]);
    printf("%d\n", ara[i]);
}

void dfs(int node)
{
    if(color[node]==0){
        color[node]=1;
        cycle[++top]=node;

        for(int i=0; i<graph[node].size(); i++){
            if(color[graph[node][i]]==0 || color[graph[node][i]]==1){
                dfs(graph[node][i]);
            }
        }
        color[node]=-1;
        top--;
    }
    else if(color[node]==1){
        track=node;
        print();
    }
}

int main()
{
   int node1, node2;

   printf("Number of nodes: ");
   scanf("%d", &nodes);

   printf("Number of Edges:: ");
   scanf("%d", &edges);

   printf("Edges:: \n");
   for(int i=1; i<=edges; i++){
       scanf("%d %d", &node1, &node2);
       graph[node1].push_back(node2);
   }

   printf("Cycle::\n");
   for(int i=1; i<=nodes; i++){
        if(color[i]==0)
           dfs(i);
   }
}
