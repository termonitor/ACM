#include<stdio.h>
#include<string.h>

int main()
{
	int N, M;
	int c1[1000], c2[1000];
	int a[1000], b[1000];
	int i, j, k;

	while(scanf("%d %d", &N, &M) != EOF)
	{
		for(i=0; i<N; i++)
		{
			scanf("%d %d", &a[i], &b[i]);
		}
		memset(c1, 0, 1000 * sizeof(int));
		memset(c2, 0, 1000 * sizeof(int));

		for(i=a[0]; i<=b[0]; i++)
		{
			c1[i] = 1;
		}
		for(i=1; i<N; i++)
		{
			for(j=0; j<=M; j++)
			{
				for(k=a[i]; k+j<=M&&k<=b[i]; k++)
				{
					c2[k+j] += c1[j];
				}
			}
			for(j=0; j<=M; j++)
			{
				c1[j] = c2[j];
				c2[j] = 0;
			}
		}
		printf("%d\n", c1[M]);
	}
	return 0;
}