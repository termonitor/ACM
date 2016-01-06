#include<stdio.h>

int main()
{
	int N;
	int i, j, k;
	int count;
	int n, m;
	int time;
	scanf("%d", &N);
	for(i=0; i<N; i++) {
		time = 1;
		while(scanf("%d %d", &n, &m), n>0)
		{
			count = 0;
			//j代表a, k代表b
			for(j=1; j<n-1; j++)
			{
				for(k=j+1; k<n; k++)
				{
					if((j*j + k*k +m) % (j*k) == 0)
						count++;
				}
			}
			printf("Case %d: %d\n", time++, count);
		}
		if(i != N-1)
			printf("\n");
	}
	return 0;
}