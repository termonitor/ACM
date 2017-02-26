#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

struct node
{
	string name;
	int mark;
	int num;
}rt[305];

bool cmp(node a, node b)
{
	if(a.mark != b.mark)
		return a.mark > b.mark;
	return a.num < b.num;
}

int main()
{
	// freopen("test.in", "r", stdin);
	string name;
	int a, b;
	int n;
	int flag;
	while(scanf("%d", &n) != EOF)
	{
		int i;
		for(i=0; i<n; i++)
		{
			// scanf("%s %d", &rt[i].name, &rt[i].mark);
			cin>>rt[i].name>>rt[i].mark;
			rt[i].num = i;
		}
		sort(rt, rt+n, cmp);
		flag = 0;
		for(i=0; i<n; i++)
		{
			// scanf("%s %d", &name, &b);
			cin>>name>>b;
			if(rt[i].mark != b)
			{
				flag = 1;
				break;
			} else if(rt[i].name != name)
			{
				flag = 2;
			}
		}
		if(flag == 1)
		{
			a = n-i-1;
			// scanf("%s %d", &name, &b);
			while(a--)
				cin>>name>>b;
		}
		switch(flag)
		{
			case 0:
				printf("Right\n");
				break;
			case 1:
				printf("Error\n");
				for(i=0; i<n; i++)
					// printf("%s %d\n", rt[i].name, rt[i].mark);
					cout<<rt[i].name<<" "<<rt[i].mark<<endl;
				break;
			case 2:
				printf("Not Stable\n");
				for(i=0; i<n; i++)
					// printf("%s %d\n", rt[i].name, rt[i].mark);
					cout<<rt[i].name<<" "<<rt[i].mark<<endl;
				break;
		}
	}
	return 0;
}