// Polygon
// http://acm.hust.edu.cn/vjudge/problem/viewProblem.action?id=22851
// math

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long LL;
LL gcd(LL a,LL b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int main(){
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++){
        LL n,k;
        scanf("%lld%lld",&n,&k);
        LL x=1;
        x<<=k;
        LL y=x-(k+1);
        LL g=gcd(x,y);
        printf("Case #%d: %lld/%lld\n",cas,y/g,x/g);
    }
    return 0;
}
