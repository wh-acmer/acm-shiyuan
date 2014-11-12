// Friends and Presents
// http://codeforces.com/contest/483/problem/B
// binary search

#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
LL cnt1,cnt2,x,y;
LL gcd(LL a,LL b){
    if(b==0) return a;
    return gcd(b,a%b);
}
LL lcm(LL a,LL b){
    return a/gcd(a,b)*b;
}
bool ok(LL mid){
    LL ttmp=mid/lcm(x,y);
    LL tmp=mid-mid/x-mid/y+ttmp;
    LL tmp1=mid/x-ttmp;
    LL tmp2=mid/y-ttmp;
    LL need1=cnt1-tmp2;
    LL need2=cnt2-tmp1;
    if(need1<0) need1=0;
    if(need2<0) need2=0;
    return need1+need2<=tmp;
}
int main(){
    while(scanf("%I64d%I64d%I64d%I64d",&cnt1,&cnt2,&x,&y)!=EOF){
        LL l=1,r=1,mid,ans=1;
        r<<=60;
        while(l<=r){
            mid=(l+r)>>1;
            if(ok(mid)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
