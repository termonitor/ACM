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
            for(int i=1;i<=n-1;i++)//主要针对由i到j的松弛,最终任意两点间的权值都会被分别松弛为最大跳的最小（但每个两点的最小不一定相同）
                for(int j=i+1;j<=n;j++)
                {
                    if(path[i][k]<path[i][j] && path[k][j]<path[i][j])//当边ik,kj的权值都小于ij时，则走i->k->j路线，否则走i->j
                    {
                        if(path[i][k]<path[k][j])//当走i->k->j路线时，选择max{ik,kj},只有选择最大跳才能保证连通  
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


/*
input
2
0 0
3 4

3
17 4
19 4
18 5
8
1 1
4 0
1 2
2 2
3 2
4 2
3 0
5 1
3
9 10
10 10
100 10
6
5 5
100 100
4 4
3 3
2 2
1 1
5
1 2
2 1
3 2
4 1
5 2
3
999 999
1 1
3 3
0
output
Scenario #1
Frog Distance = 5.000

Scenario #2
Frog Distance = 1.414

Scenario #3
Frog Distance = 1.414

Scenario #4
Frog Distance = 1.000

Scenario #5
Frog Distance = 134.350

Scenario #6
Frog Distance = 1.414

Scenario #7
Frog Distance = 1408.557
*/