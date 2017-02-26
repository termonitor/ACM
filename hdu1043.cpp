#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>

using namespace std;

/*
	hdu1043  A*代码
	A*+哈希+曼哈顿距离
	AC 405MS  4496K  G++
*/

#define N 363000

bool visit[N];
char visit1[N];
int pre[N], st, a[10], end1;
int dir[9]={1, 1, 2, 6, 24, 120, 720, 5040, 40320};

struct node
{
	int ma[10];
	int ans1;
	int x;
	int f;
	int g;
	bool operator <(const node &a) const
	{
		return a.f < f;
	}
};

int hash1(int s[])
{
	int i, j, cnt, sum;
	sum = 0;
	for(i=1; i<=9; i++)
	{
		cnt = 0;
		for(j=1; j<i; j++)
			if(s[j] > s[i]) cnt++;
		sum += cnt*dir[i-1];
	}
	return sum;
}

int ABS(int x)
{
	return x<0 ? (-x):x;
}

int check(int s[])
{
	int i, j, cnt = 0;
	for(i=0; i<=9; i++)
	{
		if(s[i] == 9) continue;
		for(j=1; j<i; j++)
		{
			if(s[j] == 9)
				continue;
			if(s[j]>s[i])
				cnt++;
		}
	}
	return cnt;
}

//不算x时的曼哈顿距离
int h(int s[])
{
	int curx, cury;
	int endx, endy;
	int sum, i, ans;
	sum = 0;
	for(i=1; i<=9; i++)
	{
		if(s[i] == 9)
			continue;
		ans = s[i];
		curx = (i+2)/3;
		cury = (i-1)%3 + 1;
		endx = (ans+2)/3;
		endy = (ans-1)%3 + 1;
		sum += ABS(curx-endx) + ABS(cury-endy);
	}
	return sum;
}

void bfs()
{
	int ans, i;
	priority_queue<node> q;
	node cur, next;
	cur.ans1 = st = hash1(a);
	visit[cur.ans1] = 1;
	if(st == end1) 
		return;
	for(i=1; i<=9; i++)
	{
		cur.ma[i] = a[i];
		if(a[i] == 9)
			cur.x = i;
	}
	cur.g = 0;
	cur.f = h(a);
	q.push(cur);
	while(!q.empty())
	{
		cur = q.top();
		q.pop();
		//向上
		if((cur.x+2)/3 != 1)
		{
			next = cur;
			next.x = cur.x -3;
			next.ma[cur.x] = next.ma[next.x];
			next.ma[next.x] = 9;
			ans = hash1(next.ma);
			if(!visit[ans])
			{
				next.g++;
				next.f = next.g + h(next.ma);
				visit[ans] = 1;
				next.ans1 = ans;
				pre[ans] = cur.ans1;
				visit1[ans] = 'u';
				if(ans == end1)
					return;
				q.push(next);
			}
		}
		//向下
		if((cur.x+2)/3 !=3 )
		{
			next = cur;
			next.x = cur.x + 3;
			next.ma[cur.x] = next.ma[next.x];
			next.ma[next.x] = 9;
			ans = hash1(next.ma);
			if(!visit[ans])
			{
				next.g++;
				next.f = next.g + h(next.ma);
				visit[ans] = 1;
				next.ans1 = ans;
				pre[ans] = cur.ans1;
				visit1[ans] = 'd';
				if(ans == end1)
					return;
				q.push(next);
			}
		}
		//向左
		if(cur.x%3 != 1)
		{
			next = cur;
			next.x = cur.x - 1;
			next.ma[cur.x] = next.ma[next.x];
			next.ma[next.x] = 9;
			ans = hash1(next.ma);
			if(!visit[ans])
			{
				next.g++;
				next.f = next.g + h(next.ma);
				visit[ans] = 1;
				next.ans1 = ans;
				pre[ans] = cur.ans1;
				visit1[ans] = 'l';
				if(ans == end1)
					return;
				q.push(next);
			}
		}
		//向右
		if(cur.x%3 != 0)
		{
			next = cur;
			next.x = cur.x + 1;
			next.ma[cur.x] = next.ma[next.x];
			next.ma[next.x] = 9;
			ans = hash1(next.ma);
			if(!visit[ans])
			{
				next.g++;
				next.f = next.g + h(next.ma);
				visit[ans] = 1;
				next.ans1 = ans;
				pre[ans] = cur.ans1;
				visit1[ans] = 'r';
				if(ans == end1)
					return;
				q.push(next);
			}
		}
	}
}

int main()
{
	int i, j, ans;
	char str[50];
	while(gets(str))
	{
		ans = 0;
		memset(visit, 0, sizeof(visit));
		for(i=0; str[i]; i++)
		{
			if(str[i] == 'x')
				a[++ans] = 9;
			else if(str[i] != ' ')
				a[++ans] = str[i] - '0';
		}
		end1 = 0;
		ans = check(a);
		if(ans%2) {
			puts("unsolvable");
			continue;
		}
		bfs();
		j = 0;
		while(end1 != st)
		{
			str[j++] = visit1[end1];
			end1 = pre[end1];
		}
		for(i=j-1; i>=0; i--)
			printf("%c", str[i]);
		printf("\n");
	}
	return 0;
}