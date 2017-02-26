#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<ctime>

using namespace std;

/*
	随机算法
*/

const int MX = 1505;
const int INF = 0x3f3f3f3f;
const double exps = 1e-3;
const double pi = acos(-1.0);

double fx[MX], fy[MX], best[MX];
double PX[MX], PY[MX];

double Rand(double L, double R)
{
	return (rand()%10000)/10000.0*(R-L)+L;
}

double dist(double x1, double y1, double x2, double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}


int main()
{
	// freopen("test.in", "r", stdin);
	int T, X, Y, n;
	scanf("%d", &T);
	srand(time(NULL));
	while(T--)
	{
		scanf("%d%d%d", &X, &Y, &n);
		for(int i=1; i<=n; i++)
		{
			scanf("%lf%lf", &PX[i], &PY[i]);
		}
		for(int i=1; i<=30; i++)
		{
			fx[i] = Rand(1, X);
			fy[i] = Rand(1, Y);
			best[i] = INF;
			for(int j=1; j<=n; j++)
			{
				//评估函数，靠它来评估整个退火过程的好坏
				best[i] = min(best[i], dist(fx[i], fy[i], PX[j], PY[j]));
			}
		}
		double step = max(X, Y);	
		while(step > exps)
		{
			for(int i=1; i<=30; i++)
			{
				for(int j=1; j<=30; j++)
				{
					//枚举任何角度，使得到的新点向四周扩散
					double angel = Rand(0, 2*pi);
					double nx = fx[i] + cos(angel)*step;
					double ny = fy[i] + sin(angel)*step;
					if(nx<0 || nx>X || ny<0 || ny>Y)
						continue;
					double d = INF;
					for(int k=1; k<=n; k++)
					{
						d = min(d, dist(nx, ny, PX[k], PY[k]));
					}
					if(d > best[i])
					{
						best[i] = d;
						fx[i] = nx;
						fy[i] = ny;
					}
				}
			}
			//退火，常数
			step *= 0.85;
		}
		int t = 1;
		for(int i=1; i<=30; i++)
		{
			if(best[i] >= best[t])
				t = i;
		}
		printf("The safest point is (%.1lf, %.1lf).\n", fx[t], fy[t]);
	}
	return 0;
}