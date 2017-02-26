#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

int main()
{
	// freopen("test.in", "r", stdin);
	int n;
	double x, y;
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
	{
		cin>>x>>y;
		double dis = sqrt(x*x+y*y);
		const double speed = 50;
		const double pi = 3.1415926;
		printf("Property %d: This property will begin eroding in year %d.\n", i, int(pi*dis*dis/speed/2.0+1));
	}
	printf("END OF OUTPUT.\n");
	return 0;
}