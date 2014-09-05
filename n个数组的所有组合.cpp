#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;

int n;
vector<int> stk;

void createvec(vector<vector<int> > &q,string str)
{
     vector<int> vec;
     int num=0;
     for(int i=0;i<str.length();i++)
     {
             if(str[i]==' '){
                   vec.push_back(num);
                   //cout<<num<<"加入"<<endl;
                   num=0;
                   continue;       
             }
             num *= 10;
             num += str[i]-'0';                             
     }
     if(num != 0)
     {
            vec.push_back(num);
            //cout<<num<<"加入"<<endl;
            num=0;
     }
     sort(vec.begin(),vec.end());
     q.push_back(vec);
}

void stk_cz(vector<vector<int> > a,int m)
{
     if(m>n-1)
     {
            for(int i=0;i<n;i++)
                    cout<<stk[i]<<" ";  
            cout<<endl;
            return;
     }
     for(int i=0;i<a[m].size();i++)
     {
             stk.push_back(a[m][i]);
             stk_cz(a,m+1);
             stk.pop_back();        
     }
}

int main()
{
    while(cin>>n)
    {
                 cout<<"input:"<<endl;
                 cin.sync();
                 vector<vector<int> > que;
                 for(int i=0;i<n;i++)
                 {
                         string str;
                         getline(cin,str);
                         createvec(que,str);
                 }
                 stk_cz(que,0);
    }   
}


