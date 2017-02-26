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
   // freopen("in.txt","r",stdin);
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
            //此处必须取一个最大值，因为如果不采用最大值的方法，可能导致maxlv两端的值大于等级差，从而导致错误
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
   // while(true); 
   // system("Pause");
    return 0;
}

//测试数据中5能够反映等级问题，表明必须对每个点都取一次最短路径
/*
    测试数据1:  
    1 4  
    10000 3 2  
    2 8000  
    3 5000  
    1000 2 1  
    4 200  
    3000 2 1  
    4 200  
    50 2 0  
      
    5250  
      
    测试数据2:  
    1 5  
    10000 3 4  
    2 3000  
    3 2000  
    4 2000  
    5 9000  
    8000 2 3  
    3 5000  
    4 2000  
    5 7000  
    5000 1 0  
    2000 4 1  
    5 1900  
    50 1 0  
      
    4000  
    测试数据3:  
    3 8  
    10000 3 6  
    2 3000  
    3 2000  
    4 2000  
    5 9000  
    7 1000  
    8 5008  
    8000 2 3  
    3 5000  
    4 2000  
    5 7000  
    5000 1 1  
    6 1000  
    2000 4 1  
    5 1900  
    50 1 0  
    5000 1 1  
    7 4007  
    2000 4 1  
    5 1900  
    80 3 0  
      
    2950  
    测试数据4:  
    1 10  
    1324 0 0  
    1234 0 0  
    255 0 0  
    67 0 0  
    56 0 0  
    2134 0 0  
    456 0 0  
    2345 0 0  
    67 0 0  
    6436 0 0  
      
    1324  
      
    测试数据5:  
    1 4  
    10000 3 2  
    2 1  
    3 3  
    1000 2 2  
    4 1  
    3 1  
    1000 3 1  
    4 2  
    100 4 0  
      
    105  
    测试数据6:  
    3 5  
    10000 3 4  
    2 3000  
    3 2000  
    4 2000  
    5 9000  
    8000 2 3  
    3 5000  
    4 2000  
    5 7000  
    5000 1 0  
    2000 4 1  
    5 1900  
    50 1 0  
      
    3950  
    测试数据7:  
    0 5  
    10000 3 4  
    2 3000  
    3 2000  
    4 2000  
    5 9000  
    8000 2 3  
    3 5000  
    4 2000  
    5 7000  
    5000 4 0  
    2000 3 1  
    5 1900  
    50 2 0  
      
    4000 
*/
