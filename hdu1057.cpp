#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int map[22][22];
int tmp[22][22];
int D[17];
char arr[4] = {'.', '!', 'X', '#'};

int main()
{
	// freopen("test.in", "r", stdin);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int day;
		scanf("%d", &day);
		memset(D, 0, sizeof(D));
		memset(map, 0, sizeof(map));
		memset(tmp, 0, sizeof(tmp));
		for(int i=0; i<16; i++)
		{
			scanf("%d", &D[i]);
		}
		for(int i=1; i<=20; i++)
		{
			for(int j=1; j<=20; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}
		for(int i=0; i<day; i++)
		{
			for(int j=1; j<=20; j++)
			{
				for(int k=1; k<=20; k++)
				{
					int sum = 0;
					sum = map[j][k] + map[j+1][k] + map[j-1][k] + map[j][k-1] + map[j][k+1];
					tmp[j][k] = map[j][k] + D[sum];
					if(tmp[j][k] > 3)
						tmp[j][k] = 3;
					if(tmp[j][k] < 0)
						tmp[j][k] = 0;
				}
			}
			memcpy(map, tmp, sizeof(tmp));
		}
		for(int i=1; i<=20; i++)
		{
			for(int j=1; j<=20; j++)
			{
				printf("%c", arr[map[i][j]]);
			}
			printf("\n");
		}
		if(t)
			printf("\n");
	}
	return 0;
}