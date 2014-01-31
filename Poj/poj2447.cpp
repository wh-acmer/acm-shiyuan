/*
    注意 Pow溢出 分解用 Pollard_rho
*/

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
LL multi(LL a,LL b,LL mod){
    LL ans=0;
    while(b){
        if(b&1) b--,ans=(ans+a)%mod;
        else b/=2,a=(a+a)%mod;
    }
    return ans;
}
LL Pow(LL a,LL b,LL mod){
    LL ans=1;
    while(b){
        if(b&1) b--,ans=multi(ans,a,mod)%mod;
        else b/=2,a=multi(a,a,mod)%mod;
    }
    return ans;
}
LL random(LL n){
    return LL ((double)rand()/RAND_MAX*n+0.5);
}
LL gcd(LL a,LL b){
    if(b==0) return a;
    return gcd(b,a%b);
}
LL pollard_rho(LL n,int c){
    LL x,y,d,i=1,k=2;
    x=random(n-2)+1;
    y=x;
    while(1){
        i++;
        x=(multi(x,x,n)+c)%n;
        d=gcd(y-x,n);
        if(1<d && d<n) return d;
        if(y==x) return n;
        if(i==k){
            y=x;
            k<<=1;
        }
    }
}
int main(){
    LL C,E,N,P,Q,T,D;
    while(scanf("%lld%lld%lld",&C,&E,&N)!=EOF){
        P=pollard_rho(N,10007);
        Q=N/P;
        T=(P-1)*(Q-1);
        exgcd(E,T,D,Q);
        D=(D%T+T)%T;
        printf("%lld\n",Pow(C,D,N));
    }
    return 0;
}
