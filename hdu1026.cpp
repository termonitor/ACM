#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int n, m;

struct node
{
	int time;
	int x, y;
	int prex, prey;
	char data;
	bool operator<(const node &a) const
	{
		return a.time < time;
	}
}s[105][105];

typedef struct t
{
	int x, y;
}T;
node cur1;
T cur2, next2;

int BFS()
{
	priority_queue<node> qu;
	int i, x1, y1;
	s[0][0].time = 0;
	qu.push(s[0][0]);
	while(!qu.empty())
	{
		cur1 = qu.top();
		qu.pop();
		if(cur1.x==n-1 && cur1.y==m-1)
			return 1;
		// printf("%d %d\n", cur1.x, cur1.y);
		for(i=0; i<4; i++)
		{
			x1 = cur1.x + dir[i][0];
			y1 = cur1.y + dir[i][1];
			if(x1>=0 && x1<n && y1>=0 && y1<m)
			{
				if(s[x1][y1].data=='.' && s[x1][y1].time>cur1.time+1)
				{
					s[x1][y1].time = cur1.time + 1;
					s[x1][y1].prex = cur1.x;
					s[x1][y1].prey = cur1.y;
					qu.push(s[x1][y1]);
				}
				else if(isdigit(s[x1][y1].data) && s[x1][y1].time>cur1.time+(s[x1][y1].data-'0'))
				{
					s[x1][y1].time = cur1.time+(s[x1][y1].data-'0')+1;
					s[x1][y1].prex = cur1.x;
					s[x1][y1].prey = cur1.y;
					qu.push(s[x1][y1]);
				}
			}
		}
	}
	return 0;
}

void printpath(int x, int y)
{
	if(x==0 && y==0)
		return;
	int prex = s[x][y].prex;
	int prey = s[x][y].prey;
	printpath(prex, prey);
	int prelength = s[prex][prey].time;
	int length = s[x][y].time;
	printf("%ds:(%d,%d)->(%d,%d)\n",prelength+1,prex,prey,x,y);
	for(int i=prelength+2; i<=length; i++)
	{
		printf("%ds:FIGHT AT (%d,%d)\n",i,x,y);
	}
}

int main()
{
	// freopen("test.in", "r", stdin);
	while(scanf("%d%d", &n, &m) != EOF)
	{
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				// scanf("%c", &s[i][j].data);
				cin>>s[i][j].data;
				s[i][j].x = i;
				s[i][j].y = j;
				s[i][j].time = INT_MAX;
			}
		}
		int state = BFS();
		if(!state)
		{
			printf("God please help our poor hero.\n");
			printf("FINISH\n");
			continue;
		}
		printf("It takes %d seconds to reach the target position, let me show you the way.\n",s[n-1][m-1].time);
		printpath(n-1, m-1);
		printf("FINISH\n");
	}
}