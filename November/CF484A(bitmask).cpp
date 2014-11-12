// Bits
// http://codeforces.com/problemset/problem/484/A
// bit mask

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <vector>
using namespace std;
typedef long long LL;
LL solve(LL l,LL r){
    if(l==r) return l;
    int i=63;
    LL one=1;
    for(;i>=0;i--){
        if(r&(one<<i)){
            break;
        }
    }
    LL tmp=(one<<i);
    if(tmp<=l){
        return solve(l-tmp,r-tmp)+tmp;
    }
    if((tmp<<1)-1<=r){
        return (tmp<<1)-1;
    }
    return tmp-1;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        LL l,r;
        scanf("%I64d%I64d",&l,&r);
        printf("%I64d\n",solve(l,r));
    }
    return 0;
}
