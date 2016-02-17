#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int a[10010];

int main()
{
	// freopen("test.in", "r", stdin);
	int n;
	while(scanf("%d", &n) != EOF)
	{
		for(int i=0; i<n; i++)
			scanf("%d", &a[i]);
		sort(a, a+n);
		printf("%d\n", a[n/2]);
	}
	return 0;
}