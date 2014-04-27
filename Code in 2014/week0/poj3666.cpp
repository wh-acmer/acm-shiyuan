#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
using namespace std;
typedef long long LL;
#define maxn 2010
long long dp[maxn][maxn];
int v[maxn],p[maxn],n;
bool cmp(int a,int b){
    return a>b;
}
LL solve(){
    LL ans=0x3fffffff;
    for(int i=1;i<=n;i++){
        LL tmp=dp[i-1][1];
        for(int j=1;j<=n;j++){
            tmp=min(tmp,dp[i-1][j]);
            dp[i][j]=abs(v[i]-p[j])+tmp;
        }
    }
    for(int i=1;i<=n;i++) ans=min(ans,dp[n][i]);
    return ans;
}
int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++) scanf("%d",&v[i]),p[i]=v[i]; sort(p+1,p+n+1);
        LL ans=solve();  sort(p+1,p+n+1,cmp);  ans=min(solve(),ans);
        printf("%lld\n",ans);
    }
    return 0;
}
