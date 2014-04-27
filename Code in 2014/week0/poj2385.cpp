#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
typedef long long LL;
int dp[3][1010][40],v[1010];
int main(){
    int n,W;
    while(scanf("%d%d",&n,&W)!=EOF){
        for(int i=1;i<=n;i++) scanf("%d",&v[i]);
        memset(dp,0,sizeof(dp));
        int ans=0;
        dp[1][1][0]=(v[1]==1);
        dp[2][1][0]=(v[1]==2);
        ans=max(ans,max(dp[1][1][0],dp[2][1][0]));
        for(int i=2;i<=n;i++){
            dp[1][i][0]=dp[1][i-1][0]+(v[i]==1);
            dp[2][i][0]=dp[2][i-1][0]+(v[i]==2);
            ans=max(ans,max(dp[1][i][0],dp[2][i][0]));
            for(int j=1;j<=W;j++){
                dp[1][i][j]=max(dp[1][i-1][j]+(v[i]==1),dp[2][i-1][j-1]+(v[i]==2));
                dp[2][i][j]=max(dp[2][i-1][j]+(v[i]==2),dp[1][i-1][j-1]+(v[i]==1));
                ans=max(ans,max(dp[2][i][j],dp[1][i][j]));
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
