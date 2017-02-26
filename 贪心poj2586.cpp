#include<iostream>
using namespace std;

int main()
{
    double s,d;
    while(cin>>s>>d)
    {
        bool flag=false;
        double plus;
        //一个月收入大于4个月亏损 
        if(s>=4*d)
        {
            flag=true;
        }
        //3/2d <= s < 4d           每连续5个月种至少4个月D 
        else if(s>=1.5*d)
        {
            plus = 3*s-9*d;
            if(plus < 0)
                flag=true;
        }
        //2/3d <= s < 3/2d          每连续5个月种至少3个月D
        else if(s>=0.666666*d)
        {
            plus = 6*s-6*d;
            if(plus < 0)
                flag=true;
        }
        //1/4d <= s < 2/3d          每连续5个月种至少2个月D
        else if(s>=0.25*d)
        {
            plus = 8*s-4*d;
            if(plus < 0)
                flag=true;
        }
        //1/4d <= s < 2/3d          每连续5个月种至少2个月D
        else if(s>=0)
        {
            plus = 10*s-2*d;
            if(plus < 0)
                flag=true;
        }
        
        if(flag)
            cout<<"Deficit"<<endl;
        else
            cout<<plus<<endl;
    }
    //system("Pause");
    return 0;
}
