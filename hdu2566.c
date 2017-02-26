#include<stdio.h>
#include<string.h>

int main()
{
	int T;
	int c1[100][100], c2[100][100];
	int i, j, k, l;
	while(scanf("%d", &T) != EOF)
	{
		int N, M;
		while(T--)
		{
			scanf("%d %d", &N, &M);
			memset(c1, 0, sizeof(c1));
			memset(c2, 0, sizeof(c2));

			for(i=0; i<=N; i++)
			{
				c1[i][i] = 1;
			}
			for(i=2; i<=5; i+=3) //每个硬币的分值
			{
				for(j=0; j<=M; j++) //已经算进去的分值
				{
					for(k=0; k*i+j<=M&&k<=N; k++) //本次计算后的分值
					{
						for(l=0; l+k<=N; l++) //本次使用的硬币数量
							c2[k*i+j][l+k] += c1[j][l];
					}
				}
				for(j=0; j<=M; j++)
					for(k=0; k<=N; k++)
					{
						c1[j][k] = c2[j][k];
						c2[j][k] = 0;
					}
			}
			printf("%d\n", c1[M][N]);
		}
	}
	return 0;
}