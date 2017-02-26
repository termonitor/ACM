#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>

using namespace std;

map<string, string> rec;

int main()
{
	// freopen("test.in", "r", stdin);
	string key, value, start;
	char str[3010];
	char op;
	cin>>start;
	while((cin>>value) && value != "END")
	{
		cin>>key;
		rec[key] = value;
	}
	cin>>start;
	getchar();
	while(1)
	{
		key="";
		while(scanf("%c", &op) != EOF)
		{
			if(op=='\n' && key=="END")
				return 0;
			if(op=='\n')
				break;
			if(!isalpha(op))
			{
				if(rec.find(key) != rec.end())
					cout<<rec[key];
				else
					cout<<key;
				cout<<op;
				key = "";
			}
			else
				key += op;
		}
		cout<<endl;
	}
	return 0;
}