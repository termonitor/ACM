#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

int main()
{
    int t;  
    double h1,r1,x1,y1,z1;  
    double h2,r2,x2,y2,z2;  
    double x3,y3,z3;  
    double x,y,z;  
    double dis,a,b,c;  
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf%lf%lf%lf",&h1,&r1,&x1,&y1,&z1);  
        scanf("%lf%lf%lf%lf%lf",&h2,&r2,&x2,&y2,&z2);  
        scanf("%lf%lf%lf",&x3,&y3,&z3);
        z1 = z1+h1-r1;  // 匪头部z轴坐标 
        z2 = z2+h2*0.9-r2;  //警头部z轴坐标
        
        x = x1-x2;
        y = y1-y2;
        z = z1-z2;
        
        a = y*z3-z*y3;
        b = z*x3-x*z3;
        c = x*y3-y*x3;
        dis = sqrt((a*a+b*b+c*c)/(x3*x3+y3*y3+z3*z3));
        if(dis<=r1&&(x*x3+y*y3+z*z3>0))
            printf("YES\n");
        else
            printf("NO\n"); 
    }
//    system("Pause");
    return 0;   
}
