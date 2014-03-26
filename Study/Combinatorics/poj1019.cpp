#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
LL a[32000],sum[32000];
int Solve(LL n){
    int now=lower_bound(sum,sum+32000,n)-sum;
    int remain=n-sum[now-1];
    int bit=-remain+*lower_bound(a,a+32000,remain);
    now = lower_bound(a,a+32000,remain)-a;
    while(bit--) now/=10;
    return now%10;

}
int main(){
    a[0]=0; sum[0]=0;
    for(int i=1;i<32000;i++)
        a[i]=a[i-1]+(int)(log10(i+0.0)+1),sum[i]=sum[i-1]+a[i];
    int T; scanf("%d",&T);
    while(T--){
        LL n; scanf("%lld",&n);
        printf("%d\n",Solve(n));
    }
    return 0;
}
