#include<iostream>
#include<algorithm>

using namespace std;
/*
	dp[i][j] 表示前i件物品取j对的最优解
	i == j*2时	dp[i][j] = dp[i-2][j-1]+(a[i]-a[i-1])*(a[i]-a[i-1])
	i > j*2时	dp[i][j] = min(dp[i-1][j], dp[i-2][j-1]+(a[i]-a[i-1])*(a[i]-a[i-1]))
*/

int minn(int a, int b)
{
	if(a > b)
		return b;
	return a;
}
int main()
{
	int dp[2050][2050];
	int a[2050];
	int i, j, n , k;
	while(scanf("%d %d", &n, &k)!=EOF)
	{
		memset(dp, 0, sizeof(dp));
		for(i=1; i<=n; i++)
			scanf("%d", &a[i]);
		sort(a+1, a+1+n);
		dp[2][1] = (a[2]-a[1]) * (a[2]-a[1]);
		for(j=1; j<=k; j++)
			for(i=j*2; i<=n; i++)
			{
				dp[i][j] = dp[i-2][j-1]+(a[i]-a[i-1])*(a[i]-a[i-1]);
				if(j*2 < i)
				{
					dp[i][j] = minn(dp[i][j], dp[i-1][j]);
				}
			}
		printf("%d\n", dp[n][k]);
	}
	return 0;
}