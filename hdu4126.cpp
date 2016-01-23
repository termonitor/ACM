#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;
#define maxn 3030
#define INF 1000000000

vector<int> edge[maxn];
int map[maxn][maxn];
int lowcost[maxn];
int nearvex[maxn];
int n, m, q;
long long sumweight;
int dp[maxn][maxn];//树A中的i点到树B中的点j的最近距离
int mindist[maxn][maxn];//保存最佳替换边
bool mark[maxn];

void prime(int u0)
{
	memset(mark, false, (n+2)*sizeof(int));
	for(int i=1; i<n; i++)
	{
		lowcost[i] = map[u0][i];
		nearvex[i] = u0;
	}
	mark[u0] = true;
	lowcost[u0] = INF;
	nearvex[u0] = -1;
	sumweight = 0;
	for(int i=0; i<n-1; i++)
	{
		int min = INF;
		int v = -1;
		for(int j=1; j<n; j++)
		{
			if(!mark[j] && lowcost[j]<min)
			{
				v = j;
				min = lowcost[j];
			}
		}
		// min or lowcost[v]
		sumweight += lowcost[v];
		mark[v] = true;
		if(v != -1)
		{
			edge[v].push_back(nearvex[v]);
			edge[nearvex[v]].push_back(v);
			for(int j=1; j<n; j++)
			{
				if(!mark[j] && map[v][j]<lowcost[j])
				{
					lowcost[j] = map[v][j];
					nearvex[j] = v;
				}
			}
		}
	}
}

int dfs1(int u, int father, int rt)
{
	for(int i=0; i<edge[u].size(); i++)
	{
		int v = edge[u][i];
		if(v == father) continue;
		dp[rt][u] = min(dp[rt][u], dfs1(v, u, rt));
	}
	if(father != rt)
		dp[rt][u] = min(dp[rt][u], map[rt][u]);
	return dp[rt][u];
}

int dfs2(int u, int father, int rt)
{
	int ans = dp[u][rt];
	for(int i=0; i<edge[u].size(); i++)
	{
		int v = edge[u][i];
		if(v == father) continue;
		ans = min(ans, dfs2(v, u, rt));
	}
	return ans;
}

void solve()
{
	int u, v, w;
	scanf("%d", &q);
	double ans = 0;
	for(int i=1; i<=q; i++)
	{
		scanf("%d%d%d", &u, &v, &w);
		if(nearvex[u]!=v && nearvex[v]!=u)
		{
			ans += sumweight*1.0;
		} else {
			ans += sumweight*1.0 - map[u][v] + min(mindist[u][v], w);
		}
	}
	printf("%.4lf\n", ans/q);
}

int main()
{
	// freopen("test.in", "r", stdin);
	int u, v, w;
	while(scanf("%d%d", &n, &m) != EOF)
	{
		if(n+m == 0)
			break;
		for(int i=0; i<n; i++)
			edge[i].clear();
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				map[i][j] = dp[i][j] = INF;
		for(int i=0; i<m; i++)
		{
			scanf("%d%d%d", &u, &v, &w);
			map[u][v] = map[v][u] = w;
		}
		prime(0);
		for(int i=0; i<n; i++)
			dfs1(i, -1, i);
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<edge[i].size(); j++)
			{
				int v = edge[i][j];
				mindist[i][v] = mindist[v][i] = dfs2(v, i, i);
			}
		}
		solve();
	}
	return 0;
}