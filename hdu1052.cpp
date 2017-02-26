#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int cmp(int a, int b)
{
	return a>b;
}

int main()
{
	// freopen("test.in", "r", stdin);
	int n;
	int a[1005], b[1005];
	int num[1005];
	while(scanf("%d", &n) && n)
	{
		for(int i=0; i<n; i++)
		{
			scanf("%d", &a[i]);
		}
		for(int i=0; i<n; i++)
		{
			scanf("%d", &b[i]);
		}
		sort(a, a+n, cmp);
		sort(b, b+n, cmp);
		int front, head, count;
		front = head = count = 0;
		int tail, rear;
		tail = rear = n-1;
		while(front <= rear)
		{
			if(a[front] > b[head])
			{
				num[front] = head;
				front++;
				head++;
			}
			else if(a[front] < b[head])
			{
				num[rear] = head;
				rear--;
				head++;
			}
			else
			{
				if(a[rear] > b[tail])
				{
					num[rear] = tail;
					rear--;
					tail--;
				}
				else
				{
					num[rear] = head;
					rear--;
					head++;
				}
			}
		}
		for(int i=0; i<n; i++)
		{
			if(a[i] > b[num[i]])
				count++;
			else if(a[i] < b[num[i]])
				count--;
		}
		int sum = 0;
		sum = count * 200;
		printf("%d\n", sum);
	}
	return 0;
}