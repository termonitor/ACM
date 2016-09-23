#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
//①质量集中在顶点上
//    n个顶点坐标为(xi,yi)，质量为mi，则重心
//　　X = ∑( xi×mi ) / ∑mi
//　　Y = ∑( yi×mi ) / ∑mi
//　　特殊地，若每个点的质量相同，则
//　　X = ∑xi / n
//　　Y = ∑yi / n
//②质量分布均匀
//　　特殊地，质量均匀的三角形重心：
//　　X = ( x0 + x1 + x2 ) / 3
//　　Y = ( y0 + y1 + y2 ) / 3 
//③三角形面积公式：S =  ( (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1) ) / 2 ;
//因此做题步骤：1、将多边形分割成n-2个三角形，根据③公式求每个三角形面积。
//				2、根据②求每个三角形重心。
//	

struct Point
{
	double x, y;
};

double area(Point p1, Point p2, Point p3)
{
	return((p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y))/2;
}

int main()
{
	// freopen("test.in", "r", stdin);
	int t, n, i;
	Point p1, p2, p3;
	double gx, gy, sumarea, temp;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		gx = gy = sumarea = 0;
		scanf("%lf%lf%lf%lf", &p1.x, &p1.y, &p2.x, &p2.y);
		for(i=2; i<n; i++)
		{
			scanf("%lf%lf", &p3.x, &p3.y);
			temp = area(p1, p2, p3);
			gx += (p1.x+p2.x+p3.x)*temp;
			gy += (p1.y+p2.y+p3.y)*temp;
			sumarea += temp;
			p2 = p3;
		}
		gx = gx/sumarea/3;
		gy = gy/sumarea/3;
		printf("%.2lf %.2lf\n", gx, gy);
	}
	return 0;
}