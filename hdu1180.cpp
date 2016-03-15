#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

const int maxn=21;
int m, n;
char map[maxn][maxn];
int status[maxn][maxn];
int sx, sy, dx, dy;
int tempx[4] = {0, 0, 1, -1};
int tempy[4] = {1, -1, 0, 0};

struct node
{
    int x, y, step;
    bool operator<(const node &a) const
    {
        return a.step < step;
    }
}init;

bool judge(node no)
{
    if(no.x<0 || no.x>=n || no.y<0 || no.y>=m || map[no.x][no.y]=='*' || (status[no.x][no.y]&&no.step>=status[no.x][no.y]))
        return false;
    return true; 
}

int bfs()
{
    init.x = sx;
    init.y = sy;
    init.step = 0;
    status[init.x][init.y] = 1;
    priority_queue<node> pq;
    while(!pq.empty())
        pq.pop();
    pq.push(init);
    while(!pq.empty())
    {
        node past = pq.top();
        node now;
        pq.pop();
        for(int i=0; i<4; i++)
        {
            now.x = past.x + tempx[i];
            now.y = past.y + tempy[i];
            now.step = past.step + 1;
            if(!judge(now))
                continue;
            if(map[now.x][now.y] == '|')
            {
                if(now.x==past.x && (past.step&1)==0)
                    now.step += 1;
                else if(now.y==past.y && (past.step&1)==1)
                    now.step += 1; 
                now.x += tempx[i];
                now.y += tempy[i];
            }
            else if(map[now.x][now.y] == '-')
            {
                if(now.x==past.x && (past.step&1)==1)
                    now.step += 1;
                else if(now.y==past.y && (past.step&1)==0)
                    now.step += 1;
                now.x += tempx[i];
                now.y += tempy[i];
            }   
            if(!judge(now))
                continue;
            if(map[now.x][now.y] == 'T')
                return now.step;
            status[now.x][now.y] = now.step;
            pq.push(now);
        }   
    }
    return 0;
}

int main()
{
//    freopen("test.in", "r", stdin);
    while(~scanf("%d%d", &n, &m))
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin>>map[i][j];
                if(map[i][j] == 'S')
                {
                    sx = i;
                    sy = j;   
                }   
                if(map[i][j] == 'T')
                {
                    dx = i;
                    dy = j;
                }
            }   
        }
        memset(status, 0, sizeof(status));
        int ans = bfs();
        printf("%d\n", ans);
    }
    return 0;   
}
