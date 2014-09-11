#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;
typedef long long LL;
#define N 52
LL dp[N][N][N];
LL dfs(int n,int k,int m){
    if(k==1){
        return n>0 && n<=m;
    }
    if(dp[n][k][m]!=-1){
        return dp[n][k][m];
    }
    LL ans=0;
    for(int i=1;i<=m;i++){
        if(n-i>0)
            ans+=dfs(n-i,k-1,m);
    }
    return dp[n][k][m]=ans;
}
int main(){
    memset(dp,-1,sizeof dp);
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++){
        int k,n,m;
        scanf("%d%d%d",&n,&k,&m);
        printf("Case %d: %lld\n",cas,dfs(n,k,m));
    }
    return 0;
}

