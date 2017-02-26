#include<iostream>
#include<algorithm>

using namespace std;

int vis[201];
int d[201];
int w[201][201];

int min(int a, int b)
{
	if(a > b)
		a = b;
	return a;
}

void dij(int n)
{
	int i, j, k, v, tmp;
	memset(vis, 0, sizeof(vis));
	for(i=1; i<=n; i++)
		d[i] = w[1][i];
	d[1] = 0;
	vis[1] = 1;
	for(i=1; i<=n; i++)
	{
		tmp = 0x7ffffff;
		for(j=1; j<=n; j++)
		{
			if(tmp>d[j] && !vis[j])
			{
				tmp = d[j];
				v = j;
			}
		}
		vis[v] = 1;
		for(k=1; k<=n; k++)
		{
			if(!vis[k]) {
				d[k] = min(d[k], d[v]+w[v][k]);
			}
		}
	}
}

int main()
{
	// freopen("test.in", "r", stdin);
	int N, M;
	int i, j, k, l;
	while(scanf("%d%d", &N, &M) && !(N==0&&M==0))
	{
		for(i=1; i<=N; i++)
		{
			for(j=1; j<=N; j++)
			{
				w[i][j] = 0x7ffffff;
			}
		}
		for(i=1; i<=M; i++)
		{
			scanf("%d%d%d", &j, &k, &l);
			
			w[j][k] = l;
			w[k][j] = l;
		}
		dij(N);
		printf("%d\n", d[N]);
	}
	return 0;
}