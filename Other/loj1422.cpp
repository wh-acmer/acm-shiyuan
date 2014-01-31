#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define maxn 101
int dp[maxn][maxn],a[maxn],n;
int main(){
    int T,cas=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)  scanf("%d",&a[i]);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=100;i++) dp[i][i]=1;
        for(int i=n-1;i>=1;i--){
            for(int j=i+1;j<=n;j++){
                dp[i][j]=dp[i+1][j]+1;
                for(int k=i+1;k<=j;k++){
                    if(a[i]==a[k])
                        dp[i][j]=min(dp[i][j],dp[i+1][k]+dp[k+1][j]);
                }
            }
        }
        printf("Case %d: %d\n",++cas,dp[1][n]);
    }
    return 0;
}
