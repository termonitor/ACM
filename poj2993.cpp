#include<iostream>
#include<string>
using namespace std;

string edge = "+---+---+---+---+---+---+---+---+";
string chess[8];

void output()
{
    for(int i=0;i<8;i++)
    {
        cout<<edge<<endl;
        cout<<chess[i]<<endl;
    }
    cout<<edge<<endl;
}

int main()
{
    //³õÊ¼»¯
    for(int i=0;i<8;i+=2)
        chess[i] = "|...|:::|...|:::|...|:::|...|:::|"; 
    for(int i=1;i<8;i+=2)
        chess[i] = "|:::|...|:::|...|:::|...|:::|...|";
    
   // freopen("in.txt","r",stdin);
    string flag,wcontent,bcontent;
    cin>>flag>>wcontent;
    cin>>flag>>bcontent;
    int x,y;
    char temp;
    int count = 0;
    //×Ö·û²Ù×÷
    for(int i=0;i<wcontent.length();i++)
    {
        if(wcontent[i]==',')
        {
            if(count==2)
            {
                temp = 'P';
            }
            y = y*4+2;
            chess[x][y] = temp;
            count = 0;
        }
        if(wcontent[i]>='A' && wcontent[i]<='Z')
        {
            temp = wcontent[i];
            count++;
        } 
        else if(wcontent[i]>='a' && wcontent[i]<='h') 
        {
            y = wcontent[i] - 'a';
            count++;
        }
        else if(wcontent[i]>='1' && wcontent[i]<='8')
        {
            x = 8-(wcontent[i] - '0');
            count++;   
        }
    } 
    temp = 'P';
    y = y*4+2;
    chess[x][y] = temp;
    count = 0;
    for(int i=0;i<bcontent.length();i++)
    {
        if(bcontent[i]==',')
        {
            if(count==2)
            {
                temp='p';
            }
            y = y*4+2;
            chess[x][y] = temp;
            count=0; 
        }
        if(bcontent[i]>='A' && bcontent[i]<='Z')
        {
            temp = bcontent[i] + 32;
            count++;
        }
        else if(bcontent[i]>='a' && bcontent[i]<='h')
        {
            y = bcontent[i] - 'a';
            count++;
        }
        else if(bcontent[i]>='1' && bcontent[i]<='8')
        {
            x = 8 - (bcontent[i] - '0');
            count++;
        }
    }
    temp = 'p';
    y = y*4+2;
    chess[x][y] = temp;
    count = 0;
    output();
   // system("Pause");
    return 0;
}
