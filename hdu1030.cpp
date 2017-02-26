#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF)
	{
		if(n > m) swap(n, m);
		int leveln, levelm, leftn, leftm, rightn, rightm;
		leveln = sqrt(n-1) + 1;
		levelm = sqrt(m-1) + 1;
		leftn = (n-(leveln-1)*(leveln-1)+1)/2;
		leftm = (m-(levelm-1)*(levelm-1)+1)/2;
		rightn = (leveln*leveln-n)/2 + 1;
		rightm = (levelm*levelm-m)/2 + 1;

		int ans;
		ans = abs(leveln-levelm) + abs(leftn-leftm) + abs(rightn-rightm);
		printf("%d\n", ans);
	}
	return 0;
}