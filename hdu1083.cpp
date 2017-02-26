#include<iostream>
#include<algorithm>

using namespace std;

const int MAX = 301;
int map[MAX][MAX];
int mark[MAX];
int piped[MAX];
int n;
int p;
int t, m;
int i, j;
int sum;

bool found(int course)
{
	int k;
	for(k=1; k<=n; k++)
	{
		if(!mark[k] && map[course][k] == 1)
		{
			mark[k] = 1;
			if(piped[k] == -1 || found(piped[k]))
			{
				piped[k] = course;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	// freopen("test.in", "r", stdin);
	scanf("%d", &t);
	while(t--)
	{
		while(scanf("%d%d", &p, &n) != EOF)
		{
			memset(map, 0, sizeof(map));
			for(i=1; i<=p; i++)
			{
				scanf("%d", &m);
				while(m--)
				{
					scanf("%d", &j);
					map[i][j] = 1;
				}
			}
			memset(piped, -1, sizeof(piped));
			sum = 0;
			for(i=1; i<=p; i++)
			{
				memset(mark, 0, sizeof(mark));
				if(found(i))
					sum++;
			}
			if(sum == p)
				printf("YES\n");
			else
				printf("NO\n");
		}	
	}
}