#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

/*
	欧拉回路：每条边恰好只走一次，并能回到出发点的路径
	欧拉路径：经过每一条边一次，但是不要求回到起始点
	思路：
	1.并查集判断连通
	2.将每个单词取出首字母和尾字母，转换为一条边，然后加入对应的连通分量中。如果这个字母出现过，visit数组标记为true。同时起点出度加1，终点入度加1.
	3.判断一下：
	1）这个图必须是连通的，即根结点只有一个。如果不是，直接结束本次算法。
	2）如果这个图是连通的，判断每个结点的入度和出度情况。
        如果这个图是欧拉路，则每个顶点的出度等于入度。即out[i] = in[i]
	如果这个图是半欧拉图，则起点的出度比入度大1，终点的入度比出度大1.其余顶点的出度等于入度。
	如果满足上述条件，就可以将所有单词链接起来，否则不能。
	当然，在判断出度入度的时候还有一点需要注意，那就是除了起点终点以外的顶点，出度必须等于入度（出度入度可以同时为2，即环），但是起点和终点必须保证出度和入度之差为1。
*/

#define MAXN 30
int pre[MAXN], in[MAXN], out[MAXN];
bool visit[MAXN];

int find(int x)
{
	return x == pre[x] ? x:find(pre[x]);
}

void join(int x, int y)
{
	int root1, root2;
	root1 = find(x);
	root2 = find(y);
	if(root1 != root2)
		pre[root2] = root1;
}


int main()
{
	// freopen("test.in", "r", stdin);
	int ncase;
	int innum, outnum;//记录入度出度不相等顶点个数
	int root;//根节点个数
	bool flag;//判断连通性
	bool flag1;//判断入度和出度是否是1或0
	int wordnum, len;
	int start, end;//转化为边
	char str[1010];
	scanf("%d", &ncase);
	while(ncase--)
	{
		memset(in, 0, sizeof(in));
		memset(out, 0, sizeof(out));
		memset(visit, false, sizeof(visit));
		for(int i=1; i<MAXN; i++)
			pre[i] = i;
		innum = outnum = root = 0;
		flag = flag1 = true;
		scanf("%d", &wordnum);
		for(int i=1; i<=wordnum; i++)
		{
			scanf("%s", str);
			len = strlen(str);
			start = str[0] - 'a' + 1;
			end = str[len-1] - 'a' + 1;
			visit[start] = true;
			visit[end] =  true;
			out[start]++;
			in[end]++;
			join(start, end);
		}
		for(int i=1; i<MAXN; i++)
		{
			if(visit[i])
			{
				if(pre[i] == i)
					root++;
				if(in[i] != out[i])
				{
					if(in[i] - out[i] == 1)
						innum++;
					else if(out[i] - in[i] == 1)
						outnum++;
					else
						flag1 = false;
				}
			}
			if(root > 1)
			{
				flag = false;
				break;
			}
		}
		if((flag && innum==0 && outnum==0 && flag1) || (flag && innum==1 && outnum==1 && flag1))
			printf("Ordering is possible.\n");
		else
			printf("The door cannot be opened.\n");
	}
	return 0;
}