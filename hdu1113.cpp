#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>

using namespace std;

map<string, string> node;

int main()
{
	// freopen("test.in", "r", stdin);
	string s;
	while(cin>>s &&s !="XXXXXX")
	{
		string t = s;
		sort(s.begin(), s.end());
		node.insert(pair<string, string>(t, s));
	}
	while(cin>>s)
	{
		if(s == "XXXXXX")
			break;
		int flag = 1;
		map<string, string>::iterator it;
		sort(s.begin(), s.end());
		for(it=node.begin(); it!=node.end(); it++)
		{
			if(it->second == s)
			{
				flag = 0;
				cout<<it->first<<endl;
			}
		}
		if(flag)
			cout<<"NOT A VALID WORD"<<endl;
		cout<<"******"<<endl;
	}
	return 0;
}