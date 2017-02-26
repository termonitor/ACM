#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
	int n;
	int cas;
	while(scanf("%d", &n) != EOF)
	{
		if(n == 0)
			break;
		cas = 0;
		while(n--)
		{
			int a, b;
			double c;
			scanf("%d%d", &a, &b);
			cas++;
			printf("Scenario #%d:\n", cas);
			if(a%2==0 || b%2== 0)
			{
				c = a*b;
				printf("%.2lf\n", c);
			} else
			{
				c = a*b-1+sqrt(2);
				printf("%.2lf\n", c);
			}
			printf("\n");
		}
	}
	return 0;
}