#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

struct node
{
	int num;
	int prior;
};

bool cmp(node a, node b)
{
	if(a.prior == -1)
		return false;
	if(b.prior == -1)
		return true;
	if(a.prior == b.prior)
	{
		return a.num < b.num;
	}
	return a.prior > b.prior;
}

int main()
{
	// freopen("test.in", "r", stdin);
	int n;
	node a[2005];
	node b[2005];
	node c[2005];
	int al, bl, cl;
	int sum;
	while(scanf("%d", &n) != EOF)
	{
		string command;
		int A, B;
		al=bl=cl=0;
		sum = 0;
		for(int i=0; i<2005; i++)
		{
			a[i].prior = -1;
			b[i].prior = -1;
			c[i].prior = -1;
		}
		while(n--) {
			cin>>command;
			if(command == "IN")
			{
				scanf("%d%d", &A, &B);
				if(A == 1)
				{
					a[al].num = sum;
					a[al].prior = B;
					al++;
					sum++;
				} else if(A == 2)
				{
					b[bl].num = sum;
					b[bl].prior = B;
					bl++;
					sum++;
				} else if(A == 3)
				{
					c[cl].num = sum;
					c[cl].prior = B;
					cl++;
					sum++;
				}
			} else if(command == "OUT")
			{
				scanf("%d", &A);
				if(A == 1)
				{
					if(al==0)
					{
						printf("EMPTY\n");
						continue;
					}
					sort(a, a+al, cmp);
					printf("%d\n", a[0].num+1);
					a[0].prior = -1;
					sort(a, a+al, cmp);
					al--;
				} else if(A == 2)
				{
					if(bl==0)
					{
						printf("EMPTY\n");
						continue;
					}
					sort(b, b+bl, cmp);
					printf("%d\n", b[0].num+1);
					b[0].prior = -1;
					sort(b, b+bl, cmp);
					bl--;
				} else if(A == 3)
				{
					if(cl==0)
					{
						printf("EMPTY\n");
						continue;
					}
					sort(c, c+cl, cmp);
					printf("%d\n", c[0].num+1);
					c[0].prior = -1;
					sort(c, c+cl, cmp);
					cl--;
				}
			}
		}
	}
	return 0;
}