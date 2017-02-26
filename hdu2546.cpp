#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int dp[1212];
int a[1212];

int main()
{
	// freopen("test.in", "r", stdin);
	int n;
	while(~scanf("%d", &n))
	{
		if(n==0)
			break;
		memset(dp, 0, sizeof(dp));
		for(int i=0; i<n; i++)
		{
			scanf("%d", &a[i]);
		}
		int m;
		scanf("%d", &m);
		if(m < 5)
		{
			printf("%d\n", m);
			continue;
		}
		sort(a, a+n);
		for(int i=0; i<n-1; i++)
		{
			for(int j=m-5; j>=a[i]; j--)
			{
				dp[j] = max(dp[j], dp[j-a[i]]+a[i]);
			}
		}
		printf("%d\n", m-dp[m-5]-a[n-1]);
	}
	return 0;
}