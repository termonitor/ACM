#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

struct coordinate
{
    double x,y;
}point[201];
double path[201][201];

int main()
{
    int n;
    int cases=1;
    while(cin>>n)
    {
        if(!n) break;
        for(int i=1;i<=n;i++)
            cin>>point[i].x>>point[i].y;
        for(int i=1;i<=n-1;i++)
            for(int j=i+1;j<=n;j++)
            {
                double x2 = point[i].x - point[j].x;
                double y2 = point[i].y - point[j].y;
                path[i][j] = path[j][i] = sqrt(y2*y2+x2*x2);
            }
        //Floyd
        for(int k=1;k<=n;k++)
            for(int i=1;i<=n-1;i++)//��Ҫ�����i��j���ɳ�,��������������Ȩֵ���ᱻ�ֱ��ɳ�Ϊ���������С����ÿ���������С��һ����ͬ��
                for(int j=i+1;j<=n;j++)
                {
                    if(path[i][k]<path[i][j] && path[k][j]<path[i][j])//����ik,kj��Ȩֵ��С��ijʱ������i->k->j·�ߣ�������i->j
                    {
                        if(path[i][k]<path[k][j])//����i->k->j·��ʱ��ѡ��max{ik,kj},ֻ��ѡ����������ܱ�֤��ͨ  
                            path[i][j]=path[j][i]=path[k][j];
                        else
                            path[i][j]=path[j][i]=path[i][k];
                    }
                }
        cout<<"Scenario #"<<cases++<<endl;
        cout<<fixed<<setprecision(3)<<"Frog Distance = "<<path[1][2]<<endl;
        cout<<endl; 
    } 
    //system("Pause");
    return 0;
}