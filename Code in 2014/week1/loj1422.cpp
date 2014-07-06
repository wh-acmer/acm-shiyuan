#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;
#define maxn 110
int a[maxn],dp[maxn][maxn];
int main(){
    int T,cas=0;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=1;i<=n;i++) dp[i][i]=1;
        for(int i=n-1;i>=1;i--){
            for(int j=i+1;j<=n;j++){
                dp[i][j]=dp[i+1][j]+1;
                for(int k=i+1;k<=j;k++){
                    if(a[i]==a[k]){
                        dp[i][j]=min(dp[i][j],dp[i+1][k]+dp[k+1][j]);
                    }
                }
            }
        }
        printf("Case %d: %d\n",++cas,dp[1][n]);
    }
    return 0;
}
