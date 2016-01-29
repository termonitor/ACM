#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>

using namespace std;

/*
	hdu 1043 Eight
	思路：反向搜索，从目标状态找回状态对应的路径
	用康拖展开判重（hash)

	答案是正确的，但是会内存溢出
	MLE 62MS 37128K  G++
*/

const int MAXN = 1000000;
int fac[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
//0! 1! 2! 3! 4! 5! 6! 7! 8! 9! 康拖展开判重
bool vis[MAXN];
string path[MAXN];
//康拖展开求该序列的hash值
int cantor(int s[])
{
	int sum = 0;
	for(int i=0; i<9; i++)
	{
		int num = 0;
		for(int j=i+1; j<9; j++)
			if(s[j] < s[i])
				num++;
		sum += (num*fac[9-i-1]);
	}
	return sum+1;
}

struct node
{
	int s[9];
	int loc;
	int status;
	string path;
};

int mov[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};//u, d, l ,r
char indexs[5] = "durl";//和上面相反，因为是反向搜索
int aim=46234; //123456780对应的康拖展开的hash值，0表示x

void bfs()
{
	memset(vis, false, sizeof(vis));
	node cur, next;
	for(int i=0; i<8; i++)
		cur.s[i] = i+1;
	cur.s[8] = 0;
	cur.loc = 8;
	cur.status = aim;
	cur.path = "";
	queue<node> q;
	q.push(cur);
	path[aim] = "";
	while(!q.empty())
	{
		cur = q.front();
		q.pop();
		int x = cur.loc / 3;
		int y = cur.loc % 3;
		for(int i=0; i<4; i++)
		{
			int tx = x + mov[i][0];
			int ty = y + mov[i][1];
			if(tx<0 || tx>2 || ty<0 || ty>2)
				continue;
			next = cur;
			next.loc = tx*3 + ty;
			next.s[cur.loc] = next.s[next.loc];
			next.s[next.loc] = 0;
			next.status = cantor(next.s);
			if(!vis[next.status])
			{
				vis[next.status] = true;
				next.path = indexs[i] + next.path;
				q.push(next);
				path[next.status] = next.path;
			}
		}
	}
}

int main()
{
	char ch;
	node cur;
	bfs();
	while(cin>>ch)
	{
		if(ch == 'x')
		{
			cur.s[0] = 0;
			cur.loc = 0;
		}
		else
			cur.s[0] = ch - '0';
		for(int i=1; i<9; i++)
		{
			cin>>ch;
			if(ch == 'x')
			{
				cur.s[i] = 0;
				cur.loc = i;
			}
			else
				cur.s[i] = ch-'0';
		}
		cur.status = cantor(cur.s);
		if(vis[cur.status])
		{
			cout<<path[cur.status]<<endl;
		}
		else
			cout<<"unsolvable"<<endl;
	}
	return 0;
}