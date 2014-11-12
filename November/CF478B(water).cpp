// Random Teams
// http://codeforces.com/problemset/problem/478/B
// water

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
LL C(LL n){
    return n*(n-1)/2;
}
int main(){
    LL n,m;
    while(scanf("%I64d%I64d",&n,&m)!=EOF){
        LL mx=C(n-m+1);
        LL re=n%m;
        LL mi=re*C(n/m+1)+(m-re)*C(n/m);
        printf("%I64d %I64d\n",mi,mx);
    }
    return 0;
}
