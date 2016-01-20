#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

#define INF 0x3f3f3f

//prime

int n;
int visit[110];
double map[110][110], low[110], x[110], y[110];

void prime()
{
	int i, j, next;
	double min, mincost = 0;
	for(i=1; i<=n; i++)
	{
		visit[i] = 0;
		low[i] = map[1][i];
	}
	visit[1] = 1;
	for(i=2; i<=n; i++)
	{
		min = INF;
		next = 1;
		for(j=1; j<=n; j++)
		{
			if(!visit[j]&&min>low[j])
			{
				min = low[j];
				next = j;
			}
		}
		if(min == INF)
		{
			printf("oh!\n");
			return;
		}
		visit[next] = 1;
		mincost += min;
		for(j=1; j<=n; j++)
		{
			if(!visit[j]&&map[next][j]<low[j])
			{
				low[j] = map[next][j];
			}
		}
	}
	printf("%.1lf\n", mincost*100);
}

int main()
{
	// freopen("test.in", "r", stdin);
	int t, i, j;
	double d;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(i=1; i<=n; i++)
		{
			scanf("%lf%lf", &x[i], &y[i]);
			for(j=1; j<=n; j++)
			{
				if(i == j)
					map[i][j] = 0;
				else
					map[i][j] = INF;
			}
		}
		for(i=1; i<=n; i++)
		{
			for(j=i+1; j<=n; j++)
			{
				d = sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
				if(d>=10 && d<=1000)
				{
					if(map[i][j] > d)
						map[i][j] = map[j][i] = d;
				}
			}
		}
		prime();
	}
	return 0;
}