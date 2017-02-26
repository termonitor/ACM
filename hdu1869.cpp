#include<iostream>
using namespace std;

const int inf=1000;
int n,m;
int path[102][102];

int main()
{
    while(cin>>n>>m)
    {
        //memset(path,inf,sizeof(path));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(i==j)
                    path[i][j] = 0;
                else
                    path[i][j] = 1000;
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            path[a][b] = path[b][a] = 1;
        }
        for(int k=0;k<n;k++)
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    if(path[i][j] > path[i][k]+path[k][j])
                        path[i][j] = path[i][k]+path[k][j];
        bool flag = false;
        for(int i=0;i<n;i++)
            for(int j=0;j<i;j++)
                if(path[i][j]>7)
                {
                    flag = true;
                    break;
                }
        if(!flag)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    //system("Pause");
    return 0;
}
