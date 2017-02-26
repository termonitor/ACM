#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

/*
	Big Number Add
*/

int main()
{
	// freopen("test.in", "r", stdin);
	int t;
	char s[105];
	int a[10005], b[1005];
	scanf("%d", &t);
	while(t--)
	{
		memset(a, 0, sizeof(a));
		while(scanf("%s", s)&&strcmp(s, "0")!=0)
		{
			memset(b, 0, sizeof(b));
			int len = strlen(s);
			for(int j=0, i=len-1; i>=0; i--)
			{
				b[j++] = s[i] - '0';
			}
			for(int i=0; i<1005; i++)
			{
				a[i] += b[i];
				if(a[i] >= 10)
				{
					a[i] -= 10;
					a[i+1] += 1;
				}
			}
		}
		int len = 0;
		for(int i=1004; i>=0; i--)
			if(a[i]) {
				len = i;
				break;
			}
		for(int i=len; i>=0; i--)
			printf("%d", a[i]);
		printf("\n");
		if(t != 0)
			printf("\n");
	}
	return 0;
}