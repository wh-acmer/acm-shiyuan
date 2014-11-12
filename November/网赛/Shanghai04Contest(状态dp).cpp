#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 1010
double dp[N][(1<<10)];
bool vis[N][(1<<10)];
double p[11][N];
int n,m;
double dfs(int now,int s){
    if(s+1==(1<<n)){
        s=0;
    }
    if(vis[now][s]){
        return dp[now][s];
    }
    vis[now][s]=true;
    dp[now][s]=0;
    if(now==m){
        return dp[now][s];
    }
    for(int i=0;i<n;i++){
        if(s&(1<<i)) continue;
        dp[now][s]=max(dp[now][s],p[i][now]+dfs(now+1,(s|(1<<i))));
    }
    return dp[now][s];
}
int main(){
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                scanf("%lf",&p[i][j]);
            }
        }
        memset(vis,false,sizeof vis);
        printf("Case #%d: %.5lf\n",cas,dfs(0,0));
    }
    return 0;
}
