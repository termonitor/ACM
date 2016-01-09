#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	int dp[2005];
	int people[2005];
	int adjacent[2005];
	while(scanf("%d", &n)!=EOF && n)
	{
		while(n--)
		{
			int m;
			int i, j, k;

			scanf("%d", &m);

			memset(people, 0, sizeof(people));
			memset(adjacent, 0, sizeof(adjacent));

			for(i=0; i<m; i++)
			{
				scanf("%d", &people[i]);
			}
			for(i=0; i<m-1; i++)
			{
				scanf("%d", &adjacent[i]);
			}

			dp[0] = people[0];
			for(i=1; i<m; i++)
			{
				if(i==1)
				{
					if(dp[0]+people[i] < adjacent[i-1])
					{
						dp[i] = dp[0] + people[i];
					} else {
						dp[i] = adjacent[i-1];
					}
				} else {
					if(dp[i-1] + people[i] < dp[i-2] + adjacent[i-1])
					{
						dp[i] = dp[i-1] + people[i];
					} else {
						dp[i] = dp[i-2] + adjacent[i-1];
					}
				}
			}
			int result = dp[m-1];
			int h, mi, s, am;
			h = 8;
			mi = 0;
			s = result;
			am = 1;
			if(s >= 60) {
				mi += s/60;
				s %= 60;
			}
			if(mi >= 60) {
				h += mi/60;
				mi %= 60;
			}
			if(h < 12 || (h==12 && mi==s && s==0))
			{

			} else {
				if(h != 12)
					h %= 12;
				am = 0;
			}
			//下面这段表示法是正确的
			// s = dp[m-1]%60;
			// mi = dp[m-1]/60%60;
			// h += (dp[m-1]/3600);
			// if(h<12 || (h==12 && mi==s && s == 0))
			// {
			// 	am = 1;
			// } else
			// {
			// 	if(h != 12)
			// 		h %= 12;
			// 	am = 0;
			// }
			if(!am) {
				printf("%02d:%02d:%02d pm\n", h, mi, s);
			} else {
				printf("%02d:%02d:%02d am\n", h, mi, s);
			}
		}
	}
	return 0;
}