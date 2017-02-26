#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

#define MAXN 500
int sum[MAXN];

int main()
{
	// freopen("test.in", "r", stdin);
	char str[10];
	int n;
	int i;
	while(cin>>str)
	{
		scanf("%d", &n);
		i = 0;
		int len = strlen(str);
		for(i=len-1; i>=0; i--)
			if(str[i] == '.')
				break;
		int vl;
		if(i == -1)
			vl = 0;
		else
			vl = n*(len-1-i);
		memset(sum, 0, sizeof(sum));
		int j=0, T=0;
		for(i=0; i<len; i++)
		{
			if(str[i] == '.')
				continue;
			T = T*10+(str[i]-'0');
		}	
		int tmp = T;
		while(T)
		{
			sum[j] = T%10;
			T /= 10;
			j++;
		}
		T = tmp;
		int h = j;
		int c, k;
		for(i=0; i<n-1; i++)
		{
			c = 0;
			for(j=0; j<h; j++)
			{
				sum[j] *= T;
				sum[j] += c;
				if(sum[j] > 9)
				{
					c = sum[j]/10;
					sum[j] %= 10;
				}
				else
					c = 0;
			}
			k = 0;
			while(c)
			{
				sum[h+k] += c%10;
				c /= 10;
				k++;
			}
			h += k;
		}
		for(i=h-1; i>=vl; i--)
			if(sum[i] != 0)
				break;
		for(; i>=vl; i--)
			printf("%d", sum[i]);
		for(i=0; i<vl; i++)
			if(sum[i] != 0)
				break;
		if(i!=vl && vl!=0)
		{
			printf(".");
			for(j=vl-1; j>=i; j--)
				printf("%d", sum[j]);
		}
		printf("\n");
	}
	return 0;
}