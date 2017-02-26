#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

/*
	多重背包
*/

#define maxn 120005

int d[maxn], v;

//01背包, c表示花费, w表示价值
void bag01(int c, int w)
{
	for(int i=v; i>=c; i--)
	{
		if(d[i] < d[i-c]+w)
		{
			d[i] = d[i-c]+w;
		}
	}
}

//完全背包, c表示花费, w表示价值
void bagall(int c, int w)
{
	for(int i=c; i<=v; i++)
	{
		if(d[i] < d[i-c]+w)
		{
			d[i] = d[i-c]+w;
		}
	}
}

//多重背包, c表示花费, w表示价值, n表示个数
void multbag(int c, int w, int n)
{
	if(c*n >= v)
	{
		bagall(c, w);
		return;
	}
	int k=1;
	while(k <= n)
	{
		bag01(k*c, k*w);
		n = n-k;
		k = k*2;
	}
	bag01(n*c, n*w);
}

int main()
{
	// freopen("test.in", "r", stdin);
	int n[6], sumv, i, k=1;
	while(scanf("%d%d%d%d%d%d", &n[0], &n[1], &n[2], &n[3], &n[4], &n[5]))
	{
		if(n[0]+n[1]+n[2]+n[3]+n[4]+n[5] == 0)
			break;
		memset(d, 0, sizeof(d));
		sumv = n[0]+n[1]*2+n[2]*3+n[3]*4+n[4]*5+n[5]*6;
		if(sumv%2 == 1)
		{
			printf("Collection #%d:\nCan't be divided.\n\n", k++);
			continue;
		}
		v = sumv/2;
		for(i=0; i<6; i++)
		{
			if(n[i])
				multbag(i+1, i+1, n[i]);
		}
		if(v == d[v])
			printf("Collection #%d:\nCan be divided.\n\n", k++);
		else
			printf("Collection #%d:\nCan't be divided.\n\n", k++);
	}
	return 0;
}