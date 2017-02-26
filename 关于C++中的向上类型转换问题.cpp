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
    Base b = d;   //ֱ�Ӹ�ֵ(�����и�) 
    b.Test();
    
    Base& b2 = d;  //ʹ�����ø�ֵ(�������и�) 
    b2.Test();
    
    Base* b3 = &d; //ʹ��ָ�븳ֵ(�������и�) 
    b3->Test();
    
    system("Pause");
    return 0;
}
