// H(n)
// http://uva.onlinejudge.org/external/115/11526.pdf
// water

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
typedef long long LL;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        LL n;
        scanf("%lld",&n);
        LL ans=0;
        LL limit=(LL)sqrt(n+0.0);
        for(LL i=1;i<=limit;i++){
            ans+=n/i;
            if(n/i>i) ans+=i*(n/(i)-n/(i+1));
        }
        printf("%lld\n",ans);
    }
    return 0;
}
