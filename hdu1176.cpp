#include<iostream>
#include<algorithm>

using namespace std;

int max(int a, int b, int c)
{
	if(a<b)
		a = b;
	if(a<c)
		a = c;
	return a;
}

int main()
{
	int n, m;
	int dp[100005][12];
	int i, j ,k;
	int x, t;
	while(scanf("%d", &n)!=EOF && n)
	{
		m=0;
		memset(dp, 0, sizeof(dp));
		for(i=1; i<=n; i++)
		{
			scanf("%d %d", &x, &t);
			if(t>m)
				m = t;
			dp[t][x] ++;
		}
		for(i=m; i>=0; i--)
		{
			for(j=0; j<=10; j++)
			{
				if(!j)
					dp[i][j] += max(dp[i+1][j], 0, dp[i+1][j+1]);
				else
					dp[i][j] += max(dp[i+1][j-1], dp[i+1][j], dp[i+1][j+1]);
			}
		}
		printf("%d\n", dp[0][5]);
	}
	return 0;
}