#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>

using namespace std;

int main()
{
	// freopen("test.in", "r", stdin);
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n;
		int percost = 0x7fffffff;
		int vol = 0;
		string s, ans;
		scanf("%d", &n);
		while(n--)
		{
			int cost, p, day=0;
			cin>>s;
			scanf("%d%d", &cost, &p);
			if(p<200)
				continue;
			day = p/200;
			if(day>5)
				day = 5;
			if(cost/day<percost || (cost/day==percost&&p>vol))
			{
				ans = s;
				percost = cost/day;
				vol = p;
			}
		}	
		cout<<ans<<endl;
	}
	return 0;
}