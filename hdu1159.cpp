#include<iostream>
#include<algorithm>

using namespace std;

int max(int a, int b)
{
	return (a>b)? a:b;
}

int main()
{
	char x[1001], y[1001];
	int dp[1001][1001];
	int i, j;
	int len1, len2;
	while(scanf("%s %s", &x[0], &y[0]) != EOF)
	{
		memset(dp, 0, sizeof(dp));
		len1 = strlen(x);
		len2 = strlen(y);
		for(i=0; i<=len1; i++)
		{
			dp[i][0] = 0;
		}
		for(i=0; i<=len2; i++)
		{
			dp[0][i] = 0;
		}
		for(i=1; i<=len1; i++)
		{
			for(j=1; j<=len2; j++)
			{
				if(x[i-1] == y[j-1])
				{
					dp[i][j] = dp[i-1][j-1] + 1;
				}
				else {
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				}
			}
		}
		printf("%d\n", dp[len1][len2]);
	}
	return 0;
}