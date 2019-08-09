#include <stdio.h>
#include <malloc.h>

typedef struct Node {
	int node;
	Node *pNext;
}NodeType;

void solution(int v, int e);
NodeType * addNode(int n2);
void dfs(NodeType* adjList[], int visited[], int n);


int main(void)
{
	freopen("Text.txt", "r", stdin);

	int V, E;
	scanf("%d %d", &V, &E);
	solution(V, E);

}

void solution(int v, int e)
{
	NodeType **adjList = (NodeType**)(malloc(sizeof(NodeType*)*(v + 1)));
	int * visited = (int*)malloc(sizeof(int)*(v + 1));
	for (int i = 0; i <= v; i++)
	{
		adjList[i] = NULL;
		visited[i] = 0;
	}

	for (int i = 0; i < e; i++)
	{
		int n1, n2;
		scanf("%d %d", &n1, &n2);
		NodeType * p = adjList[n1];
		if (p == NULL)
			adjList[n1] = addNode(n2);
		else
		{
			while (p->pNext != NULL)
			{
				p = p->pNext;
			}
			p->pNext = addNode(n2);
		}
	}
	dfs(adjList, visited, 1);

}

NodeType * addNode(int n2)
{
	NodeType * p = (NodeType*)malloc(sizeof(NodeType));
	p->node = n2;
	p->pNext = NULL;
	return p;
}

void dfs(NodeType* adjList[], int visited[], int n)
{
	visited[n] = 1;
	printf("%d ", n);
	NodeType *p = adjList[n];
	while (p != NULL)
	{
		if (visited[p->node] == 0)
		{
			dfs(adjList, visited, p->node);
		}
		p = p->pNext;
	}
}
