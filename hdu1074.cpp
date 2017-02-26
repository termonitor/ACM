#include<iostream>
#include<algorithm>

using namespace std;

#define IMAX 1<<16
#define INF 0x7ffffff

struct p {
	char name[102];
	int deadline;
	int time;
}node[20];

struct DPL
{
	int score;
	int last;
	int pos;
	int time;
}dp[IMAX];

int main()
{
	int T, N;
	int len, cur, prior, dis;
	int i, j;
	while(scanf("%d", &T)!=EOF && T)
	{
		while(T--)
		{
			scanf("%d", &N);
			for(i=0; i<N; i++)
			{
				scanf("%s %d %d", &(node[i].name[0]), &(node[i].deadline), &(node[i].time));
			}
			len = 1<<N;	//最终状态，这里是用二进制的状态表示作业的完成与否
			for(i=1; i<len; i++)
			{
				dp[i].score = INF;//初始化
				for(j=N; j>=0; j--)
				{
					cur = 1<<j;//将j左移，表示第j-1题
					if(cur&i)//判断出当前状态是j已经完成了
					{
						prior = i-cur;//求出上一道完成的题目，这里不太懂
						dis = dp[prior].time + node[j].time - node[j].deadline;
						if(dis < 0)
							dis = 0;
						if(dis+dp[prior].score < dp[i].score)
						{
							dp[i].score = dis + dp[prior].score;
							dp[i].pos = j;
							dp[i].last = prior;
							dp[i].time = dp[prior].time + node[j].time;
						}
					}
				}
			}

			int stack_[20];
			int top = len - 1;
			i = N-1;
			while(i >= 0)
			{
				stack_[i] = dp[top].pos;
				top=dp[top].last;
				i--;
			}
			top = len - 1;
			printf("%d\n", dp[top].score);
			j = 0;
			while(j < N)
			{
				i = stack_[j];
				puts(node[i].name);
				j++;
			}
		}
	}
	return 0;
}