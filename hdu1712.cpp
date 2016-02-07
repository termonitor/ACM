#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int main()
{
	// freopen("test.in", "r", stdin);
	int n, m;
	int a[150][150];
	int dp[150];
	while(~scanf("%d%d", &n, &m))
	{
		if(n==0 && m==0)
			break;
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=m; j++)
			{
				scanf("%d", &a[i][j]);
			}
		}
		memset(dp, 0, sizeof(dp));
		for(int i=1; i<=n; i++)
		{
			for(int j=m; j>=0; j--)
			{
				for(int k=1; k<=j; k++)
				{
					dp[j] = max(dp[j], dp[j-k]+a[i][k]);
				}
			}
		}
		printf("%d\n", dp[m]);
	}
	return 0;
}