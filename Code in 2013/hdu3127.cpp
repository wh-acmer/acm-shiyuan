/*
    dp
*/
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;
#define maxn 1010
int dp[maxn][maxn];
int a[15],b[15],c[15];
int n;
int DP(int x,int y)
{
    if(x<=0 || y<=0)
        return 0;
    if(dp[x][y]!=-1)
        return dp[x][y];
    int mx=0;
    for(int i=1;i<=n;i++)
    {
        if(x-a[i]>0)
            mx=max(mx,DP(x-a[i],y)+DP(a[i],y));
        if(x-b[i]>0)
            mx=max(mx,DP(x-b[i],y)+DP(b[i],y));
        if(y-a[i]>0)
            mx=max(mx,DP(x,y-a[i])+DP(x,a[i]));
        if(y-b[i]>0)
            mx=max(mx,DP(x,y-b[i])+DP(x,b[i]));
    }
    return dp[x][y]=mx;

}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int x,y;
        scanf("%d%d%d",&n,&x,&y);
        memset(dp,-1,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&a[i],&b[i],&c[i]);
            dp[a[i]][b[i]]=max(dp[a[i]][b[i]],c[i]);
            dp[b[i]][a[i]]=max(dp[b[i]][a[i]],c[i]);
        }
        printf("%d\n",DP(x,y));
    }
    return 0;
}
