#include<iostream>
using namespace std;

struct node
{
    int s;//��� 
    int d;//�յ� 
    int p;//Ȩֵ 
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
                //�ɳ� 
            }
        }
        if(!flag)
            break;
        //ֻҪ��ĳһ��û�и���dis���飬��˵�����·���Ѿ�������ϣ����߲��ֵ㲻�ɴ�������� �ɳ� 
    }      
    //��������Ĳ��裬һ�������dis�����д�ŵĶ������·��
    //so������ڼ�����С�����������Ϊ��·���������� 
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
        memset(dis,0,sizeof(dis));
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
            //ע��Ϊ��ֵ 
        }
        
        if(bellman())
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    //system("Pause");
    return 0;
}
