#include<stdio.h>
#include<string.h>

char prime[38];
int result[20];
char status[21];

void dfs(int n, int depth)
{
	int i, j;
	if(depth == n) {
		if(n == 1) {
			return;
		}
		printf("%d", result[0]);
		for(i=1; i<n; i++)
		{
			printf(" %d", result[i]);
		}
		printf("\n");
		return;
	}
	
	if(result[depth] == 0)
	{
		for(j=1; j<=n; j++)
		{
			if(status[j] == '1')
				continue;
			int k = j + (result[depth-1]);
			if(prime[k] == '1')
			{
				if(depth == n-1)
				{
					//最后一个，还要和1相加比较
					if(prime[1+j] == '0')
					{
						continue;
					}
				}
				result[depth] = j;
				status[j] = '1';
				dfs(n, depth+1);
				status[j] = '0';
				result[depth] = 0;
			}
		}
	}
}

int main()
{
	int n;
	int time = 1;
	memset(prime, '0', 38 * sizeof(char));
	memset(result, 0, 20 * sizeof(int));
	memset(status, '0', 20 * sizeof(char));
	//n的范围内的素数
	prime[2] = '1';
	prime[3] = '1';
	prime[5] = '1';
	prime[7] = '1';
	prime[11] = '1';
	prime[13] = '1';
	prime[17] = '1';
	prime[19] = '1';
	prime[23] = '1';
	prime[29] = '1';
	prime[31] = '1';
	prime[37] = '1';
	while(scanf("%d", &n) != EOF) {
		printf("Case %d:\n", time);
		result[0] = 1;
		status[1] = '1';
		dfs(n, 1);
		printf("\n");
		time++;
	}
	return 0;
}