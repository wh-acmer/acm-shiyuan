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
#define inf 0x3fffffff
typedef long long LL;
/// dp[i][j] 枚举前i头牛,后状态为j的方案数
LL dp[2][(1<<20)];
vector<int>v[21];
int getone(int n){
    int ans=0;
    while(n){
        ans++;
        n-=n&(-n);
    }
    return ans;
}
int main(){
    int n,m,x,y;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=0;i<=n;i++) v[i].clear();
        memset(dp,0,sizeof(dp)); dp[0][0]=1;
        for(int i=1;i<=n;i++){
            scanf("%d",&x); for(int j=0;j<x;j++) scanf("%d",&y),v[i].push_back(y-1);
        }
        for(int i=1;i<=n;i++){
            for(int state=0;state<(1<<m);state++){ // 枚举所占的状态
                if(getone(state)!=i) continue;
                for(int j=0;j<v[i].size();j++){
                    if(state&(1<<v[i][j]))
                        dp[i&1][state]+=dp[1-(i&1)][state&(~(1<<v[i][j]))];
                }
            }
            memset(dp[1-(i&1)],0,sizeof(dp[1-(i&1)]));
        }
        LL ans=0;
        for(int i=0;i<(1<<m);i++) ans+=dp[n&1][i];
        printf("%lld\n",ans);
    }
    return 0;
}
