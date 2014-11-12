#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>P;
LL gcd(LL a,LL b){
    if(b==0) return a;
    return gcd(b,a%b);
}
// c represent kinds  , s represent length
P polya(int c,int s){
    LL p[64];
    p[0]=1;
    for(int k=1;k<=s;k++){
        p[k]=p[k-1]*c;
    }

    // reflection part
    LL reflection=s&1?s*p[s/2+1]:(s/2)*(p[s/2]+p[s/2+1]);

    // rotation part
    LL rotation=0;
    for(int k=1;k<=s;k++){
        rotation+=p[gcd(k,s)];
    }
    return P(rotation/s,(rotation+reflection)/2/s);
}
int main(){
    LL s,c;
    while(scanf("%lld%lld",&s,&c)!=EOF){
        P ans=polya(c,s);
        printf("%lld %lld\n",ans.first,ans.second);
    }
    return 0;
}
