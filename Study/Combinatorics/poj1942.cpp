#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
typedef long long LL;
int main(){
    LL n,m,s;
    while(scanf("%lld%lld",&n,&m)!=EOF){
        if(n==0 && m==0) break;
        s=n+m; n=min(n,m);
        LL ans=1,i=1,j=s-n+1;
        while(j<=s){
            ans*=j;
            j++;
            while(ans%i==0 && i<=n){
                ans/=i;
                i++;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
