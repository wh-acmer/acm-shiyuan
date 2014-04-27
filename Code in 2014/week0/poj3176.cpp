#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define maxn 400
int a[maxn][maxn];
int dp[maxn][maxn];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        memset(dp,0,sizeof(dp));
        memset(a,0,sizeof(a));
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                scanf("%d",&a[i][j]);
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+a[i][j];
                ans=max(ans,dp[i][j]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
