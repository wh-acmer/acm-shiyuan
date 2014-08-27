#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
LL dp[1<<16][16];
int val[16][16];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&val[i][j]);
            }
        }
        memset(dp,0x3f,sizeof dp);
        for(int i=0;i<(1<<n);i++){
            for(int j=0;j<n;j++){
                if((i&(1<<j))==(1<<j)){
                    if(i==(1<<j)){
                        dp[i][j]=0;
                        continue;
                    }
                    for(int k=0;k<n;k++){
                        if(j!=k){
                            dp[i][j]=min(dp[i][j],dp[i&~(1<<j)][k]+val[k][j]);
                        }
                    }
                }
            }
        }
        int all=(1<<n)-1;
        LL ans=dp[all][0];
        for(int i=0;i<n;i++){
            ans=min(ans,dp[all][i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
