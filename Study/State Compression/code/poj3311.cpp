#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int dp[1<<11][12];
int cnt[12][12];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        if(n==0) break;
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                scanf("%d",&cnt[i][j]);
        for(int k=0;k<=n;k++){
            for(int i=0;i<=n;i++){
                for(int j=0;j<=n;j++){
                    cnt[i][j]=min(cnt[i][j],cnt[i][k]+cnt[k][j]);
                }
            }
        }
        memset(dp,0x3f,sizeof(dp));
        int ans=dp[0][0];
        for(int i=1;i<=n;i++){
            dp[1<<(i-1)][i]=cnt[0][i];
        }
        for(int i=1;i<(1<<n);i++){
            for(int j=1;j<=n;j++){
                if((i&(1<<(j-1)))){
                    for(int k=1;k<=n;k++){
                        if(j==k) continue;
                        if(i&(1<<(k-1))){
                            dp[i][j]=min(dp[i][j],dp[i&(~(1<<(j-1)))][k]+cnt[k][j]);
                        }
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            ans=min(ans,dp[(1<<n)-1][i]+cnt[i][0]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
