#include<iostream>
#include<algorithm>

using namespace std;

struct p {
	int weight;
	int speed;
	int index;
}node[1010];

bool cmp(p a, p b)
{
	if(a.weight == b.weight)
		return a.speed > b.speed;
	return a.weight < b.weight;
}

int main()
{
	// freopen("test.in", "r", stdin);
	// freopen("test.out", "w", stdout);
	int i, j;
	int n;
	int dp[1010];
	int pre[1010];
	int res[1010];
	int maxlen;
	int maxi;
	i = 1;
	maxlen = 0;
	while(scanf("%d %d", &node[i].weight, &node[i].speed) != EOF)
	{
		dp[i] = 1;
		pre[i] = 0;
		node[i].index = i;
		i++;
	}
	n = i-1;
	sort(node+1, node+1+n, cmp);

	dp[1] = 1;
	for(i=1; i<=n; i++)
	{
		for(j=1; j<i; j++)
		{
			if(node[i].weight > node[j].weight && node[i].speed < node[j].speed && dp[j]+1>dp[i])
			{
				dp[i] = dp[j] + 1;
				pre[i] = j;
				if(dp[i] > maxlen)
				{
					maxi = i;
					maxlen = dp[i];
				}
			}
		}
	}

	int t = maxi;
	i = 0;
	while(t != 0)
	{
		res[i++] = t;
		t = pre[t];
	}
	printf("%d\n", i);
	while(i>0)
	{
		i--;
		printf("%d\n", node[res[i]].index);
	}
	return 0;
}