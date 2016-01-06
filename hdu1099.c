#include<stdio.h>

int GCD(int num1, int num2)
{
	if(num1 % num2 == 0)
		return num2;
	else
		return GCD(num2, num1 % num2);
}

int LCM(int a, int b)
{
	int tmp;
	tmp = a*b/GCD(a, b);
	return tmp;
}

int main()
{
	int fenzi, fenmu;
	int lastfenzi, lastfenmu;
	int n;
	//    b
	//  a -
	//    c
	int a, b, c;
	while(scanf("%d", &n) != EOF)
	{
		fenzi = n;
		lastfenmu = 0;
		lastfenzi = 0;
		a = 0;
		b = 0;
		c = 0;
		for(fenmu=n; fenmu>0; fenmu--)
		{
			if(fenzi % fenmu == 0)
			{
				a += fenzi/fenmu;
			} 
			else {
				if(lastfenzi == 0 && lastfenmu == 0)
				{
					lastfenzi = fenzi;
					lastfenmu = fenmu;
				} 
				else {
					int num = LCM(fenmu, lastfenmu);
					lastfenzi = (num/lastfenmu)*lastfenzi;
					lastfenmu = num;
					lastfenzi += (num/fenmu)*fenzi;
					if(lastfenzi%lastfenmu == 0)
					{
						a += lastfenzi/lastfenmu;
						lastfenzi = 0;
						lastfenmu = 0;
					}
					else {
						int tmp = lastfenzi / lastfenmu;
						a += tmp;
						lastfenzi -= tmp*lastfenmu;
						if(lastfenzi == 0)
							lastfenmu = 0;
						tmp = GCD(lastfenzi, lastfenmu);
						lastfenzi /= tmp;
						lastfenmu /= tmp;
					}
				}
			}
			if(lastfenzi != 0)
			{
				int tmp = lastfenzi / lastfenmu;
				a += tmp;
				lastfenzi -= tmp*lastfenmu;
				tmp = GCD(lastfenzi, lastfenmu);
				lastfenzi /= tmp;
				lastfenmu /= tmp;
				b = lastfenzi;
				c = lastfenmu;
			}
			// printf("%d %d %d %d\n", fenmu, a, lastfenzi, lastfenmu);
		}

		if(b != 0) {
			if(a < 10) {
				printf("  ");
			} else if(a < 100) {
				printf("   ");
			} else if(a < 1000) {
				printf("    ");
			} else if(a < 10000) {
				printf("     ");
			} else if(a < 100000) {
				printf("      ");
			} else if(a < 1000000) {
				printf("       ");
			}
			else {
				printf("        ");
			}
			printf("%d\n", b);
			printf("%d ", a);
			if(c < 10) {
				printf("-");
			} else if(c < 100) {
				printf("--");
			} else if(c < 1000) {
				printf("---");
			} else if(c < 10000) {
				printf("----");
			} else if(c < 100000) {
				printf("-----");
			} else if(c < 1000000) {
				printf("------");
			} else if(c < 10000000) {
				printf("-------");
			} else {
				printf("--------");
			}
			printf("\n");
			if(a < 10) {
				printf("  ");
			} else if(a < 100) {
				printf("   ");
			} else if(a < 1000) {
				printf("    ");
			} else if(a < 10000) {
				printf("     ");
			} else if(a < 100000) {
				printf("      ");
			} else if(a < 1000000) {
				printf("       ");
			}
			else {
				printf("        ");
			}
			printf("%d\n", c);
		}
		else {
			printf("%d\n", a);
		}
	}
	return 0;
}