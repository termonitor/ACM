#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<queue>

using namespace std;

const char ss[32]={11,12,13,14,15,16,17,0,21,22,23,24,25,26,27,0,31,32,33,34,35,36,37,0,41,42,43,44,45,46,47,0};

string aim="";

struct node
{
	int x, y;
};

char m[4][8];

struct state
{
	node pos[50], blank[4];
	string s;
	int lvl;
};

string m2s()
{
	string now="";
	int i, j;
	for(i=0; i<4; i++)
		for(j=0; j<8; j++)
			now.push_back(m[i][j]);
	return now;
}

int get_hash(string s)
{
	long long ans = 0;
	for(int i=0; i<32; i++)
		ans = (ans<<1)+s[i];
	return ans%999991;
}

bool vis[1000000];
queue<state> q;
state now, next_;
node temp;
int bfs()
{
	memset(vis, 0, sizeof(vis));
	while(!q.empty())
		q.pop();
	int i, j, t=0, k, o, lvl;
	for(i=0; i<4; i++)
		for(j=0; j<8; j++)
		{
			temp.x = i;
			temp.y = j;
			if(m[i][j] == 0)
				now.blank[t++] = temp;
			else
				now.pos[m[i][j]] = temp;
		}
	now.s = m2s();
	vis[get_hash(now.s)] = 1;
	now.lvl = 1;
	q.push(now);
	int Aim = get_hash(aim);
	while(!q.empty()&&!vis[Aim])
	{
		now = q.front();
		q.pop();
		next_ = now;
		next_.lvl = now.lvl+1;
		for(i=0; i<4; i++)
		{
			node &b = next_.blank[i];
			o = 8*b.x + b.y - 1;
			t = next_.s[o];
			if(t%10 == 7 || t==0)
				continue;
			k = t+1;
			node &p = next_.pos[k];
			k = p.x*8 + p.y;
			o++;
			swap(next_.s[o], next_.s[k]);
			t = get_hash(next_.s);
			if(!vis[t])
			{
				if(t==Aim)
					return next_.lvl-1;
				swap(p, b);
				q.push(next_);
				vis[t] = 1;
				swap(p, b);
			}
			swap(next_.s[o], next_.s[k]);
		}
	}
	return vis[Aim]-1;
}

int main()
{
	// freopen("test.in", "r", stdin);
	int T;
	for(T=0; T<32; T++)
		aim.push_back(ss[T]);
	scanf("%d", &T);
	while(T--)
	{
		memset(m, 0, sizeof(m));
		int i, j, t;
		for(i=0; i<4; i++)
			for(j=1; j<8; j++)
			{
				scanf("%d", &t);
				m[i][j] = (char)t;
				if(t%10==1)
					swap(m[i][j], m[(t/10)-1][0]);
			}
		printf("%d\n", bfs());
	}
	return 0;
}