#include<stdio.h>
#include<limits.h>
#define MAX 20
#define INF 999
int dist[MAX];
int visited[MAX];
int path[MAX];
int source;
void dijkstra(int n,int graph[MAX][MAX]);
int mindistance(int n);
void printshortest(int n);
void printpath(int path[],int j);
int main(){
int i,j,n;
int graph[MAX][MAX];
printf("enter the no. of nodes:");
scanf("%d",&n);
printf("enter the weight matrix:\n");
for(i=1;i<=n;i++){
for(j=1;j<=n;j++){
scanf("%d",&graph[i][j]);
}
}
printf("enter the source vertex:");
scanf("%d",&source);
dijkstra(n,graph);
printshortest(n);
return 0;
}
void dijkstra(int n,int graph[MAX][MAX]){
int i,u,v;
for(i=1;i<=n;i++){
visited[i]=0;
}
visited[source]=1;
for(i=1;i<=n;i++){
dist[i]=graph[source][i];
}
for(i=1;i<=n;i++){
path[i]=source;
}
path[source]=-1;
for(i=1;i<=n;i++){
u=mindistance(n);
visited[u]=1;
for(v=1;v<=n;v++){
if(!visited[v] && graph[u][v] && dist[u]!=INF && dist[u]+graph[u][v]<dist[v]){
dist[v]=dist[u]+graph[u][v];
path[v]=u;
}
}
}
}
int mindistance(int n){
int min=INF,minindex=-1,i;
for(i=1;i<=n;i++){
if(visited[i]==0&&dist[i]<=min){
min=dist[i];
minindex=i;
}
}
return minindex;
}
void printshortest(int n){
int i;
for(i=1;i<=n;i++){
if(i!=source){
printf("the shortest distance from node %d to %d=%d\n",source,i,dist[i]);
printf("the shortest path from node %d to %d is:",source,i);
printf("%d",source);
printpath(path,i);
printf("\n");
}
}
}
void printpath(int path[],int j){
if(path[j]==-1){
return;
}
printpath(path,path[j]);
printf("--->%d",j);
}
