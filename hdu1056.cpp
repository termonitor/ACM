#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int main()
{
	// freopen("test.in", "r", stdin);
	int j, k, n, m;
	double a, i, s;
	while(scanf("%lf", &a)!=EOF && a)
	{
		s = 0.0;
		for(i=2; ; i++)
		{
			s += 1/i;
			if(s >= a)
			{
				printf("%.0lf card(s)\n", i-1);
				break;
			}
		}
	}
	return 0;
}