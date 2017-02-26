#include<iostream>
using namespace std;

class Base
{
    public:
        int b;
        virtual void Test()
        {
            cout<<"Base"<<endl;
        }
};

class Derived:public Base
{
    public:
        int d;
        virtual void Test()
        {
            cout<<"Derived"<<endl;
        }  
};

int main()
{
    Derived d;
    Base b = d;   //直接赋值(产生切割) 
    b.Test();
    
    Base& b2 = d;  //使用引用赋值(不产生切割) 
    b2.Test();
    
    Base* b3 = &d; //使用指针赋值(不产生切割) 
    b3->Test();
    
    system("Pause");
    return 0;
}
