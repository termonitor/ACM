/*
    @题目
    1~9的9个数字，每个数字只能出现一次，要求这样一个9位整数：第一位能被1整除
    前两位能被2整除，前三位能被3整除……以此类推，前9位能被9整除。
    @答案
    381654729
*/
#include<iostream>
#include<vector>
using namespace std;

bool used[10];
vector<long long> v;
void dfs(int k,long long a)
{
    if(k && a%k!=0)
        return;
    if(k == 9)
    {
        v.push_back(a);
        return;
    }
    for(int i=1;i<=9;i++)
        if(!used[i])
        {
            used[i] = 1;
            dfs(k+1,a*10+i);
            used[i] = 0;
        }
}

int main()
{
    dfs(0,0);
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<endl;
    system("Pause");
    return 0;
}
