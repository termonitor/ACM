#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

#define N 30

char s[N], t[10], ans[10];
int target, n, a[N];
bool visited[N];

void work(int k)
{
	int temp;
	if(k == 5)
	{
		temp = a[t[0]-'A'] - pow(a[t[1]-'A'], 2) + pow(a[t[2]-'A'], 3) - pow(a[t[3]-'A'], 4) + pow(a[t[4]-'A'], 5);
		//strcmp(t, ans)>0 保证最后是最大字典序
		if(temp == target && strcmp(t, ans) >0)
		{
			strcpy(ans, t);
		}
		return ;
	}
	for(int i=0; i<n; i++)
	{
		if(!visited[s[i]-'A'])
		{
			t[k] = s[i];
			visited[s[i]-'A'] = true;
			work(k+1);
			visited[s[i]-'A'] = false;
		}
	}
}

int main()
{
	// freopen("test.in", "r", stdin);

	for(int i=0; i<26; i++)
		a[i] = i+1;
	while(scanf("%d", &target))
	{
		cin>>s;
		if(target==0 && !strcmp(s, "END"))
			break;
		memset(visited, false, sizeof(visited));
		memset(t, '\0', sizeof(t));
		memset(ans, '\0', sizeof(ans));
		n = strlen(s);
		work(0);
		if(strlen(ans) == 0)
			printf("no solution\n");
		else
			printf("%s\n", ans);
	}
	return 0;
}