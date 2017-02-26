#include<iostream>
#include<map>
#include<string>
using namespace std;

const int inf=10000;

int n,m;
map<string,int> currency;
double rate;
double dis[31][31];

void floyd()
{
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(dis[i][j] < dis[i][k]*dis[k][j])
                    dis[i][j] = dis[i][k]*dis[k][j];
}

int main()
{
    int case1 = 0;
//    freopen("in.txt","r",stdin);
    while(cin>>n && n!=0)
    {
        case1++;
        memset(dis,inf,sizeof(dis));
        for(int i=1;i<=n;i++)
        {
            string str;
            cin>>str;
            currency[str] = i;
            dis[i][i] = 1;
        }
        
        cin>>m;
        for(int i=1;i<=m;i++)
        {
            string str1,str2;
            cin>>str1>>rate>>str2;
            dis[currency[str1]][currency[str2]] = rate;   
        }
        
        floyd();
        
        bool flag = false;
        for(int i=1;i<=n;i++)
            if(dis[i][i]>1)
            {
                flag=true;
                break;
            }
        if(flag)
            cout<<"Case "<<case1<<": Yes"<<endl;
        else
            cout<<"Case "<<case1<<": No"<<endl;
    }
//    while(1);
    system("Pause");
    return 0;
}
