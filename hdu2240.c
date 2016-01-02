#include<stdio.h>
#include<string.h>

int main()
{
	int N, A, B, C;
	//步数
	int len[400];
	//表示目前该位置的状态
	char t;
	int i, f0, f1;
	int L = 0, Y = 0;
	while(scanf("%d %d %d %d", &N, &A, &B, &C) != EOF)
	{
		L = 0;
		Y =0;
		memset(len, -1, 400 * sizeof(int));
		getchar();
		i=0;
		//初始化
		while((t=getchar()) != '\n')
		{
			if(t == 'N')
			{
				len[i] = i;
			} else if(t == ' ')
			{
				i++;
				continue;
			} else if(t != 'G' && t <= '9' && t >= '0')
			{
				len[i] = t - '0';
			}
		}
		i = 0;
		//偶数是Lele，奇数是Yueyue
		f0 = (A*C+B)%6+1;
		while(L!=N-1 && Y!=N-1)
		{
			if(i%2 == 0)
			{
				if(L+f0 > N) {
					//点数太大，往回走
					L = 2*N-2-f0-L;
					while(L != len[L])
					{
						L = len[L];
					}
				} else {
					L += f0;
					while(L != len[L])
					{
						L = len[L];
					}
				}
				if(L == Y && L != 0)
					Y = 0;
				f1 = (A*f0+B)%6+1;
			} else {
				if(Y+f1 > N) {
					//点数太大，往回走
					Y = 2*N-2-f1-Y;
					while(Y != len[Y])
					{
						Y = len[Y];
					}
				} else {
					Y += f1;
					while(Y != len[Y])
					{
						Y = len[Y];
					}
				}
				if(Y == L && Y != 0)
					L = 0;
				f0 = (A*f1+B)%6+1;
			}
			i++;
			if(L == 0 && Y ==0)
				break;
			if(i >= 2*N)
				break;
		}
		if(L == N-1)
		{
			printf("Lele\n");
		} else if(Y == N-1) {
			printf("Yueyue\n");
		} else {
			printf("Impossible\n");
		}
	}
	return 0;
}