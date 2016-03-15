#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

double x[1000002];
double y[1000002];

int main()
{
    int n;
    while(~scanf("%d", &n) && n)
    {
        for(int i=1; i<=n; i++)
            scanf("%lf%lf", &x[i], &y[i]);
        sort(x+1, x+n+1);
        sort(y+1, y+n+1);
        printf("%.2lf %.2lf\n", x[(n+1)>>1], y[(n+1)>>1]);
    }
    return 0;   
}
