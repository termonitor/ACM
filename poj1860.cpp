#include<iostream>
using namespace std;

int n;//�������� 
int m;//�һ������� 
int s;//���е�s�ֻ��� 
double v;//���е�s���ҵı���

int all;//�ܱ���
double dis[101];//s�������Ȩֵ

struct exchange_points
{
    int a;//����a 
    int b;//����b 
    double r;//rate 
    double c;//������ 
}exc[202];

bool bellman()
{
    memset(dis,0,sizeof(dis)); //������bellman��Ŀ�ĸպ��෴����ʼ��ΪԴ�㵽�����������С
    dis[s] = v;   //��bellman�������Ҹ���������С·��������������ͬ����˼���������������·��  
    
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
