#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#define mod 1000000007
typedef long long LL;
LL dp[1<<20];
int n,k,L;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&k,&L);
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        int total=(1<<k)-1;
        int unuse=0;
        if(L>k){
            unuse=L-k;
            L=k;
        }
        for(int i=0;i<n;i++){
            for(int j=total;j>=0;j--){
                LL c=dp[j];
                if(c==0) continue;
                for(int p=1;p<=L;p++){
                    int now=j|(1<<(p-1));
                    now|=(j<<p)&total;
                    dp[now]=(dp[now]+c)%mod;
                }
                dp[j]=(dp[j]+(c*unuse)%mod)%mod;
            }
        }
        LL ans=0;
        for(int i=0;i<=total;i++){
            if(i&(1<<(k-1))){
               ans=(ans+dp[i])%mod;
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
