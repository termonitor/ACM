#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	int map[150][150];
	int dp[150][150];
	// freopen("test.in", "r", stdin);
	while(scanf("%d", &n)!= EOF && n!=0)
	{
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				scanf("%d", &map[i][j]);
		memset(dp, 0, sizeof(dp));
		int max = INT_MIN;
		for(int i=n; i>=1; i--)
		{
			for(int j=n; j>=1; j--)
			{
				dp[i][j] = map[i][j];
				if(dp[i][j] > max) 
					max = dp[i][j];
				for(int i1=i-1; i1>=1; i1--)
				{
					dp[i1][j] = dp[i1+1][j] + map[i1][j];
					if(dp[i1][j] > max)
						max = dp[i1][j];
				}
				for(int j1=j-1; j1>=1; j1--)
				{
					dp[i][j1] = dp[i][j1+1] + map[i][j1];
					if(dp[i][j1] > max)
						max = dp[i][j1];
				}
				for(int i1=i-1; i1>=1; i1--)
				{
					for(int j1= j-1; j1>=1; j1--)
					{
						dp[i1][j1] = dp[i1+1][j1] + dp[i1][j1+1] - dp[i1+1][j1+1] + map[i1][j1];
						if(dp[i1][j1] > max)
							max = dp[i1][j1];
					}
				}
			}
		}
		printf("%d\n", max);
	}
	return 0;
}