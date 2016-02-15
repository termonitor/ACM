#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAXN = 9;
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
int map[MAXN][MAXN], step[MAXN][MAXN], tim[MAXN][MAXN];
int n, m, sx, sy, dx, dy, minx;


void dfs(int x, int y, int len, int cnt)
{
	if(x<0 || y<0 || x>=n || y>=m)
		return;
	if(len<=0 || cnt>=minx)
		return;
	if(map[x][y] == 0)
		return;
	if(map[x][y] == 3)
	{
		if(cnt < minx)
			minx = cnt;
		return;
	}
	if(map[x][y] == 4)
	{
		len = 6;
	}
	if(cnt>=step[x][y] && tim[x][y]>=len)
		return;
	step[x][y] = cnt;
	tim[x][y] = len;
	int tx, ty, i;
	for(i=0; i<4; i++)
	{
		tx = x + dir[i][0];
		ty = y + dir[i][1];
		dfs(tx, ty, len-1, cnt+1);
	}
}

int main()
{
	// freopen("test.in", "r", stdin);
	int t;
	scanf("%d", &t);
	int i, j, len, cnt;
	while(t--)
	{
		scanf("%d%d", &n, &m);
		for(i=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				tim[i][j] = 0;
				step[i][j] = INT_MAX-3;
				scanf("%d", &map[i][j]);
				if(map[i][j] == 2)
				{
					sx = i;
					sy = j;
				} else if(map[i][j] == 3)
				{
					dx = i;
					dy = j;
				}
			}
		}
		len = 6;
		cnt = 0;
		minx = INT_MAX;
		dfs(sx, sy, len, cnt);
		if(minx == INT_MAX)
		{
			printf("-1\n");
		}
		else
		{
			printf("%d\n", minx);
		}
	}
	return 0;
}