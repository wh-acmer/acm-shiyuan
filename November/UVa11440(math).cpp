// Help Tomisu
// http://uva.onlinejudge.org/external/114/11440.pdf
// math

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
#define N 10000010
const LL mod=100000007;
bool vis[N];
LL g[N];
void init(){
    memset(vis,true,sizeof vis);
    vis[0]=vis[1]=false;
    for(int i=2;i<N;i++){
        if(vis[i]){
            for(int j=2*i;j<N;j+=i){
                vis[j]=false;
            }
        }
    }
    g[1]=g[2]=1;
    for(int i=3;i<N;i++){
        if(vis[i]) g[i]=(i-1)*g[i-1]%mod;
        else g[i]=i*g[i-1]%mod;
    }
}
int main(){
    LL n,m;
    init();
    while(scanf("%lld%lld",&n,&m)!=EOF){
        if(n==0 && m==0) break;
        LL ans=g[m];
        for(LL i=m+1;i<=n;i++){
            ans=ans*i%mod;
        }
        ans+=mod-1;
        ans%=mod;
        printf("%lld\n",ans);
    }
    return 0;
}
