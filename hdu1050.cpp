#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int cnt[200];
bool cmp(int a, int b)
{
	return a>b;
}

int main()
{
	// freopen("test.in", "r", stdin);
	int t;
	int n;
	int a, b;
	int l, r;
	scanf("%d", &t);
	while(t--)
	{
		memset(cnt, 0, sizeof(cnt));
		scanf("%d", &n);
		for(int i=0; i<n; i++)
		{
			scanf("%d%d", &a, &b);
			l = min(a, b);
			r = max(a, b);
			//因为标记的是走廊数，所以要除以2，因为两个房间之间只有1条走廊
			//1号和2号房间对应一条1号走廊
			//3号和4号房间对应一条2号走廊
			//所以搬向3号房间，和从4号房间搬出去，是要相互影响的
			l = (l+1)/2;
			r = (r+1)/2;
			for(int j=l; j<=r; j++)
				cnt[j]++;
		}
		sort(cnt, cnt+200, cmp);
		printf("%d\n", cnt[0]*10);	
	}
	return 0;
}