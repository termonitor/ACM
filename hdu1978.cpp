#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	// freopen("test.in", "r", stdin);
	int T;
	while(scanf("%d", &T) != EOF)
	{
		int n, m;
		int i, j, k, l;
		int base[1000][1000];
		int dp[1000][1000];
		while(T--)
		{
			memset(dp, 0, sizeof(dp));
			scanf("%d %d", &n, &m);
			for(i=1; i<=n; i++)
				for(j=1; j<=m; j++)
					scanf("%d", &base[i][j]);
			int t;
			int sum = 0;
			dp[1][1] = 1;
			for(i=1; i<=n; i++)
			{
				for(j=1; j<=m&&!(i==n&&j==m); j++)
				{
					t = base[i][j];
					sum = dp[i][j] % 10000;
					for(k=i; k<=i+t&&k<=n; k++)
					{
						for(l=j; l<=j+t-k+i&&l<=m; l++)
						{
							dp[k][l] += sum;
						}
					}
				}
			}
			printf("%d\n", dp[n][m]%10000);
		}
	}
	return 0;
}