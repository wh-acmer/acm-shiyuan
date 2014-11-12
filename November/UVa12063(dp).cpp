// Zeros and Ones
// http://uva.onlinejudge.org/external/120/12063.pdf
// mask dp

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
int n,k;
const int N=66;
LL dp[N][N][102];
LL solve(int pos,int one,int re){
    if(dp[pos][one][re]!=-1) return dp[pos][one][re];
    if(pos==n){
        return one*2==n && re==0;
    }
    LL ans=0;
    ans+=solve(pos+1,one,(re<<1)%k);
    ans+=solve(pos+1,one+1,((re<<1)|1)%k);
    dp[pos][one][re]=ans;
    return ans;
}
int main(){
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++){
        memset(dp,-1,sizeof dp);
        scanf("%d%d",&n,&k);
        printf("Case %d: %lld\n",cas,k==0?0:solve(1,1,1));
    }
    return 0;
}
