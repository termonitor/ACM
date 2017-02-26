#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

char str[10];
int ar[101], br[101], cr[101];

int main()
{
	// freopen("test.in", "r", stdin);
	int a, b, c;
	int count, num, m, h, table, *p;
	while(~scanf("%d%d%d", &a, &b, &c))
	{
		if(a==0 && b==0 && c==0)
			break;
		memset(ar, 0, sizeof(ar));
		memset(br, 0, sizeof(br));
		memset(cr, 0, sizeof(cr));
		count = 0;
		while(cin>>str, str[0]!='#')
		{
			sscanf(str, "%d:%d", &h, &m);
			m += h*60;
			scanf("%d", &num);
			table = num;
			if(num&1)
				table++;
			if(table == 2)
			{
				p = min_element(ar, ar+a);
				if(*p <= m+30)
				{
					if(*p <=m)
						*p = m+30;
					else
						*p += 30;
					count += num;
				}
			} 
			else if(table == 4)
			{
				p = min_element(br, br+b);
				if(*p <= m+30)
				{
					if(*p <= m)
						*p = m+30;
					else
						*p += 30;
					count += num;
				}
			}
			else
			{
				p = min_element(cr, cr+c);
				if(*p <= m+30)
				{
					if(*p <= m)
						*p = m+30;
					else
						*p += 30;
					count += num;
				}
			}
		}
		printf("%d\n", count);
	}
	return 0;
}