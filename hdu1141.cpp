#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

int main()
{
	// freopen("test.in", "r", stdin);
	int n;
	while(scanf("%d", &n) != EOF)
	{
		if(n == 0)
			break;
		n = (n-1960)/10 + 2;
		double bit = (1<<n)*log(2.0);
		double count = 0;
		int i = 0;
		while(count < bit)
		{
			count += log(++i);
		}
		printf("%d\n", i-1);
	}
	return 0;
}