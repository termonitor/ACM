#include<iostream>
#include<algorithm>

using namespace std;

struct p
{
	int exp;//experience
	int pat;//patience
}node[1000];

int main()
{
	int n, m, k, s;
	int i, j, l;
	int dp[1000][1000];
	// freopen("test.in", "r", stdin);
	while(scanf("%d%d%d%d", &n, &m, &k, &s) != EOF)
	{
		for(i=1; i<=k; i++)
			scanf("%d%d", &node[i].exp, &node[i].pat);
		memset(dp, 0, sizeof(dp));
		for(i=1; i<=k; i++)
		{
			for(j=0; j<=s; j++)
			{
				for(l=0; l<=m; l++)
				{
					if(j>0&&node[i].pat <=l &&dp[j-1][l-node[i].pat]+node[i].exp > dp[j][l])
					{
						dp[j][l] = dp[j-1][l-node[i].pat]+node[i].exp;
					}
				}
			}
		}
		// for(i=0; i<=s; i++)
		// {
		// 	for(j=0; j<=m; j++)
		// 	{
		// 		printf("%d ", dp[i][j]);
		// 	}
		// 	printf("\n");
		// }
		if(dp[s][m] < n)
			printf("-1\n");
		else {
			int max = 10000000;
			for(i=0; i<=s; i++)
				for(j=0; j<=m; j++)
					if(n <= dp[i][j] && j < max)
						max = j;
			printf("%d\n", m-max);
		}
	}
	return 0;
}