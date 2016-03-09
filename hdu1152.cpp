#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

struct node
{
    int x, y;
}a[202000];

int main()
{
    int n;
    while(scanf("%d", &n)!=EOF)
    {
        if(n == 0)
            break;
        for(int i=0; i<n; i++)
        {
            scanf("%d%d", &a[i].x, &a[i].y);   
        }   
        int x = a[n/2].x;
        int y = a[n/2].y;
        int s, o;
        s = o = 0;
        for(int i=0; i<n; i++)
        {
            if((a[i].x>x&&a[i].y>y) || (a[i].x<x&&a[i].y<y))
                s++;
            else if((a[i].x>x&&a[i].y<y) || (a[i].x<x&&a[i].y>y))
                o++; 
        }
        printf("%d %d\n", s, o);
    }
    return 0;   
} 
