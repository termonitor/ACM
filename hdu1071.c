#include<stdio.h>

int main()
{
	int n;
	double x1, y1;
	double x2, y2;
	double x3, y3;
	double k, t, a, b, c;
	double area;
	while(scanf("%d", &n) != EOF)
	{
		while(n--)
		{
			scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
			k = (y3-y2) / (x3-x2);
			t = y2 - k*x2;
			a = (y2-y1) / (x2*x2-x1*x1-2*x1*x2+2*x1*x1);
			b = 0 - 2*a*x1;
			c = y1 - a*x1*x1 - b*x1;
			// printf("%lf %lf %lf %lf %lf\n", k, t, a, b, c);
			area = a*(x3*x3*x3-x2*x2*x2)/3 + (b-k)*(x3*x3-x2*x2)/2 + (c-t)*(x3-x2);
			printf("%.2lf\n", area);
		}
	}

	return 0;
}