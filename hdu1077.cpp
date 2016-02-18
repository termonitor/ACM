#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

const double eps = 1e-6;
const int MAXN = 305;

struct point
{
	double x, y;
};
struct point ps[MAXN];

int N;

double get_dis(int a, int b)
{
	return (ps[a].x-ps[b].x)*(ps[a].x-ps[b].x)+(ps[a].y-ps[b].y)*(ps[a].y-ps[b].y);
}

void get_center(int a, int b)
{
	double ox, oy, dx, dy, r, temp;
	ox = (ps[a].x+ps[b].x)/2;
	oy = (ps[a].y+ps[b].y)/2;
	dx = ps[b].x-ps[a].x;
	dy = ps[b].y-ps[a].y;
	ps[N].x =ox;
	ps[N].y = oy;
	temp = get_dis(N, b);
	r = sqrt(1.0-temp);
	if(fabs(dx) < eps)
		ps[N].x -= r;
	else
	{
		double ang = atan(-dy/dx);
		ps[N].x -= r*sin(ang);
		ps[N].y -= r*cos(ang);
	}	
}

int main()
{
	// freopen("test.in", "r", stdin);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &N);
		for(int i=0; i<N; i++)
			scanf("%lf%lf", &ps[i].x, &ps[i].y);
		int ans = 1;
		int max1, k;
		for(int i=0; i<N; i++)
		{
			for(int j=i+1; j<N; j++)
			{
				if(get_dis(i, j) >= 4)
					continue;
				get_center(i, j);
				for(k=0, max1=0; k<N; k++)
				{
					if(N-k+max1 <= ans)
						break;
					double temp = sqrt(get_dis(k, N));
					if(temp <= 1.000001)
						max1++;
				}
				if(max1 > ans)
					ans = max1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}