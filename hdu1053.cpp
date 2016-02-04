#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>

using namespace std;

/*
	hdu1053
	哈弗曼树
*/

char str[1001];
int num[27];

int fun()
{
	int n = 0;
	int tmp[27];
	int k = 0;
	int i, j, l;
	sort(num, num+27);
	for(i=0; i<27; i++)
	{
		if(num[i] != 0)
			break;
	}
	l = 27-i;
	if(l == 1)
		return num[26];
	for(i=27-l; i<27; i++)
	{
		tmp[k++] = num[i];
	}
	for(i=0; i<l-1; i++)
	{
		if(i%2 == 0)
		{
			num[0] = tmp[0] + tmp[1];
			n += num[0];
			for(j=2; j<k; j++)
			{
				num[j-1] = tmp[j];
			}
			k--;
			sort(num, num+k);
		}
		else
		{
			tmp[0] = num[0] + num[1];
			n += tmp[0];
			for(j=2; j<k; j++)
			{
				tmp[j-1] = num[j];
			}
			k--;
			sort(tmp, tmp+k);
		}
	}
	return n;
}

int main()
{
	// freopen("test.in", "r", stdin);
	int len, i;
	int ori, now;
	while(cin>>str && strcmp(str, "END")!=0)
	{
		for(int i=0; i<27; i++)
		{
			num[i] = 0;
		}
		len = strlen(str);
		for(i=0; i<len; i++)
		{
			if(str[i]-'A' < 26)
			{
				num[str[i]-'A']++;
			} else {
				num[26]++;
			}
		}
		ori = 8*len;
		now = fun();
		printf("%d %d %.1lf\n", ori, now, 1.0*ori/now);
	}
	return 0;
}