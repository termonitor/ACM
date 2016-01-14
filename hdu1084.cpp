#include<iostream>
#include<algorithm>

using namespace std;

struct p
{
	int h;
	int m;
	int s;
};
struct grade
{
	int num;
	p time;
	int flag;
	int graded;
};

int cmp(grade a, grade b)
{
	if(a.num != b.num)
		return a.num > b.num;
	else if(a.time.h != b.time.h)
		return a.time.h < b.time.h;
	else if(a.time.m != b.time.m)
		return a.time.m < b.time.m;
	else
		return a.time.s < a.time.s;
}

int cmp1(grade a, grade b)
{
	return a.flag < b.flag;
}

int main()
{
	int n;
	// freopen("test.in", "r", stdin);
	while(scanf("%d", &n))
	{
		if(n == -1)
			break;
		grade a[105];
		int b[10];
		memset(b, 0, sizeof(b));
		for(int i=0; i<n; i++)
		{
			scanf("%d%d:%d:%d", &a[i].num, &a[i].time.h, &a[i].time.m, &a[i].time.s);
			a[i].flag = i;
			b[a[i].num]++;
		}
		sort(a, a+n, cmp);
		int c[10];
		memset(c, 0, sizeof(c));
		for(int i=0; i<n; i++)
		{
			if(a[i].num == 5)
				a[i].graded = 100;
			else if(a[i].num == 4)
			{
				if(b[4] <=1 || c[4] < (b[4]/2))
					a[i].graded = 95;
				else 
					a[i].graded = 90;
				c[4]++;
			}
			else if(a[i].num == 3)
			{
				if(c[3] < (b[3]/2))
					a[i].graded = 85;
				else
					a[i].graded = 80;
				c[3]++;
			}
			else if(a[i].num == 2)
			{
				if(c[2] < (b[2]/2))
					a[i].graded = 75;
				else
					a[i].graded = 70;
				c[2]++;
			}
			else if(a[i].num == 1)
			{
				if(c[1] < (b[1]/2))
					a[i].graded = 65;
				else
					a[i].graded = 60;
				c[1]++;
			}
			else
				a[i].graded = 50;
		}
		sort(a, a+n, cmp1);
		for(int i=0; i<n; i++)
		{
			printf("%d\n", a[i].graded);
		}
		printf("\n");
	}
	return 0;
}