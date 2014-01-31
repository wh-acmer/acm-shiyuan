#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
#define maxn 65535
typedef long long LL;
struct hash{
    LL a,b,next;
}Hash[maxn*2];
LL flg[maxn+66];
LL top,idx;
void ins(LL a,LL b){
    LL k=b&maxn;
    if(flg[k]!=idx){
        flg[k]=idx,Hash[k].next=-1,Hash[k].a=a,Hash[k].b=b;
        return ;
    }
    while(Hash[k].next!=-1){
        if(Hash[k].b==b) return ;
        k=Hash[k].next;
    }
    Hash[k].next=++top;
    Hash[top].next=-1,Hash[top].a=a,Hash[top].b=b;
}
LL find(LL b){
    LL k=b&maxn;
    if(flg[k]!=idx) return -1;
    while(k!=-1){
        if(Hash[k].b==b) return Hash[k].a;
        k=Hash[k].next;
    }
    return -1;
}
LL gcd(LL a,LL b){
    if(b==0) return a;
    return gcd(b,a%b);
}
LL exgcd(LL a,LL b,LL &x,LL &y){
    LL t,ans;
    if(b==0){
        x=1,y=0;
        return a;
    }
    ans=exgcd(b,a%b,x,y);
    t=x,x=y,y=t-a/b*y;
    return ans;
}
LL Inval(LL a,LL b,LL n){
    LL x,y,e;
    exgcd(a,n,x,y);
    e=x*b%n;
    return e<0?(e+n):e;
}
LL Pow(LL a,LL b,LL mod){
    LL ans=1;
    while(b){
        if(b&1) b--,ans=(ans*a)%mod;
        else b/=2,a=(a*a)%mod;
    }
    return ans;
}
LL Babystep(LL A,LL B,LL C){
    top=maxn,++idx;
    LL buf=1%C,D=buf,K,i,d=0,tmp;
    for(i=0;i<=100;buf=buf*A%C,i++)
        if(buf==B) return i;
    while((tmp=gcd(A,C))!=1){
        if(B%tmp) return -1;
        ++d,C/=tmp,B/=tmp,D=D*A/tmp%C;
    }
    LL M=(LL)ceil(sqrt((double)C));
    for(buf=1%C,i=0;i<=M;buf=buf*A%C,++i)
        ins(i,buf);
    for(i=0,K=Pow(A,M,C);i<=M;D=D*K%C,++i){
        tmp=Inval((LL)D,B,C);
        LL w=find(tmp);
        if(tmp>=0 && w!=-1)
            return i*M+w+d;
    }
    return -1;
}
int main(){
    LL K,P,N;
    while(scanf("%I64d%I64d%I64d",&K,&P,&N)!=EOF){
        if(N>=P || N<0) printf("Orz,I can’t find D!\n");
        else{
            LL ans=Babystep(K,N,P);
            if(ans<0) printf("Orz,I can’t find D!\n");
            else printf("%I64d\n",ans);
        }
    }
    return 0;
}
