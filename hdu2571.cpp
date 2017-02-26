#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	// freopen("test.in", "r", stdin);
	int C;
	scanf("%d", &C);
	while(C--)
	{
		int n, m;
		int i, j, k;
		int w[100][1050];
		int dp[100][1050];
		scanf("%d%d", &n, &m);
		for(i=1; i<=n; i++)
		{
			for(j=1; j<=m; j++)
			{
				scanf("%d", &w[i][j]);
			}
		}

		dp[1][1] = w[1][1];

		for(i=1; i<=n; i++)
		{
			for(j=1; j<=m; j++)
			{
				if(i==1 && j==1)
					continue;
				int max;
				int v;
				int dir;
				if(i==1) {
					max = dp[i][j-1];
					v = j-1;
					dir = 1;//横向
				} else {
					max = dp[i-1][j];
					v = i-1;
					dir = 0;//纵向
				}
					
				for(k=1; k<j; k++)
				{
					if(j%k==0 && max < dp[i][k]) {
						max = dp[i][k];
						v = k;
						dir = 1;//横向
					}
				}

				if(j!=1&&max < dp[i][j-1]) {
					max = dp[i][j-1];
					v = j-1;
					dir = 1;
				}
				&&dp[i][j] < dp[i][v] + w[i][j]
				if(dir==1)
				{
					dp[i][j] = dp[i][v] + w[i][j];
					// printf("横向 %d %d %d %d\n", i, j, v, w[i][j]);
				} else if(dir==0)
				{
					dp[i][j] = dp[i-1][j] + w[i][j];
					// printf("纵向 %d %d %d\n", i, j, w[i][j]);
				}
			}
		}

		printf("%d\n", dp[n][m]);
	}
	return 0;
}