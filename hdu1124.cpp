#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

#define e exp(1.0)
#define PI acos(-1.0)
int main()
{
    int T;
    int n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        int cnt5=0;
        int temp;
        temp=n/5;
        while(temp>0)
        {
            cnt5+=temp;
            temp/=5;
        }
        printf("%d\n",cnt5);
    }
    return 0;
}
