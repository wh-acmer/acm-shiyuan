/*
    设dp[i][j]表示i个人被分成了j个队
    dp[i][j]=dp[i-1][j-1]+dp[i-1][j]*j
*/
#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
long long dp[30][30];
int main()
{
    dp[0][0]=1;
    for(int i=1;i<=25;i++)
        for(int j=1;j<=i;j++)
            dp[i][j]=dp[i-1][j-1]+dp[i-1][j]*j;
    for(int i=1;i<=25;i++)
    {
        dp[i][0]=0;
        for(int j=1;j<=i;j++)
            dp[i][0]+=dp[i][j];
    }
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        printf("%I64d\n",dp[n][0]);
    }
    return 0;
}
