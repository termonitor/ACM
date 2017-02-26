#include<iostream>
#include<algorithm>

using namespace std;

const int maxn = 200;
int matrix[maxn][maxn];
int d[maxn];
bool tt[maxn];

int main()
{
	// freopen("test.in", "r", stdin);
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF)
	{
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
				matrix[i][j] = -1;
			d[i] = -1;
		}
		memset(tt, 0, sizeof(tt));
		int a, b, x;
		for(int i=0; i<m; i++)
		{
			scanf("%d%d%d", &a, &b, &x);
			if(x<matrix[a][b]||matrix[a][b]==-1)
				matrix[a][b] = matrix[b][a] = x;
		}
		int s, t;
		scanf("%d%d", &s, &t);
		d[s] = 0;
		tt[s] = true;
		int nn = n;
		while(nn--)
		{
			if(s==t)
				break;
			for(int i=0; i<n; i++)
			{
				if(tt[i])
					continue;
				if(matrix[s][i] != -1)
				{
					if(d[i] == -1)
						d[i] = matrix[s][i] + d[s];
					else if(d[i] > matrix[s][i] + d[s])
						d[i] = matrix[s][i] + d[s];
				}
			}
			int min = INT_MAX;
			for(int i=0; i<n; i++)
			{
				if(!tt[i] && d[i]<min && d[i]!=-1)
				{
					min = d[i];
					s = i;
				}
			}
			tt[s] = true;
		}
		printf("%d\n", d[t]);
	}
	return 0;
}