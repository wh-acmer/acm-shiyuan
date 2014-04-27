#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <iostream>
#include <vector>
#include <cmath>
#define maxn 200010
using namespace std;
int s[110],f[110];
int dp[maxn];
const int miao=100000;
int main()
{
    int n;
    scanf("%d",&n);
    int sum=0;
    for(int i=1;i<=n;i++)
        scanf("%d%d",&s[i],&f[i]);
    for(int i=0;i<maxn;i++)
        dp[i]=-20000000;
    dp[miao]=0;
    for(int i=1;i<=n;i++)
        if(s[i]>0)
            for(int j=maxn-1;j>=s[i];j--)
                dp[j]=max(dp[j],dp[j-s[i]]+f[i]);
        else
            for(int j=0;j<maxn+s[i];j++)
                dp[j]=max(dp[j],dp[j-s[i]]+f[i]);

    int ans=0;
    for(int i=miao;i<maxn;i++)
        if(dp[i]>0)
            ans=max(ans,dp[i]+i-miao);
    printf("%d\n",ans);
    return 0;
}
