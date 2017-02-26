#include<iostream>
#include<algorithm>

using namespace std;

struct node
{
	int u, v, w;
} edge[12101];
int N, Q;
int parent[110];

bool cmp(node a, node b)
{
	return a.w <= b.w;
}

int find(int a)
{
	return parent[a]==a ? a:parent[a] = find(parent[a]);
}

int kruskal(int m)
{
	int ans = 0;
	int i, j, x, y;
	sort(edge, edge+m, cmp);
	for(i=0; i<m; i++)
	{
		x = edge[i].u;
		y = edge[i].v;
		x = find(x);
		y = find(y);
		if(x != y)
		{
			parent[x] = y;
			ans += edge[i].w;
		}
	}
	return ans;
}

int main()
{
	// freopen("test.in", "r", stdin);
	while(scanf("%d", &N) != EOF)
	{
		memset(edge, 0, sizeof(edge));
		int k = 0;
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<N; j++)
			{
				int q;
				scanf("%d", &q);
				if(i>=j) continue;
				edge[k].u = i;
				edge[k].v = j;
				edge[k].w = q;
				k++;
			}
		}
		for(int i=0; i<N; i++)
			parent[i] = i;
		scanf("%d", &Q);
		for(int i=0; i<Q; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			x--;
			y--;
			x = find(x);
			y = find(y);
			parent[x] = y;
		}
		printf("%d\n", kruskal(k));
	}	
	return 0;
}