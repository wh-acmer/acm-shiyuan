#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
LL C[11][11],fac[11];
void init(){
    fac[0]=1;
    for(int i=1;i<11;i++){
        fac[i]=fac[i-1]*i;
    }
    for(int i=0;i<11;i++){
        C[i][0]=C[i][i]=1;
        for(int j=1;j<i;j++){
            C[i][j]=C[i-1][j]+C[i-1][j-1];
        }
    }
}
int main(){
    init();
    int n,K;
    while(scanf("%d%d",&n,&K)!=EOF){
        if(n<K)  printf("0\n");
        else printf("%lld\n",C[n][K]*C[n][K]*fac[K]);
    }
    return 0;
}

/*
    dp

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long LL;
LL dp[11][1<<10][11];
int main(){
    int n,K;
    while(scanf("%d%d",&n,&K)!=EOF){
        if(n<K){
            printf("0\n");
            continue;
        }
        memset(dp,0,sizeof dp);
        dp[0][0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<(1<<n);j++){
                for(int x=0;x<=K;x++){
                    dp[i][j][x]=dp[i-1][j][x];
                }
                for(int k=0;k<n;k++){
                    if(j&(1<<k)){
                        for(int x=1;x<=K;x++){
                            dp[i][j][x]+=dp[i-1][j-(1<<k)][x-1];
                        }
                    }
                }
            }
        }
        LL ans=0;
        for(int i=0;i<(1<<n);i++){
            ans+=dp[n][i][K];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
*/
