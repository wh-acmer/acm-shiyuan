#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;
typedef long long LL;
LL mod,a,b;
LL Pow(LL a,LL b){
    LL ans=1;
    while(b){
        if(b&1) b--,ans=(ans*a)%mod;
        else b/=2,a=(a*a)%mod;
    }
    return ans;
}
int main(){
    int T,m;
    scanf("%d",&T);
    while(T--){
        scanf("%lld",&mod);
        LL ans=0;
        scanf("%d",&m);
        while(m--){
            scanf("%lld%lld",&a,&b);
            ans=(ans+Pow(a,b))%mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
