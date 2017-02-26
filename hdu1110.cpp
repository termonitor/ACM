#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

#define PI 3.1415926

int main()
{
	// freopen("test.in", "r", stdin);
	double a, b, x, y;
	int n;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%lf%lf%lf%lf", &a, &b, &x, &y);
		if(a < b)
		{
			double t = b;
			b = a;
			a = t;
		}
		if(x < y)
		{
			double t = x;
			x = y;
			y = t;
		}
		if(a>x && b>y)
			printf("Escape is possible.\n");
		if((a<=x&&b<=y) | (a>x&&b<=y))
			printf("Box cannot be dropped.\n");
		if(a<=x && b>y)
		{
			int flag = 0;
			for(double i=0; i<=90; i+=0.2)
			{
				double rad = PI*i/180;
				if(x*cos(rad)+y*sin(rad)<a && x*sin(rad)+y*cos(rad)<b)
				{
					flag = 1;
					break;
				}
			}
			if(flag)
				printf("Escape is possible.\n");
			else
				printf("Box cannot be dropped.\n");
		}
	}
	return 0;
}