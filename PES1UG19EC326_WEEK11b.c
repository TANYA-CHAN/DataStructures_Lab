#include<stdio.h>
#include "bfs.h"

int check_path(int **graph, int n, int v, int u)
{
	//TODO
	int a[n], b=0,c=-1;
	int visited[100]={0};
	a[++c]=v;
	visited[v]=1;
	while(b<=c)
	{
	int x=a[b++];
	if(x==u) return 1;
	for(int i=0;i<n;i++){
		if(graph[x][i] && !visited[i])
		{
		a[++c]=i;
		visited[i]=1;	
			}	
		}
	}
	return 0;
}