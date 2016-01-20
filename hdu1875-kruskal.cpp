#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

//kruskal

const int maxn = 10010;
double x[110], y[110];
int set[110];

struct line
{
	int start;
	int end;
	double dis;
}num[maxn];

bool cmp(line a, line b)
{
	return a.dis<b.dis;
}

int find(int p)
{
	int child = p;
	int t;
	while(p != set[p])
		p = set[p];
	while(child != p)
	{
		t = set[child];
		set[child] = p;
		child = t;
	}
	return p;
}

void merge(int x, int y)
{
	int fx = find(x);
	int fy = find(y);
	if(fx != fy)
		set[fx] = fy;
}

int main()
{
	// freopen("test.in", "r", stdin);
	int t, n, i, j, k, exist;
	double need, d;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(i=1; i<=n; i++)
		{
			set[i] = i;
			scanf("%lf%lf", &x[i], &y[i]);
		}
		k = 0;
		for(i=1; i<=n; i++)
		{
			for(j=i+1; j<=n; j++)
			{
				d = sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
				if(d>=10 && d<=1000)
				{
					num[k].start = i;
					num[k].end = j;
					num[k].dis = d;
					k++;
				}
			}
		}
		sort(num, num+k, cmp);
		need = 0;
		for(i=0; i<k; i++)
		{
			if(find(num[i].start) != find(num[i].end))
			{
				merge(num[i].start, num[i].end);
				need += num[i].dis;
			}
		}
		exist = 0;
		for(i=1; i<=n; i++)
		{
			if(set[i] == i)
				exist++;
			if(exist > 1)
				break;
		}
		if(exist > 1)
			exist++;
		else
			printf("%.1lf\n", need*100);
	}
	return 0;
}