#include<iostream>
#include<stack>
using namespace std;

#define INFINITE 1000 //最大值 
#define MAX_VERTEX_COUNT 20 //最大顶点个数

struct Graph
{
    int g[MAX_VERTEX_COUNT][MAX_VERTEX_COUNT];//邻接矩阵
    int count; //顶点数量
    int edgecount; //边数 
};
//读入图的数据 
void readGraphData(Graph *myGraph)
{
    cout<<"请输入顶点数量和边的数量: ";
    cin>>myGraph->count;
    cin>>myGraph->edgecount;
    
    cout<< "请输入邻接矩阵数据:" <<endl;
    
    for(int row=0;row<myGraph->count;row++)
    {
        for(int col=0;col<myGraph->count;col++)
        {
            cin>>myGraph->g[row][col]; 
        }
    }
}

//核心的Floyd算法
void floyd(int dis[][MAX_VERTEX_COUNT],int Path[][MAX_VERTEX_COUNT],int count)
{
    //先初始化Path数组
    for(int i=0;i<count;i++)
        for(int j=0;j<count;j++)
            Path[i][j] = i;
    
    for(int k=0;k<count;k++)
        for(int i=0;i<count;i++)
            for(int j=0;j<count;j++) 
            {
                if(dis[i][j]>dis[i][k]+dis[k][j])
                {
                    dis[i][j] = dis[i][k]+dis[k][j];
                    Path[i][j] = Path[k][j];
                }
            }
}
//输出结果
void printResult(int dis[][MAX_VERTEX_COUNT],int Path[][MAX_VERTEX_COUNT],int count)
{
    cout<<"Origin -> Dest   Distance    Path"<<endl;
    for(int i=0;i<count;i++)
    {
        for(int j=0;j<count;j++)
        {
            if(i!=j)
            {
                cout<<i+1<< " -> "<<j+1<<"\t\t";
                if(INFINITE == dis[i][j])  //i->j不存在路径
                {
                    cout<<"INFINITE"<<endl; 
                } 
                else
                {
                    cout<<dis[i][j]<<"\t\t";
                    // 由于我们查询最短路径是从后往前插，因此我们把查询得到的节点
                    // 压入栈中，最后弹出以顺序输出结果。
                    stack<int> s;
                    int k=j;
                    
                    do
                    {
                        k = Path[i][k];
                        s.push(k);
                    }while(k!=i);
                    
                    cout<<s.top()+1;
                    s.pop();
                    
                    int length = s.size();
                    for(int index=0;index<length;index++)
                    {
                        cout<<" -> "<<s.top()+1;
                        s.pop();
                    } 
                    cout<<" -> "<<j+1<<endl;
                }
            } 
        }
    }
}

int main()
{
    Graph myGraph;
    readGraphData( &myGraph );
    
    int dis[MAX_VERTEX_COUNT][MAX_VERTEX_COUNT];
    int Path[MAX_VERTEX_COUNT][MAX_VERTEX_COUNT];
    
    for(int i=0;i<myGraph.count;i++)
        for(int j=0;j<myGraph.edgecount;j++)
            dis[i][j] = myGraph.g[i][j];
    
    floyd(dis,Path,myGraph.count);
    
    printResult(dis,Path,myGraph.count);
    system("Pause");
    return 0;
}   


/*
input:
    4 8
    1000 5 1000 1000
    50 1000 15 5
    30 1000 1000 15
    15 1000 5 1000
*/
