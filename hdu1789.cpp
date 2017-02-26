#include<iostream>
#include<algorithm>

using namespace std;

#define INF 0x7ffffff

struct p{
	int deadline;
	int score;
}node[1050];

bool cmp(p a, p b)
{
	if(a.score == b.score)
		return a.deadline < b.deadline;
	return a.score > b.score;
}

int main()
{
	int T;
	while(scanf("%d", &T)!=EOF && T)
	{
		int N;
		int i, j, k;
		bool used[10000];
		while(T--)
		{
			scanf("%d", &N);
			for(i=0; i<N; i++)
				scanf("%d", &node[i].deadline);
			for(i=0; i<N; i++)
				scanf("%d", &node[i].score);
			sort(node, node+N, cmp);
			memset(used, 0, sizeof(used));
			int ans = 0;
			for(i=0; i<N; i++)
			{
				for(j=node[i].deadline; j>0; j--)
				{
					if(!used[j])
					{
						used[j] = true;
						break;
					}
				}
				if(j == 0)
					ans += node[i].score;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}