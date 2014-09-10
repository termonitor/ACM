#include<iostream>
using namespace std;

int n,m;
int price[101][101];//价格和优惠价 
int lv[101];//等级 
int x[101];//替代物数量 

int dis[101];
bool visit[101];

int dijkstra()
{
    int node;//记录与当前源点距离最短的点 
    int sd;//记录最短路径 
    
    for(int i=1;i<=n;i++)
        dis[i] = price[0][i];
    for(int i=1;i<=n;i++)
    {
        node = 0;
        sd = INT_MAX;
        for(int j=1;j<=n;j++)
        {
            if(!visit[j] && sd > dis[j])
            {
                sd = dis[j];
                node = j;
            }
        } 
        if(node == 0)//若node没有变化，说明所有点都被访问，最短路寻找完毕  
            break;
        visit[node] = true;
        for(int j=1;j<=n;j++)
        {
            if(!visit[j] && price[node][j]>0 && dis[j] > dis[node]+price[node][j])
                dis[j] = dis[node]+price[node][j]; 
        }
    } 
    return dis[1];
}

int main()
{
    cin>>m>>n;
    memset(price,0,sizeof(price));
    memset(lv,0,sizeof(lv));
    memset(x,0,sizeof(x));
    memset(dis,INT_MAX,sizeof(dis));
    memset(visit,false,sizeof(visit));
    
    for(int i=1;i<=n;i++)
    {
        cin>>price[0][i]>>lv[i]>>x[i];
        for(int j=0;j<x[i];j++)
        {
            int t,u;
            cin>>t>>u;
            price[t][i] = u;
        } 
    }
    
    int temp_price;
    int maxlv;
    int minprice = INT_MAX;
    
    for(int i=1;i<=n;i++)
    {
        maxlv = lv[i];
        for(int j=1;j<=n;j++)
        {
            if(maxlv<lv[j] || maxlv-lv[j] > m)
            {
                visit[j] = true;
            }
            else
                visit[j] = false;
        }
        temp_price = dijkstra();
        
        if(temp_price < minprice)
            minprice = temp_price;
    }
    
    cout<<minprice<<endl;
    
    system("Pause");
    return 0;
}
