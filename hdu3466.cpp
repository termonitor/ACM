#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

struct node
{
	int p;
	int q;
	int v;
}a[550];

int dp[5500];

//按照q-p 从小到大顺序排列
bool cmp(node a, node b)
{
	return a.q-a.p < b.q-b.p;
}

int main()
{
	// freopen("test.in", "r", stdin);
	int n, m;
	while(~scanf("%d%d", &n, &m))
	{
		for(int i=0; i<n; i++)
		{
			scanf("%d%d%d", &a[i].p, &a[i].q, &a[i].v);
		}
		sort(a, a+n, cmp);
		memset(dp, 0, sizeof(dp));
		for(int i=0; i<n; i++)
			for(int j=m; j>=a[i].q; j--)
			{
				dp[j] = max(dp[j], dp[j-a[i].p]+a[i].v);
			}
		printf("%d\n", dp[m]);
	}
	return 0;
}