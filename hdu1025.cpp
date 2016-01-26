#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
#define MAXN 500005
int poor[MAXN], res[MAXN], len[MAXN];

int find(int a, int l, int r)
{
	int mid = (l+r)/2;
	while(l <= r)
	{
		if(a == res[mid])
			return mid;
		else
		{
			if(a > res[mid])
				l = mid+1;
			else
				r = mid-1;
			mid = (l+r)/2;
		}
	}
	return l;
}

int main()
{
	// freopen("test.in", "r", stdin);
	int i, k, n, cas, max, r, pos;
	cas = 1;
	while(scanf("%d", &n) != EOF)
	{
		memset(res, 0, sizeof(res));
		memset(len, 0, sizeof(len));
		for(i=1; i<=n; i++)
			res[i] = MAXN;
		for(i=1; i<=n; i++)
		{
			scanf("%d%d", &k, &r);
			poor[k] = r;
		}
		res[1] = poor[1];
		len[1] = 1;
		for(i=2; i<=n; i++)
		{
			pos = find(poor[i], 1, n);
			res[pos] = poor[i];
			len[i] = pos;
		}
		max = 0;
		for(i=1; i<=n; i++)
		{
			if(len[i] > max)
				max = len[i];
		}
		if(max == 1)
			printf("Case %d:\nMy king, at most %d road can be built.\n\n", cas++, max);
		else
			printf("Case %d:\nMy king, at most %d roads can be built.\n\n", cas++, max);
	}
	return 0;
}