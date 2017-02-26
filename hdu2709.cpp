#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int N;
	int s[1000001];
	int i=3;
	s[1] = 1;
	s[2] = 2;
	//i为奇数时，s[i] = s[i-1]，相当于在前一个数的加数后面都加上一
	//i为偶数时，两种情况，加数里面含1和加数里面不含1
	//加数里面含1，则一定有两个1，相当于s[i-2]的加数里加上两个一
	//加数里面不含1，则相当于i/2的加数都乘以2，s[i>>1]种
	//因此为s[i] = (s[i-2] + s[i>>1])
	while(i <= 1000000)
	{
		s[i] = s[i-1];
		i++;
		s[i] = (s[i-2] + s[i>>1]) % 1000000000;
		i++;
	}
	while(scanf("%d", &N) != EOF)
	{
		printf("%d\n", s[N]);
	}
	return 0;
}