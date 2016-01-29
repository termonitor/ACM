#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	// freopen("test.in", "r", stdin);
	int n;
	double d;
	int num;
	char h, m1, m2, s1, s2;
	scanf("%d", &n);
	scanf("%lf", &d);
	while(scanf("%d", &num) != EOF)
	{
		printf("%3d: ", num);
		bool flag = true;
		int sumtime = 0;
		for(int i=0; i<n; i++)
		{
			getchar();
			scanf("%c:%c%c:%c%c", &h, &m1, &m2, &s1, &s2);
			if(h=='-')
				flag = false;
			if(!flag)
				continue;
			sumtime += (h-'0')*3600 + ((m1-'0')*10+(m2-'0'))*60 + (s1-'0')*10+(s2-'0');
		}
		if(!flag)
			printf("-\n");
		else
		{
			double t1 = sumtime/d;
			//四舍五入
			int t2 = (int)(t1+0.5);
			printf("%d:%02d min/km\n", t2/60, t2%60);
		}
	}
	return 0;
}