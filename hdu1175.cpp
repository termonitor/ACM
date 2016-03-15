#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

/*
    g++ 10000MS TLE³¬Ê±
    c++ 9126MS ACÍ¨¹ý 
*/

int map[2050][2050];
int rt;
int n, m;
int t;
int a, b, c, d;
int temp[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void dfs(int x, int y, int t, int f)
{
    if(x==c && y==d && t<=2)
    {
        rt = 1;
        return ;   
    }
    if(t > 2)
        return ;
    map[x][y] = -1;     
    for(int i=0; i<4; i++)
    {
        int tx = x + temp[i][0];
        int ty = y + temp[i][1];
        if(tx>=0 && tx<n && ty>=0 && ty<m && map[tx][ty]==0)
        {
            if(i==f)
                dfs(tx, ty, t, f);
            else
                dfs(tx, ty, t+1, i);   
        }       
    }
    map[x][y] = 0;
    return ;
}

int main()
{
    while(~scanf("%d%d", &n, &m))
    {
        if(n==0 && m==0)
            break;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                scanf("%d", &map[i][j]);   
            }   
        } 
        scanf("%d", &t);
        while(t--)
        {
           scanf("%d%d%d%d", &a, &b, &c, &d);
           a--;
           b--;
           c--;
           d--;
           if(map[a][b] != map[c][d] || map[a][b]==0 || map[c][d]==0)
           {
                printf("NO\n");
                continue;     
           }    
           else
           {
                int tp = map[a][b];
                map[c][d] = 0;
                rt = 0;
                dfs(a, b, -1, -1);
                if(rt)
                    printf("YES\n");
                else
                    printf("NO\n");
                map[c][d] = map[a][b] = tp; 
           }
        }  
    }
//   system("Pause");
    return 0;   
}
