#include<stdio.h>
#include<string.h>

double tmp[11];
void jiecheng()
{
	tmp[0] = 1;
	for(int i=1; i<11; i++)
	{
		tmp[i] = tmp[i-1] * i;
	}
}

int main()
{
	int N, M;
	int a[11];
	double c1[11], c2[11];
	int i, j, k;

	jiecheng();
	while(scanf("%d %d", &N, &M) != EOF)
	{
		for(i=0; i<N; i++)
		{
			scanf("%d", &a[i]);
		}

		memset(c1, 0, sizeof(c1));
		memset(c2, 0, sizeof(c2));

		for(i=0; i<=a[0]; i++)
		{
			c1[i] = 1.0/tmp[i];
		}
		for(i=1; i<N; i++)
		{
			for(j=0; j<=M; j++)
			{
				for(k=0; k+j<=M&&k<=a[i]; k++)
				{
					c2[k+j] += c1[j]/tmp[k];
				}
			}
			for(j=0; j<=M; j++)
			{
				c1[j] = c2[j];
				c2[j] = 0;
			}
		}
		printf("%.0lf\n", c1[M]*tmp[M]);
	}
	return 0;
}