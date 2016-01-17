#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	//(天数+月份)是偶数时胜，奇数时负。特殊的诗9月30与11月30，也是胜的
	int T;
	int y, m, d;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d%d", &y, &m, &d);
		if((d+m)%2==0 || (m==9&&d==30) || (m==11&&d==30))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}