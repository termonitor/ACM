#include<iostream>
#include<stack>
using namespace std;

stack<int> stk;
char wwf[101];
int pp,qq,rr,ss,tt;

bool judge_variable(char a)
{
    switch(a)
    {
        case 'p':stk.push(pp);return true;
        case 'q':stk.push(qq);return true;
        case 'r':stk.push(rr);return true;
        case 's':stk.push(ss);return true;
        case 't':stk.push(tt);return true;
    }
    return false;
}

void operate(char a)
{
    switch(a)
    {
        case 'K':
            { 
                int x=stk.top();
                stk.pop();
                int y=stk.top();
                stk.pop();
                stk.push(x&&y); 
                break;
            } 
        case 'A':
            {
                int x=stk.top();
                stk.pop();
                int y=stk.top();
                stk.pop();
                stk.push(x||y);
                break;
            }
        case 'N':
            {
                int x=stk.top();
                stk.pop();
                stk.push(!x);
                break;
            }
        case 'C':
            {
                int x=stk.top();
                stk.pop();
                int y=stk.top();
                stk.pop();
                stk.push((!x)||y);
                break;
            }
        case 'E':
            {
                int x=stk.top();
                stk.pop();
                int y=stk.top();
                stk.pop();
                stk.push(x==y); 
                break;
            } 
    }
}

int main()
{
    while(cin>>wwf&&wwf[0]!='0')
    {
        int len=strlen(wwf);
        bool flag=true;
        for(pp=0;pp<2;pp++)
        {
            for(qq=0;qq<2;qq++)
            {
                for(rr=0;rr<2;rr++)
                {
                    for(ss=0;ss<2;ss++)
                    {
                        for(tt=0;tt<2;tt++)
                        {
                            for(int i=len-1;i>=0;i--)
                            {
                                if(!judge_variable(wwf[i]))
                                    operate(wwf[i]);
                            }
                            int ans=stk.top();
                            stk.pop();
                            if(!ans)
                            {
                                flag=false;
                                break;
                            } 
                        }
                        if(!flag)
                            break;
                    }
                    if(!flag)
                        break;
                }
                if(!flag)
                    break;
            }
            if(!flag)
                break;
        }
        if(flag)
            cout<<"tautology"<<endl;
        else cout<<"not"<<endl;
    }
    //system("Pause");
    return 0; 
}
