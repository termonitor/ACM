#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

#define N 1010
#define INF 100000000

struct point
{
	int x, y, v;
}p[N];
double a[N][N], maxx[N][N], dis[N];
int n, pre[N];
bool vis[N];

void prime()
{
	double ans = 0;
	memset(vis, false, sizeof(vis));
	memset(maxx, 0, sizeof(maxx));
	for(int i=1; i<=n; i++)
	{
		dis[i] = a[1][i];
		pre[i] = 1;
	}
	dis[1] = 0;
	vis[1] = true;
	for(int i=1; i<n; i++)
	{
		int k = 0;
		double tmp = INF;
		for(int j=1; j<=n; j++)
		{
			if(!vis[j] && dis[j]<tmp)
			{
				k = j;
				tmp = dis[j];
			}
		}
		vis[k] = true;
		ans += tmp;
		for(int j=1; j<=n; j++)
		{
			if(!vis[j] && dis[j]>a[k][j])
			{
				dis[j] = a[k][j];
				pre[j] = k;
			}
		}
		for(int j=1; j<=n; j++)
		{
			if(vis[j] && j!=k)
			{
				maxx[j][k] = max(maxx[j][pre[k]], tmp);
				maxx[k][j] = maxx[j][k];
			}
		}
	}
	double an = 0;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(i != j)
			{
				an = max(an, double(p[i].v+p[j].v)/(ans-maxx[i][j]));
			}
		}
	}
	printf("%.2f\n", an);
}

int main()
{
	// freopen("test.in", "r", stdin);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(int i=1; i<=n; i++)
			scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].v);
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
			{
				a[i][j] = sqrt(1.0*(p[i].x-p[j].x)*(p[i].x-p[j].x)+1.0*(p[i].y-p[j].y)*(p[i].y-p[j].y));
			}
		}
		prime();
	}
	return 0;
}