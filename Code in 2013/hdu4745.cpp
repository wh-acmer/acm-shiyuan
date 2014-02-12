/*
    water
*/
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1010 ;
int dp[maxn][maxn];
int a[maxn];
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
            dp[i][i]=1;
        for(int i=n;i>=1;i--)
            for(int j=i+1;j<=n;j++)
            {
                dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                if(a[i]==a[j])
                    dp[i][j]=max(dp[i][j],dp[i+1][j-1]+2);
            }
        int ans=0;
        for(int i=1;i<=n;i++)
            ans=max(ans,dp[1][i]+dp[i+1][n]);
        printf("%d\n",ans);
    }
    return 0;
}
