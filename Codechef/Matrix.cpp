#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
#define maxn 2010
char s[maxn][maxn];
int dp[maxn][maxn];
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=0;i<n;i++)    scanf("%s",&s[i]);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j]=s[i-1][j-1]-'0';
            }
        }
        long long ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(dp[i][j])
                    dp[i][j]=min(dp[i-1][j-1],dp[i-1][j])+1;
                ans+=dp[i][j];
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
