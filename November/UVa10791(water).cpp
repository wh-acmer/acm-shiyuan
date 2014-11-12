// Minimum Sum LCM
// http://uva.onlinejudge.org/external/107/10791.pdf
// 质因数分解

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
typedef long long LL;
int main(){
    LL n;
    int cas=0;
    while(scanf("%lld",&n)!=EOF){
        if(n==0) break;
        LL nn=n;
        printf("Case %d: ",++cas);
        LL limit=(LL)sqrt(n+0.0);
        LL ans=0;
        for(int i=2;i<=limit;i++){
            if(n%i==0){
                LL now=1;
                while(n%i==0){
                    n/=i;
                    now*=i;
                }
                ans+=now;
            }
        }
        if(ans==0) ans=n+1;
        else{
            if(n!=1) ans+=n;
            if(n==1 && ans==nn) ans++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
