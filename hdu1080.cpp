#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 101;
int dp[N][N];

int max(int a, int b)
{
	if(a > b)
		return a;
	return b;
}

int main()
{
	// freopen("test.in", "r", stdin);
	int t;
	scanf("%d", &t);
	int r[5][5] = { {5, -1, -2, -1, -3},
					{-1, 5, -3, -2, -4},
					{-2, -3, 5, -2, -2},
					{-1, -2, -2, 5, -1},
					{-3, -4, -2, -1, 0}};
	while(t--)
	{
		int n, m;
		char str1[N];
		char str2[N];
		int a[N], b[N];
		scanf("%d", &n);
		cin>>str1;
		scanf("%d", &m);
		cin>>str2;
		for(int i=0; i<n; i++)
		{
			switch(str1[i])
			{
				case 'A':
					a[i] = 0; break;
				case 'C':
					a[i] = 1; break;
				case 'G':
					a[i] = 2; break;
				case 'T':
					a[i] = 3; break;
				case '-':
					a[i] = 4; break;
				default:
					a[i] = 0;
			}
		}
		for(int i=0; i<m; i++)
		{
			switch(str2[i])
			{
				case 'A':
					b[i] = 0; break;
				case 'C':
					b[i] = 1; break;
				case 'G':
					b[i] = 2; break;
				case 'T':
					b[i] = 3; break;
				case '-':
					b[i] = 4; break;
				default:
					b[i] = 0;
			}
		}
		memset(dp, 0, sizeof(dp));
		for(int i=1; i<=n; i++)
			dp[i][0] = dp[i-1][0] + r[a[i-1]][4];
		for(int i=1; i<=m; i++)
			dp[0][i] = dp[0][i-1] + r[4][b[i-1]];
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=m; j++)
			{
				dp[i][j] = max(dp[i-1][j-1] + r[a[i-1]][b[j-1]], max(dp[i-1][j]+r[a[i-1]][4], dp[i][j-1]+r[4][b[j-1]]));
			}
		}
		printf("%d\n", dp[n][m]);
	}
	return 0;
}