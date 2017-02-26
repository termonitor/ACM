#include<iostream>
#include<stack>
using namespace std;

#define INFINITE 1000 //���ֵ 
#define MAX_VERTEX_COUNT 20 //��󶥵����

struct Graph
{
    int g[MAX_VERTEX_COUNT][MAX_VERTEX_COUNT];//�ڽӾ���
    int count; //��������
    int edgecount; //���� 
};
//����ͼ������ 
void readGraphData(Graph *myGraph)
{
    cout<<"�����붥�������ͱߵ�����: ";
    cin>>myGraph->count;
    cin>>myGraph->edgecount;
    
    cout<< "�������ڽӾ�������:" <<endl;
    
    for(int row=0;row<myGraph->count;row++)
    {
        for(int col=0;col<myGraph->count;col++)
        {
            cin>>myGraph->g[row][col]; 
        }
    }
}

//���ĵ�Floyd�㷨
void floyd(int dis[][MAX_VERTEX_COUNT],int Path[][MAX_VERTEX_COUNT],int count)
{
    //�ȳ�ʼ��Path����
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
//������
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
                if(INFINITE == dis[i][j])  //i->j������·��
                {
                    cout<<"INFINITE"<<endl; 
                } 
                else
                {
                    cout<<dis[i][j]<<"\t\t";
                    // �������ǲ�ѯ���·���ǴӺ���ǰ�壬������ǰѲ�ѯ�õ��Ľڵ�
                    // ѹ��ջ�У���󵯳���˳����������
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
