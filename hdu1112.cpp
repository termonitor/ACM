#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

bool key[109][109], s[11009][1009], vis[11009][1009];
int n, m;
int nm, mm;

bool in(int y)
{
	if(y>=0 && y<mm)
		return true;
	return false;
}

bool door(int x, int y)
{
	int i, j;
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		{
			if(key[i][j] && s[i+x][j+y])
				return false;
		}
	}
	return true;
}

int main()
{
	// freopen("test.in", "r", stdin);
	int cas, i, j, flag;
	char str[1009];
	scanf("%d", &cas);
	while(cas--)
	{
		memset(key, false, sizeof(key));
		memset(s, false, sizeof(s));
		memset(vis, false, sizeof(vis));
		scanf("%d%d", &n, &m);
		for(i=0; i<n; i++)
		{
			scanf("%s", str);
			for(j=0; j<m; j++)
			{
				if(str[j] == '#')
					key[i][j] = true;
			}
		}
		scanf("%d%d", &nm, &mm);
		nm += n;
		for(i=n; i<nm; i++)
		{
			scanf("%s", str);
			for(j=0; j<mm; j++)
			{
				if(str[j] == '#')
					s[i][j] = true;
			}
		}
		for(i=0; i<mm; i++)
			vis[0][i] = true;
		for(i=1; i<nm; i++)
		{
			flag = false;
			for(j=0; j<=mm-m; j++)
			{
				if(!vis[i][j] && (vis[i-1][j]||(in(j-1)&&vis[i][j-1])||(in(j+1)&&vis[i][j+1])))
				{
					if(door(i, j))
					{
						flag = true;
						vis[i][j] = true;
						if(j>0 && !vis[i][j-1])
							j -= 2;
					}
				}
			}
			if(!flag)
				break;
		}
		if(i >= nm)
			printf("The key can fall through.\n");
		else
			printf("The key falls to depth %d.\n", i-1);
	}
	return 0;
}