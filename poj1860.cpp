#include<iostream>
using namespace std;

int n;//货币种数 
int m;//兑换点数量 
int s;//持有第s种货币 
double v;//持有的s货币的本金

int all;//总边数
double dis[101];//s到各点的权值

struct exchange_points
{
    int a;//货币a 
    int b;//货币b 
    double r;//rate 
    double c;//手续费 
}exc[202];

bool bellman()
{
    memset(dis,0,sizeof(dis)); //这里与bellman的目的刚好相反。初始化为源点到各点距离无穷小
    dis[s] = v;   //即bellman本用于找负环，求最小路径，本题是利用同样的思想找正环，求最大路径  
    
    bool flag;
    for(int i=1;i<=n-1;i++)
    {
        flag = false;
        for(int j=0;j<all;j++)
        {
            if(dis[exc[j].b] < (dis[exc[j].a]-exc[j].c)*exc[j].r)
            {
                dis[exc[j].b] = (dis[exc[j].a]-exc[j].c)*exc[j].r;
                flag = true;
            }
        }
        if(!flag)
            break;
    }
    
    for(int i=0;i<all;i++)
        if(dis[exc[i].b] < (dis[exc[i].a]-exc[i].c)*exc[i].r)
            return true;
    return false;
}

int main()
{
    int a,b;
    double rab,cab,rba,cba;
    
    while(cin>>n>>m>>s>>v)
    {
        all = 0;
        for(int i=0;i<m;i++)
        {
            cin>>a>>b>>rab>>cab>>rba>>cba;
            exc[all].a = a;
            exc[all].b = b;
            exc[all].r = rab;
            exc[all++].c = cab;
            exc[all].a = b;
            exc[all].b = a;
            exc[all].r = rba;
            exc[all++].c = cba;
        }
        
        if(bellman())
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }    
    //system("Pause");
    return 0;
}
