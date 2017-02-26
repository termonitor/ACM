#include<iostream>
using namespace std;
struct S
{
    int i;
    int *p;
};
int main()
{
    S s;
    int *p = &s.i;
    p[0] =1;
    p[1] =5;
    cout<<p[0]<<" "<<s.i<<endl;
    cout<<&p[0]<<" "<<&s.i<<endl;
    cout<<p[1]<<" "<<s.p<<" "<<endl;
    cout<<endl;
    
    s.p = p;
    cout<<p[0]<<" "<<s.i<<endl;
    cout<<&p[0]<<" "<<&s.i<<endl;
    cout<<p[1]<<" "<<s.p<<" "<<s.p[1]<<endl;
    cout<<&p[1]<<" "<<&s.p<<" "<<&s.p[1]<<endl;
    cout<<endl;
    
    s.p[1] = 1;
    cout<<s.p<<" "<<&s.p<<" "<<endl; 
     
    system("Pause");
    return 0;
}
