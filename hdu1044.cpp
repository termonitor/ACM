#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;

int W, H, L, M; 
int val[60];
char map[60][60];
bool used[60][60];
bool vis[60];
int step[60][60];
int ans;
int sum;
int mov[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int dis[60][60];
queue<int> q;

void bfs(int x1, int y1, int s)
{
	while(!q.empty())
		q.pop();
	memset(used, false, sizeof(used));
	memset(step, 0, sizeof(step));
	int u = x1*W+y1;
	q.push(u);
	used[x1][y1] = true;
	step[x1][y1] = 0;
	while(!q.empty())
	{
		u = q.front();
		q.pop();
		int x = u/W;
		int y = u%W;
		for(int i=0; i<4; i++)
		{
			int xx = x + mov[i][0];
			int yy = y + mov[i][1];
			if(xx<0 || yy<0 || xx>=H || yy>=W)
				continue;
			if(used[xx][yy] || map[xx][yy] == '*')
				continue;

			used[xx][yy] = true;
			step[xx][yy] = step[x][y] + 1;
			if(map[xx][yy] == '@')
				dis[s][0] = step[xx][yy];
			else if(map[xx][yy] == '<')
				dis[s][M+1] = step[xx][yy];
			else if(map[xx][yy]>='A' && map[xx][yy]<='J')
				dis[s][map[xx][yy]-'A'+1] = step[xx][yy];
			q.push(xx*W+yy);
		}
	}
}

void dfs(int s, int value, int time1)
{
	if(time1 > L)
		return;
	if(ans == sum)
		return;
	if(s > M)
	{
		if(value > ans)
			ans = value;
		return;
	}
	for(int i=0; i<=M+1; i++)
	{
		if(dis[s][i] == 0 || vis[i])
			continue;
		vis[i] = true;
		dfs(i, value+val[i], time1+dis[s][i]);
		vis[i] = false;
	}
}

int main()
{
	// freopen("test.in", "r", stdin);
	int T;
	scanf("%d", &T);
	int cas = 0;
	while(T--)
	{
		memset(dis, 0, sizeof(dis));
		cas += 1;
		scanf("%d%d%d%d", &W, &H, &L, &M);
		sum = 0;
		ans = -1;
		for(int i=1; i<=M; i++)
		{
			scanf("%d", &val[i]);
			sum += val[i];
		}
		val[0] = val[M+1] = 0;
		for(int i=0; i<H; i++)
			cin>>map[i];
		for(int i=0; i<H; i++)
			for(int j=0; j<W; j++)
			{
				if(map[i][j] == '@')
					bfs(i, j, 0);
				else if(map[i][j] == '<')
					bfs(i, j, M+1);
				else if(map[i][j] >= 'A' && map[i][j] <= 'J')
					bfs(i, j, map[i][j]-'A'+1);
			}
		memset(vis, false, sizeof(vis));
		vis[0] = true;
		dfs(0, 0, 0);
		printf("Case %d:\n", cas);
		if(ans >=0)
			printf("The best score is %d.\n", ans);
		else
			printf("Impossible\n");
		if(T > 0)
			printf("\n");
	}
	return 0;
}