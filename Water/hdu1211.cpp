#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long LL;
LL exgcd(LL a,LL b,LL &x,LL &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    LL ans=exgcd(b,a%b,x,y);
    LL tmp=x;
    x=y;
    y=tmp-a/b*y;
    return ans;
}
LL Pow(LL a,LL b,LL mod){
    LL ans=1;
    while(b){
        if(b&1) b--,ans=(ans*a)%mod;
        else b/=2,a=(a*a)%mod;
    }
    return ans;
}
int main(){
    LL p,q,e,l;
    while(scanf("%lld%I64d%I64d%I64d",&p,&q,&e,&l)!=EOF){
        LL fn=(p-1)*(q-1),d,k,n=p*q;
        exgcd(e,fn,d,k);
        d=(d%fn+fn)%fn;
        while(l--){
            scanf("%I64d",&k);
            printf("%c",Pow(k,d,n)%128);
        }
        printf("\n");
    }
    return 0;
}

