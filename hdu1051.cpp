#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

struct node
{
	int l;
	int w;
}thing[5005];

int cmp(node a, node b)
{
	if(a.l == b.l)
		return a.w < b.w;
	return a.l < b.l;
}

int main()
{
	// freopen("test.in", "r", stdin);
	int t;
	int n, l, w;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(int i=0; i<n; i++)
		{
			scanf("%d%d", &thing[i].l, &thing[i].w);
		}
		sort(thing, thing+n, cmp);
		int count = 0;
		for(int i=0; i<n; i++)
		{
			if(thing[i].l != 0)
			{
				for(int j=i+1; j<n; j++)
				{
					if(thing[j].l>=thing[i].l && thing[j].w>=thing[i].w)
					{
						thing[i].l = thing[j].l;
						thing[i].w = thing[j].w;
						thing[j].l = 0;
						thing[j].w = 0;
					}
				}
				if(i >= 0)
				{
					thing[i].l = 0;
					thing[i].w = 0;
					count++;
				}
			}
		}
		printf("%d\n", count);
	}
	return 0;
}