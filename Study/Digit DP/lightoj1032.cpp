#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
#define N 32
int bit[N];
LL dp[N][N][2];
LL dfs(int pos,int sum,int pre,int limit){
    if(pos<0){
        return sum;
    }
    if(!limit && dp[pos][sum][pre]!=-1){
        return dp[pos][sum][pre];
    }
    int li=limit?bit[pos]:1;
    LL ans=0;
    for(int i=0;i<=li;i++){
        ans+=dfs(pos-1,sum+(pre==1 && i==1),i,limit&&(i==li));
    }
    if(!limit){
        dp[pos][sum][pre]=ans;
    }
    return ans;
}
LL solve(LL n){
    int cnt=0;
    while(n){
        bit[cnt++]=n&1;
        n>>=1;
    }
    return dfs(cnt-1,0,0,1);
}
int main(){
    memset(dp,-1,sizeof dp);
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++){
        LL n;
        scanf("%lld",&n);
        printf("Case %d: %lld\n",cas,solve(n));
    }
    return 0;
}
