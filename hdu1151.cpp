#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAXN = 121;
int no_of_intersections, no_of_streets, t;
int link[MAXN];	//记录当前与street终点相连的起点点 
bool map[MAXN][MAXN];	//存储二分图，起点到终点有路径，则map[x][y]=true;反之，为false
bool vis[MAXN];	//记录路口点是否使用了

void getMap()
{
	memset(map, false, sizeof(map));
	int a, b;
	for(int i=1; i<=no_of_streets; i++)
	{
		scanf("%d%d", &a, &b);
		map[a][b] = true;
	}
}

bool can(int t)
{
	for(int i=1; i<=no_of_intersections; i++)
	{
		if(!vis[i] && map[t][i])
		{
			vis[i] = true;
			if(link[i]==-1 || can(link[i]))
			{
				link[i] = t;
				return true;
			}
		}
	}
	return false;
}

int maxMatch()
{
	int num = 0;
	memset(link, -1, sizeof(link));
	for(int i=1; i<=no_of_intersections; i++)
	{
		memset(vis, false, sizeof(vis));
		if(can(i))
			num++;
	}
	return num;
}

int main()
{
//	freopen("test.in", "r", stdin);
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d", &no_of_intersections, &no_of_streets);
		getMap();
		printf("%d\n", no_of_intersections-maxMatch());
	}
	return 0;
}
