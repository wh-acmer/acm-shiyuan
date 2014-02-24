#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
typedef __int64 LL;
const LL mod = 10007;
LL Pow(LL a,LL b){
    LL ans=1;
    while(b){
        if(b&1) b--,ans=(ans*a)%mod;
        else b/=2,a=(a*a)%mod;
    }
    return ans;
}
int main(){
    int T; scanf("%d",&T);
    while(T--){
        LL n;
        scanf("%I64d",&n);
        printf("%I64d\n",(Pow(2,n-1)+Pow(4,n-1))%mod);
    }
    return 0;
}
