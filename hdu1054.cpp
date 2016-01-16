#include<iostream>
#include<algorithm>

using namespace std;

const int MAX = 2005;
bool vis[MAX];
int linked[MAX], head[MAX];
int cnt, n;

struct Edge
{
	int to;
	int next;
};
Edge edge[MAX*MAX];

void add(int u, int v)
{
	edge[cnt].to = v;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}

bool dfs(int u)
{
	for(int i=head[u]; ~i; i=edge[i].next)
	{
		int v = edge[i].to;
		if(!vis[v])
		{
			vis[v] = 1;
			if(linked[v] == -1 || dfs(linked[v]))
			{
				linked[v] = u;
				return true;
			}
		}
	}
	return false;
}

int match()
{
	int ans = 0;
	memset(linked, -1, sizeof(linked));
	for(int i=0; i<n; i++)
	{
		memset(vis, 0, sizeof(vis));
		if(dfs(i))
			ans++;
	}
	return ans;
}

int main()
{
	// freopen("test.in", "r", stdin);
	while(scanf("%d", &n) != EOF)
	{
		cnt = 0;
		memset(head, -1, sizeof(head));
		for(int i=0; i<n; i++)
		{
			int u, v, k;
			scanf("%d:(%d)", &u, &k);
			while(k--)
			{
				scanf("%d", &v);
				add(u, v);
				add(v, u);
			}
		}
		printf("%d\n", match()>>1);
	}
	return 0;
}