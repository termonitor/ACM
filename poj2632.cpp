#include<iostream>
using namespace std;

int a,b;
int array[101][101];
int xf[4]={-1,0,1,0};
int yf[4]={0,1,0,-1};
struct Robot
{
    int x;
    int y;
    int d;
}robot[101];

bool forward(int s,int t)
{
    int x,y;
    int d = robot[s].d;
    x = robot[s].x;
    y = robot[s].y;
    array[x][y] = 0;
    for(int i=0;i<t;i++)
    {
        x = x + xf[d];
        y = y + yf[d];
        if(x<1 || x>a || y<1 || y>b)
        {
            cout<<"Robot "<<s<<" crashes into the wall"<<endl;
            return true;
        }
        if(array[x][y])
        {
            cout<<"Robot "<<s<<" crashes into robot "<<array[x][y]<<endl;
            return true;
        }
    }
    robot[s].x = x;
    robot[s].y = y;
    array[x][y] = s;
    return false;
}

bool action(int s,char dir,int t)
{
    switch(dir)
    {
        case 'F':return forward(s,t);
        case 'L':robot[s].d = (robot[s].d-t%4+4)%4;break;
        case 'R':robot[s].d = (robot[s].d+t%4)%4;break;
    }
    return false;
}

int main()
{
    //freopen("in.txt","r",stdin);
    int n,m,x1,y1,s,t;
    char dir;
    int k;
    cin>>k;
    while(k--)
    {
        memset(array,0,sizeof(int)*101*101);
        memset(robot,0,sizeof(Robot)*101);
        cin>>a>>b;
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            cin>>x1>>y1>>dir;
            array[x1][y1] = i+1;
            robot[i+1].x = x1;
            robot[i+1].y = y1;
            switch(dir)
            {
                case 'W':robot[i+1].d = 0;break;
                case 'N':robot[i+1].d = 1;break;
                case 'E':robot[i+1].d = 2;break;
                case 'S':robot[i+1].d = 3;break;
                default:robot[i+1].d = -1;
            }
        }
        bool f = false;
        for(int i=0;i<m;i++)
        {
            cin>>s>>dir>>t;
            if(!f) f=action(s,dir,t);
        }
        if(!f) cout<<"OK"<<endl;
    }
    //system("Pauses");
    return 0;
}



