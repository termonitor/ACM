#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int Min(int a, int b)
{
    return a<b? a:b;
}

int main()
{
    int hire, salary, fire;
    int n;
    int num[15];
    int dp[15][99999];
    int max, min;
    while(~scanf("%d", &n) && n)
    {
        scanf("%d%d%d", &hire, &salary, &fire);
        min = 99999;
        max = 0;
        for(int i=1; i<=n; i++)
        {
            scanf("%d", &num[i]);
            if(num[i] < min)
                min = num[i];
            if(num[i] > max)
                max = num[i];
        }   
        for(int i=0; i<=n; i++)
        {
            for(int j=min; j<=max; j++)
            {
                if(i == 0)
                {
                    dp[0][j] = 0;
                }   
                else
                    dp[i][j] = 546548;
            }   
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=num[i]; j<=max; j++)
            {
                if(i == 1)
                {
                    dp[i][j] = dp[i-1][j] + j*(hire+salary);   
                }   
                else
                {
                    for(int k=num[i-1]; k<=max; k++)
                    {
                        int a = dp[i-1][k];
                        int b = j*salary;
                        if(j >= k)
                        {
                            dp[i][j] = Min(dp[i][j], a+(j-k)*hire+b);   
                        }
                        else
                        {
                            dp[i][j] = Min(dp[i][j], a+(k-j)*fire+b);   
                        }
                    }   
                }
            }
        }
        int result = 546348;
        for(int i=num[n]; i<=max; i++)
        {
            if(dp[n][i] < result)
                result = dp[n][i];   
        }
        printf("%d\n", result);
    }
    return 0;   
}
