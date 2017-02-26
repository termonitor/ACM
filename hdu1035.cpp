#include<iostream>
#include<algorithm>

using namespace std;

char map[20][20];
int visited[20][20];

int main()
{
	// freopen("test.in", "r", stdin);
	int n, m, l;
	while(scanf("%d%d%d", &n, &m, &l) != EOF)
	{
		if(n==0 && m==0 && l==0)
			break;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				cin>>map[i][j];
				visited[i][j] = 0;
			}
		}
		int x, y;
		int step = 0;
		x = 0;
		y = l-1;
		visited[x][y] = step;
		int flag = 0;
		int loop = 0;
		while(1)
		{
			// printf("%d %d\n", x, y);
			if(x<0 || y<0 || x >=n || y>=m)
				break;
			if(map[x][y] == 'N' && !visited[x][y])
			{
				step++;
				visited[x][y] = step;
				x--;
			}
			else if(map[x][y] == 'S' && !visited[x][y])
			{
				step++;
				visited[x][y] = step;
				x++;
			}
			else if(map[x][y] == 'W' && !visited[x][y])
			{
				step++;
				visited[x][y] = step;
				y--;
			}
			else if(map[x][y] == 'E' && !visited[x][y])
			{
				step++;
				visited[x][y] = step;
				y++;
			}
			else if(visited[x][y])
			{
				flag = 1;
				loop = step - visited[x][y] + 1;
				break;
			}
		}
		if(flag)
			printf("%d step(s) before a loop of %d step(s)\n", step-loop, loop);
		else 
			printf("%d step(s) to exit\n", step);
	}
	return 0;
}