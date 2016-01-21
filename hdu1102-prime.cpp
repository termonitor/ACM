#include<iostream>
#include<algorithm>

using namespace std;

#define INF 0x3f3f3f

const int maxn = 205;
int map[maxn][maxn];
int visit[maxn];
int low[maxn];
int n, q;
int mincost;

void prime()
{
	int next, min;
	for(int i=1; i<=n; i++)
	{
		visit[i] = 0;
		low[i] = map[1][i];
	}
	visit[1] = 1;
	for(int i=2; i<=n; i++)
	{
		min = INF;
		next = 1;
		for(int j=1; j<=n; j++)
		{
			if(!visit[j]&&min>low[j])
			{
				min = low[j];
				next = j;
			}
		}
		visit[next] = 1;
		mincost += min;
		for(int j=1; j<=n; j++)
		{
			if(!visit[j]&&map[next][j]<low[j])
			{
				low[j] = map[next][j];
			}
		}
	}
	printf("%d\n", mincost);
}

int main()
{
	// freopen("test.in", "r", stdin);
	while(scanf("%d", &n) != EOF)
	{
		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));
		mincost = 0;
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}

		scanf("%d", &q);
		int x, y;
		for(int i=0; i<q; i++)
		{
			scanf("%d%d", &x, &y);
			map[x][y] = map[y][x] = 0;
		}
		prime();
	}	
	return 0;
}