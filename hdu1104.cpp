#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>

using namespace std;
const int M = 1000010;

int n, m, k, km;
bool vis[M];

struct node
{
	int num;
	int step;
	string road;
};

void bfs()
{
	memset(vis, 0, sizeof(vis));
	queue<node> q;
	node q1;
	q1.num = n;
	q1.step = 0;
	q1.road = "";
	q.push(q1);
	vis[(n%k+k)%k] = 1;
	while(!q.empty())
	{
		node q2 = q.front();
		q.pop();
		if(((n+1)%k+k)%k == (q2.num%k+k)%k)
		{
			printf("%d\n", q2.step);
			cout<<q2.road<<endl;
			return;
		}
		q1.step = q2.step+1;
		for(int i=0; i<4; i++)
		{
			if(i == 0)
			{
				q1.num = (q2.num+m)%km;
				q1.road = q2.road + '+';
			}
			else if(i == 1)
			{
				q1.num = (q2.num-m)%km;
				q1.road = q2.road + '-';
			}
			else if(i == 2)
			{
				q1.num = (q2.num*m)%km;
				q1.road = q2.road + '*';
			}
			else if(i == 3)
			{
				q1.num = (q2.num%m+m)%m%km;
				q1.road = q2.road + '%';
			}
			if(!vis[(q1.num%k+k)%k])
			{
				q.push(q1);
				vis[(q1.num%k+k)%k] = 1;
			}
		}
	}
	puts("0");
}

int main()
{
	// freopen("test.in", "r", stdin);
	while(~scanf("%d%d%d", &n, &k, &m))
	{
		if(n==0 && k==0 && m==0)
			break;
		km = k*m;
		bfs();
	}
	return 0;
}