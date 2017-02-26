#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int main()
{
	// freopen("test.in", "r", stdin);
	int m,b,t,c;
	double s;
	char a;
	scanf("%d",&t);
	while(t--)
	{
		getchar();
		scanf("%c %d %d",&a,&b,&c);
		if(a=='+')
		{
			s=b+c;
			printf("%.0lf\n",s);
		}
		else
			if(a=='-')
			{
				s=b-c;
				printf("%.0lf\n",s);
			}
			else
				if(a=='*')
				{
					s=b*c;
					printf("%.0lf\n",s);
				}
				else
				{
					s=(b+0.0)/c;
					m=s;
					if(s==m)
					{
						printf("%.0lf\n",s);
					}
					else
					{
						printf("%.2lf\n",s);
					}
					
				}
	}
	return 0;
}