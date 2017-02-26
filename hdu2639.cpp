#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

#define MAX 1005

int main()
{
	// freopen("test.in", "r", stdin);
	int t, n, v, m;
	while(scanf("%d", &t) != EOF)
	{
		while(t--)
		{
			int val[MAX], vol[MAX], dp[MAX][35];
			int i, j, k;
			int a[35], b[35];
			scanf("%d%d%d", &n, &v, &m);
			for(i=1; i<=n; i++)
			{
				scanf("%d", &val[i]);
			}
			for(i=1; i<=n; i++)
			{
				scanf("%d", &vol[i]);
			}
			memset(dp, 0, sizeof(dp));
			for(i=1; i<=n; i++)
			{
				for(j=v; j>=vol[i]; j--)
				{
					for(k=1; k<=m; k++)
					{
						a[k] = dp[j-vol[i]][k] + val[i];
						b[k] = dp[j][k];
					}
					int x, y, z;
					x = y = z = 1;
					a[k] = b[k] = -1;
					while(z<=m && (y<=m||x<=m))
					{
						if(a[x] > b[y])
						{
							dp[j][z] = a[x++];
						}
						else
						{
							dp[j][z] = b[y++];
						}
						if(dp[j][z] != dp[j][z-1])
						{
							z++;
						}
					}
				}
			}
			printf("%d\n", dp[v][m]);
		}
	}
	return 0;
}