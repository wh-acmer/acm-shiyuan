/*
    prufer sequence
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
const LL mod = 1000000007 ;
#define N 20010
LL fac[N];
LL Pow(LL a,LL b){
    LL ans=1;
    while(b){
        if(b&1) b--,ans=(ans*a)%mod;
        else b/=2,a=(a*a)%mod;
    }
    return ans;
}
int main(){
    fac[0]=1;
    for(int i=1;i<N;i++) fac[i]=(fac[i-1]*i)%mod;
    int T,n,cas=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        LL ans=0;
        for(int i=0;i<n;i++){
            ans=(ans+(Pow(n,i)*Pow(fac[i],mod-2))%mod)%mod;
        }
        ans=(ans*fac[n-1])%mod;
        printf("Case %d: %lld\n",++cas,ans);
    }
    return 0;
}
