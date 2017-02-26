#include<iostream>
#include<algorithm>

using namespace std;

struct element
{
	int id; 
	double sa;
}e[10000];

int cmp(element a, element b)
{
	return a.sa > b.sa;
}

int cmp2(element a, element b)
{
	return a.id > b.id;
}

int main()
{
	// freopen("test.in", "r", stdin);
	int n, m, k;
	double x;
	while(~scanf("%d%d%d", &n, &m, &k))
	{
		for(int i=0; i<10000; i++)
		{
			e[i].sa = 0;
			e[i].id = i+1;
		}
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				scanf("%lf", &x);
				e[j].sa += x;
			}
		}
		sort(e, e+m, cmp);
		sort(e, e+k, cmp2);
		for(int i=0; i<k; i++)
		{
			if(i) printf(" ");
			printf("%d", e[i].id);
		}
		printf("\n");
	}
	return 0;
}