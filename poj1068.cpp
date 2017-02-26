//第一种是我自己写的，主要是字符处理的问题和标识的问题 


#include<iostream>
#include<string>
using namespace std;

int tf[200] = {0};

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int num,old=0,new1;
        int size=0;
        cin>>num;
        for(int i=0;i<num;i++)
        {
            cin>>new1;
            if(i==0)
            {
                old = new1;
                while(new1--)
                {
                    tf[new1] = 0;
                }
                tf[old] = 1;
                size = old+1;
            }else{
                for(int i=0;i<new1-old;i++)
                {
                    tf[size++] = 0;
                }
                tf[size++] = 1;
                old = new1;
            }
        }
        bool flag = false;
        for(int i=0;i<size;i++)
        {
            if(tf[i]==1)
            {
                int count = 0;
                for(int j=i-1;j>=0;j--)
                {
                    if(tf[j]==0)
                    {
                        if(!flag){
                            cout<<1+count;
                            flag = true;
                        }else cout<<" "<<1+count; 
                        tf[j] = 3;
                        break; 
                    } else if(tf[j]==3)
                        count++;
                }
            }
        }
        cout<<endl;
    }
    //system("Pause");
    return 0;
}


//第二种方法思想，算法都很简略 


#include <iostream>
using namespace std;
short a[20];
int main(void)
{
  short n,m,i,j,rightCount,tmp1,tmp2=0;
    cin>>n;
    while(n--)
    { 
       cin>>m;
       tmp2=0;
       for(i=0;i<m;i++){
         cin>>tmp1;
         a[i] = tmp1 - tmp2;
         tmp2 = tmp1; 
         rightCount = 1;           
         for(j=i;j>=0;j--){
           if(a[j]>0){
              a[j]--;
              break;
              }
            else
              rightCount++;
              }
         cout<<rightCount<<" ";
         }
       cout<<endl;
    }
    return 0;
}
