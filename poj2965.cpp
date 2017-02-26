#include<iostream>
#include<vector>
using namespace std;

bool door[6][6]={false};
bool flag=false;
int x[]={1,2,3,4};
int y[]={1,2,3,4};
int step;

struct node
{
    int x;
    int y;
};

vector<node> queue;

bool judge_all()
{
    for(int i=1;i<5;i++)
        for(int j=1;j<5;j++)
            if(door[i][j]!=true)
                return false;
    return true;
}

void flip(int row ,int col)
{
    for(int i=0;i<4;i++)
    {
        door[row][y[i]]=!door[row][y[i]];
        door[x[i]][col]=!door[x[i]][col];
    }
    door[row][col]=!door[row][col];
}

void dfs(int row ,int col ,int deep)
{
    if(step==deep)
    {
        flag=judge_all();
        if(flag)
        {
            cout<<deep<<endl;
            for(int i=0;i<queue.size();i++)
            {
                cout<<queue[i].x<<" "<<queue[i].y<<endl;
            }
            cout<<endl;
        }
        flag=false;
        return;
    }
    if(flag||row==5) return;
    
    flip(row,col);
    node port;
    port.x=row;
    port.y=col;
    queue.push_back(port);
    if(col<4)
        dfs(row,col+1,deep+1);
    else
        dfs(row+1,1,deep+1);
    flip(row,col);
    queue.pop_back();
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
            if(temp=='-')
                door[i][j]=true;
        }
    for(step=0;step<=16;step++)
    {
        dfs(1,1,0);
        if(flag)
            break;
    }
    system("Pause");
    return 0;
}
