#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

/*
	用成功逃走的概率当做价值！银行的总钱数当做背包容量！
*/

int main()
{
	// freopen("test.in", "r", stdin);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		float P;
		int n, sum=0;
		float p[110], dp[10010];
		int M[110];
		scanf("%f %d", &P, &n);
		P = 1-P;
		memset(dp, 0, sizeof(dp));
		for(int i=1; i<=n; i++)
		{
			scanf("%d %f", &M[i], &p[i]);
			sum += M[i];
			p[i] = 1-p[i];
		}
		dp[0] = 1;
		for(int i=1; i<=n; i++)
		{
			for(int j=sum; j>=M[i]; j--)
			{
				dp[j] = max(dp[j], dp[j-M[i]]*p[i]);
			}
		}
		int flag = 0;
		for(int i=sum; i>=0; i--)
		{
			if(dp[i] >= P)
			{
				flag = i;
				break;
			}
		}
		printf("%d\n", flag);
	}
	return 0;
}