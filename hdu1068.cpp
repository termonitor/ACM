#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

#define maxn 510

/*
	hdu1068匈牙利算法
	思考过程：
	1、对没有好感的点之间连一条边。最后求最大团。
	2、对有好感度的点之间连一条无向边。最后求最大独立集。	
	最大团是NP问题。
	这道题目因为特殊性：一条边连接的是一男一女，所以必然能用红蓝着色，分成两个集合，所以这也暗示了这个图是一个二分图
	这样我们用2中的思路来看，对于一条边连接的两个点，必然不能划分到一个集合中去。
	也就像在红蓝染色过程中，我们只能选择（尽可能）被染成同一种颜色的点。
	所以就是个求二分图最大独立点集（最大匹配）的问题。
	使用匈牙利算法，复杂度为O(MN)。
	important：最大独立点集=最小覆盖路径= 顶点数 - 最大二分匹配/2
*/

vector<int> G[maxn];
int match[maxn];
bool vis[maxn];
int n;

bool dfs(int s)
{
	for(int i=0; i<G[s].size(); i++)
	{
		int v=G[s][i];
		if(!vis[v])
		{
			vis[v] = true;
			if(match[v]==0 || dfs(match[v]))
			{
				match[v] = s;
				return true;
			}
		}
	}
	return false;
}

int hungary()
{
	int ans = 0;
	memset(match, 0, sizeof(match));
	for(int i=1; i<=n; i++)
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
	while(scanf("%d", &n)!=EOF)
	{
		for(int i=1; i<=n; i++)
			G[i].clear();
		for(int i=1; i<=n; i++)
		{
			int a, k, b;
			scanf("%d: (%d)", &a, &k);
			a++;
			for(int j=0; j<k; j++)
			{
				scanf("%d", &b);
				b++;
				G[a].push_back(b);
			}
		}
		printf("%d\n", n-hungary()/2);
	}
	return 0;
}