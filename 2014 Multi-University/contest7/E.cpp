#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
#define maxn 1600
typedef long long LL;
LL dp[maxn][maxn];
int main(){
    int T,cas=0;
    scanf("%d",&T);
    while(T--){
        int n;
        LL x,y,z,t;
        scanf("%d%I64d%I64d%I64d%I64d",&n,&x,&y,&z,&t);
        memset(dp,0,sizeof(dp));
        LL ans=n*x*t;
        for(LL i=1;i<=n;i++){
            for(LL j=0;j<=i;j++){
                if(j-1>=0) dp[i][j]=max(dp[i-1][j]+(t+j*z)*(i-1-j)*y,dp[i-1][j-1]+(t+(j-1)*z)*(i-j)*y);
                else dp[i][j]=dp[i-1][j]+(t+j*z)*(i-1-j)*y;
                ans=max(ans,dp[i][j]+(n-i)*(x+y*(i-j))*(t+j*z));
            }
        }
        printf("Case #%d: %I64d\n",++cas,ans);
    }
    return 0;
}
