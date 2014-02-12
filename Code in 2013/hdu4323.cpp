/*
    ±‡º≠æ‡¿Îdp
*/
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;
string s[1510],t;
int N,M;
int dp[11][11];
int sb(int n)
{
    if(n>0)
        return n;
    return -n;
}
int DP(int index)
{
    int m=s[index].size()-1;
    int n=t.size()-1;
    //memset(dp,0,sizeof(dp));
    dp[0][0]=0;
    for(int i=1;i<=m;i++)
        dp[i][0]=i;
    for(int i=1;i<=n;i++)
        dp[0][i]=i;
    for(int j=1;j<=n;j++)
        for(int i=1;i<=m;i++)
        {
            if(s[index][i]==t[j])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=min(dp[i-1][j]+1,min(dp[i][j-1]+1,dp[i-1][j-1]+1));
        }
    return dp[m][n];
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        scanf("%d%d",&N,&M);
        for(int i=1;i<=N;i++)
        {
            cin>>s[i];
            s[i]=" "+s[i];
        }
        printf("Case #%d:\n",cas);
        for(int i=1;i<=M;i++)
        {
            int p,tmp,ans=0;
            cin>>t>>p;
            t=" "+t;
            for(int j=1;j<=N;j++)
            {
                if(sb(s[j].size()-t.size())>p)
                    continue;
                tmp=DP(j);
                if(tmp<=p)
                {
                    ans++;
                    //cout<<s[j]<<":"<<t<<":"<<tmp<<endl;
                }
            }
            printf("%d\n",ans);
        }
    }
}
