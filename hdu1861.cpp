#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

struct Boat
{
	int hour;
	int minu;
	int borrowed;
};

int main()
{
	// freopen("test.in", "r", stdin);
	int serial, hour, minu, count, time;
	char flag;
	Boat boats[100];
	time = 0;
	count = 0;
	memset(boats, 0, sizeof(boats));
	for(scanf("%d", &serial); serial!=-1; scanf("%d", &serial))
	{
		scanf("%*c%c%*c%d%*c%d", &flag, &hour, &minu);
		if(serial == 0)
		{
			if(count == 0)
				printf("0 0\n");
			else
				printf("%d %d\n", count, (int)ceil((double)time/count));
			time = 0;
			count = 0;
			memset(boats, 0, sizeof(boats));
		} else {
			if(flag == 'S')
			{
				boats[serial-1].hour = hour;
				boats[serial-1].minu = minu;
				boats[serial-1].borrowed = 1;
			} else {
				if(boats[serial-1].borrowed)
				{
					count++;
					time += (hour - boats[serial-1].hour - 1) * 60;
					time += minu + 60 - boats[serial-1].minu;
				}
			}
		}
	}
	return 0;
}