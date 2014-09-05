#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

struct Point
{
    double left,right;
}p[2010],temp;

bool operator <(Point a ,Point b)
{
    return a.left<b.left;
}

int main()
{
    int n;
    double r;
    int a,b;
    int kase=0;
    while(cin>>n>>r&&(n||r))
    {
        bool flag=false;
        for(int i=0;i<n;i++)
        {
            double a,b;
            cin>>a>>b;
            if(fabs(b)>r)
                flag=true;
            else
            {
                p[i].left=a*1.0-sqrt(r*r-b*b);
                p[i].right=a*1.0+sqrt(r*r-b*b);
            }
        }
        cout<< "Case "<<++kase<<": ";
        if(flag)
            cout<<-1<<endl;
        else
        {
            int count= 1;
            sort(p,p+n);
            temp=p[0];
            for(int i=1;i<n;i++)
            {
                if(p[i].left>temp.right)
                {
                    count++;
                    temp=p[i];
                }
                else if(p[i].right<temp.right)
                {
                    temp=p[i];
                }
            }
            cout<<count<<endl;
        }
    }  
    //system("Pause");
    return 0;
}
