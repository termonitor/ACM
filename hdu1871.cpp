#include<iostream>
#include<algorithm>

using namespace std;

struct node
{
	int idx;//序号
	int l;	//人数
	int c;	//费用
} d[1010];

bool cmp(node a, node b)
{
	if(a.c < b.c)
		return true;
	if(a.c == b.c)
		if(a.l > b.l)
			return true;
	return false;
}

int main()
{
	// freopen("test.in", "r", stdin);
	int T;
	scanf("%d", &T);

	int C;
	while(T--)
	{
		scanf("%d", &C);
		for(int i=0; i<C; i++)
			scanf("%d%d%d", &d[i].idx, &d[i].l, &d[i].c);
		int t;
		scanf("%d", &t);
		int p;
		sort(d, d+C, cmp);
		while(t--)
		{
			scanf("%d", &p);
			int flag = 0;
			for(int i=0; i<C; i++)
			{
				if(d[i].l >= p)
				{
					d[i].l -= p;
					printf("%d\n", d[i].idx);
					flag = 1;
					break;
				}
			}
			if(!flag)
				printf("sorry\n");
		}
	}
	return 0;
}