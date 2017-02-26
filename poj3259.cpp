#include<iostream>
using namespace std;

struct node
{
    int s;//起点 
    int d;//终点 
    int p;//权值 
}edge[5200]; 

int f;
int n,m,w;
int all;
int dis[1001];

bool bellman()
{
    bool flag;
    
    for(int i=1;i<=n-1;i++)
    {
        flag = false;
        for(int j=0;j<all;j++)
        {
            if(dis[edge[j].d] > dis[edge[j].s] + edge[j].p)
            {
                dis[edge[j].d] = dis[edge[j].s] + edge[j].p;
                flag = true;
                //松弛 
            }
        }
        if(!flag)
            break;
        //只要有某一此没有更新dis数组，就说明最短路径已经查找完毕，或者部分点不可达，可以跳出 松弛 
    }      
    //经过上面的步骤，一般情况下dis数组中存放的都是最短路径
    //so如果存在继续减小的情况，则视为负路径（负环） 
    for(int i=0;i<all;i++)
    {
        if(dis[edge[i].d] > dis[edge[i].s] + edge[i].p)
            return true;
    }
    return false; 
}

int main()
{
    int s,e,t;
    cin>>f;
    while(f--)
    {
        memset(dis,INT_MAX,sizeof(dis));
        cin>>n>>m>>w;
        all = 0;
        for(int i=0;i<m;i++)
        {
            cin>>s>>e>>t;
            edge[all].s = s;
            edge[all].d = e;
            edge[all++].p = t;
            edge[all].d = s;
            edge[all].s = e;
            edge[all++].p = t;
        }
        for(int i=0;i<w;i++)
        {
            cin>>s>>e>>t;
            edge[all].s = s;
            edge[all].d = e;
            edge[all++].p = -t;
            //注意为负值 
        }
        
        if(bellman())
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    //system("Pause");
    return 0;
}
