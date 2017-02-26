#include<stdio.h>
#include<string.h>

int main()
{
	int N, A, B, C;
	//目的地
	int des[400];
	char isOK[400];
	char LY[2];//1L2Y
	//表示目前该位置的状态
	char t;
	int i, f0, f1;
	int L = 0, Y = 0;
	while(scanf("%d %d %d %d", &N, &A, &B, &C) != EOF)
	{
		L = 0;
		Y =0;
		memset(des, -1, 400 * sizeof(int));
		memset(isOK, '1', 400 * sizeof(char));
		memset(LY, '1', 2 * sizeof(char));
		getchar();
		i=0;
		//初始化
		while((t=getchar()) != '\n')
		{
			if(t == 'N')
			{
				des[i] = i;
			} else if(t == ' ')
			{
				i++;
				continue;
			} else if(t != 'G' && t <= '9' && t >= '0')
			{
				des[i] = t - '0';
			}
		}
		i = 0;
		while(i != N)
		{
			if(des[i] == i)
				isOK[i] = '1';
			else {
				int d = des[i];
				while(d != des[d])
				{
					if(des[d] == i) {
						d = des[d];
						break;
					}
					d = des[d];
				}
				if(d == i) {
					isOK[i] = '0';
				} else {
					if(isOK[d] == '0')
						isOK[i] = '0';
					des[i] = d;
				}
			}
			i++;
		}
		// printf("isOK: \n");
		// for(i=0;i<N;i++)
		// {
		// 	printf("%c ", isOK[i]);
		// }
		// printf("\ndes:\n");
		// for(i=0;i<N;i++)
		// {
		// 	printf("%d ", des[i]);
		// }
		// printf("\n");
		i = 0;
		//偶数是Lele，奇数是Yueyue
		f0 = (A*C+B)%6+1;
		while(L!=N-1 && Y!=N-1 && (LY[0] == '1' || LY[1] == '1'))
		{
			if(i%2 == 0)
			{
				f1 = (A*f0+B)%6+1;
				if(L+f0 > N-1) {
					//点数太大，往回走
					int length = f0%(2*(N-1));
					if(L+length <= N-1) {
						L +=length;
					} else if(L+length <= 2*N-2) 
					{
						L = 2*N-2-length-L;
					} else {
						L = length-(2*N-2-L);
					}
				} else {
					L += f0;
				}
				// printf("%d \n", f0);
				if(isOK[L] == '0')
				{
					LY[0] = '0';
					LY[1] = '0';
				} else if(des[L] != L ) {
					L = des[L];
				}
				if(L == Y && L != 0)
					Y = 0;
			} else {
				f0 = (A*f1+B)%6+1;
				if(Y+f1 > N-1) {
					//点数太大，往回走
					int length = f1%(2*(N-1));
					if(Y+length <= N-1) {
						Y += length;
					} else if(Y+length <= 2*N-2)
					{
						Y = 2*N-2-length-Y;
					} else {
						Y = length-(2*N-2-Y);
					}
				} else {
					Y += f1;
				}
				// printf("%d \n", f1);
				if(isOK[Y] == '0')
				{
					LY[0] = '0';
					LY[1] = '0';
				} else if(des[Y] != Y) {
					Y = des[Y];
				}
				if(Y == L && Y != 0)
					L = 0;
			}
			i++;
			// printf("L:%d Y:%d \n", L, Y);
			// if(L == 0 && Y ==0 && i >= 2)
			// 	break;
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