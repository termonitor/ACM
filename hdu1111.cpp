#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int maxn = 110;
__int64 xr, xi, br, bi, num;
__int64 flag, t;
__int64 ans[maxn];

void dfs(__int64 rr, __int64 ii, __int64 step)
{
	__int64 x, y, i;
	if(step>100)
		return;
	if(flag)
		return;
	if(rr==0 && ii==0)
	{
		flag = 1;
		t = step;
		return;
	}
	for(i=0; i*i<num; i++)
	{
		x = (rr-i)*br + ii*bi;
		y = ii*br - (rr-i)*bi;
		ans[step] = i;
		if(x%num==0 && y%num==0)
			dfs(x/num, y/num, step+1);
		if(flag)
			return;
	}
}

int main()
{
	// freopen("test.in", "r", stdin);
	__int64 T, i;
	scanf("%I64d", &T);
	while(T--)
	{
		scanf("%I64d%I64d%I64d%I64d", &xr, &xi, &br, &bi);
		num = br*br+bi*bi;
		flag = 0;
		dfs(xr, xi, 0);
		if(!flag)
			printf("The code cannot be decrypted.\n");
		else
		{
			printf("%I64d", ans[t-1]);
			for(i=t-2; i>=0; i--)
				printf(",%I64d", ans[i]);
			printf("\n");
		}
	}
	return 0;
}