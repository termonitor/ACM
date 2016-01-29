#include<iostream>
#include<algorithm>

using namespace std;

const int N = 205;
struct point
{
	int x, y;
	point(int x=0, int y=0):x(x), y(y){}
};

char in[N];

//A时 顺时针旋转  V时 逆时针旋转
//其实题意就是A右转，V左转，每次前进10
void solve()
{
	point st(300, 420), ed(310, 420), ted;
	printf("300 420 moveto\n");
	printf("310 420 lineto\n");
	int i;
	for(i=0; in[i]; i++)
	{
		if(in[i] == 'A')
		{
			ted.x = (ed.y - st.y) + ed.x;
			ted.y = -(ed.x - st.x) + ed.y;
		} else {
			ted.x = -(ed.y - st.y) + ed.x;
			ted.y = (ed.x - st.x) + ed.y;
		}
		st = ed;
		ed = ted;
		printf("%d %d lineto\n", ed.x, ed.y);
	}
	printf("stroke\n");
	printf("showpage\n");
}

int main()
{
	while(scanf("%s", in) != EOF)
		solve();
	return 0;
}