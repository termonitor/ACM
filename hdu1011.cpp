#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

const int maxn = 110;
int n, m;

vector<int> son[maxn];
int bug[maxn], cost[maxn];
int dp[maxn][maxn];
bool vis[maxn];

void dfs(int p)
{
	int temp = (bug[p]+19)/20;
	for(int i=temp; i<=m; i++)
		dp[p][i] = cost[p];
	vis[p] = true;
	for(int i=0; i<son[p].size(); i++)
	{
		int t = son[p][i];
		if(vis[t])
			continue;
		dfs(t);
		for(int j=m; j>=temp; j--)
		{
			for(int k=1; k<=j-temp; k++)
			{
				dp[p][j] = max(dp[p][j], dp[p][j-k]+dp[t][k]);
			}
		}
	}
}

int main()
{
	// freopen("test.in", "r", stdin);
	while(scanf("%d%d", &n, &m) != EOF)
	{
		if(n==-1 && m==-1)
			break;
		for(int i=0; i<=n; i++)
			son[i].clear();
		memset(vis, false, sizeof(vis));
		memset(bug, 0, sizeof(bug));
		memset(cost, 0, sizeof(cost));
		memset(dp, 0, sizeof(dp));
		for(int i=1; i<=n; i++)
		{
			scanf("%d%d", bug+i, cost+i);
		}
		for(int i=1; i<n; i++)
		{
			int v, u;
			scanf("%d%d", &v, &u);
			son[v].push_back(u);
			son[u].push_back(v);
		}
		if(m==0)
		{
			printf("0\n");
			continue;
		}
		dfs(1);
		printf("%d\n", dp[1][m]);
	}
	return 0;
}