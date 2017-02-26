#include<iostream>
#include<algorithm>

using namespace std;

int h[200];
struct p{
	int x, y, z;
}node[200];

bool cmp(p a, p b)
{
	if(a.x == b.x)
		return a.y < b.y;
	else
		return a.x < b.x;
}
//DP问题
int main()
{
	int n, t;
	int max;
	int x, y, z;
	int i, j, m;
	t = 1;
	while(scanf("%d", &n)!=EOF && n)
	{
		memset(h, 0, sizeof(h));
		memset(node, 0, sizeof(node));
		m = 1;
		max = 0;
		for(i=1; i<=n; i++)
		{
			scanf("%d %d %d", &x, &y, &z);
			node[m].x = x, node[m].y = y, node[m].z = z;
			m++;
			node[m].x = y, node[m].y = x, node[m].z = z;
			m++;
			node[m].x = x, node[m].y = z, node[m].z = y;
			m++;
			node[m].x = z, node[m].y = x, node[m].z = y;
			m++;
			node[m].x = y, node[m].y = z, node[m].z = x;
			m++;
			node[m].x = z, node[m].y = y, node[m].z = x;
			m++;
		}
		m -= 1;
		sort(node+1, node+1+m, cmp);
		for(i=1; i<=m; i++)
			h[i] = node[i].z;
		for(i=1; i<=m; i++)
		{
			for(j=1; j<i; j++)
			{
				if(node[j].x<node[i].x && node[j].y<node[i].y && h[i]<h[j]+node[i].z)
				{
					h[i] = h[j] + node[i].z;
					if(h[i] > max)
						max = h[i];
				}
			}
		}
		printf("Case %d: maximum height = %d\n", t, max);
		t++;
	}
	return 0;
}