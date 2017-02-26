#include<iostream>
#include<stack>
using namespace std;

#define M 100
#define N 100

typedef struct node
{
    int matrix[N][M];      //�ڽӾ��� 
    int n;                 //������ 
    int e;                 //���� 
}MGraph;

void DijkstraPath(MGraph g,int *dist,int *path,int v0) //v0��ʾԴ���� 
{
    int i,j,k;
    bool *visited = (bool*)malloc(sizeof(bool)*g.n);
    for(i=0;i<g.n;i++)//��ʼ�� 
    {
        if(g.matrix[v0][i]>0 && i!=v0)
        {
            dist[i] = g.matrix[v0][i];
            path[i] = v0;//path��¼���·���ϴ�v0��i��ǰһ������ 
        }
        else
        {
            dist[i] = INT_MAX; //��i��v0�����ڣ�����ȨֵΪ����� 
            path[i] = -1;
        }
        visited[i] = false;
        path[v0] = v0;
        dist[v0] = 0;
    } 
    visited[v0] = true;
    
    for(i=0;i<g.n;i++)
    {
        int min = INT_MAX;
        int u;
        for(j=0;j<g.n;j++)  //Ѱ��δ����չ��Ȩֵ��С�Ķ��� 
        {
            if(visited[j]==false && dist[j]<min)
            {
                min = dist[j];
                u = j;
            }
        }
        visited[u] = true;
        for(k=0;k<g.n;k++)  //����dist�����ֵ��·����ֵ
        {
            if(visited[k]==false && g.matrix[u][k]>0 && min+g.matrix[u][k] < dist[k])
            {
                dist[k] = min+g.matrix[u][k];
                path[k] = u;
            }
        }
    } 
}

void showPath(int *path,int v,int v0)  //��ӡ���·���ϵĸ�������
{
    stack<int> s;
    int u = v;
    while(v != v0)
    {
        s.push(v);
        v = path[v];
    } 
    s.push(v);
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    } 
} 

int main()
{
    int n,e;
    while(cin>>n>>e && e!=0)
    {
        int i,j;
        int s,t,w;   //��ʾ����һ��s->t�ıߣ�ȨֵΪw
        MGraph g;
        int v0;
        int *dist = (int*)malloc(sizeof(int)*n);
        int *path = (int*)malloc(sizeof(int)*n);
        for(i=0;i<N;i++)
            for(j=0;j<M;j++)
                g.matrix[i][j] = 0;
        g.n = n;
        g.e = e;
        for(i=0;i<e;i++)
        {
            cin>>s>>t>>w;
            g.matrix[s][t] = w;
        } 
        
        cin>>v0;   //����Դ����
        DijkstraPath(g,dist,path,v0);
        for(i=0;i<n;i++)
        {
            if(i!=v0)
            {
                showPath(path,i,v0);
                cout<<dist[i]<<endl;
            }
        }
    }
    system("Pause");
    return 0;
}

/*
input:
  5 7
  0 1 100
  0 2 30
  0 4 10
  2 1 60
  2 3 60
  3 1 10
  4 3 50
  0
 output:
  0 4 3 1 70
  0 2 30
  0 4 3 60
  0 4 10    
    
*/ 
