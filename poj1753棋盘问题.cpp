#include<iostream>
using namespace std;

bool flag=false;
int step;
int x[]={1,-1,0,0,0};
int y[]={0,0,1,-1,0};
bool chess[6][6]={false};

bool judge_all()
{
    for(int i=1;i<5;i++)
        for(int j=1;j<5;j++)
            if(chess[i][j]!=chess[1][1])
                return false;
    return true;
}

void flip(int row ,int col)
{
    for(int i=0;i<5;i++)
        chess[row+x[i]][col+y[i]]=!chess[row+x[i]][col+y[i]];
}

void dfs(int row ,int col ,int deep)
{
    if(deep==step)
    {
        flag=judge_all();
        return;
    }
    if(flag||row==5) return;
    
    flip(row,col);
    if(col<4)
        dfs(row,col+1,deep+1);
    else
        dfs(row+1,1,deep+1);
    flip(row,col);
    if(col<4)
        dfs(row,col+1,deep);
    else
        dfs(row+1,1,deep);
}

int main()
{
    char temp;
    for(int i=1;i<5;i++)
        for(int j=1;j<5;j++)
        {
            cin>>temp;
            if(temp=='b')
                chess[i][j]=true;
        }
    for(step=0;step<=16;step++)
    {
        dfs(1,1,0);
        if(flag) break;
    } 
    if(flag)
        cout<<step<<endl;
    else
        cout<<"Impossible"<<endl;
    system("Pause");
    return 0;
}
