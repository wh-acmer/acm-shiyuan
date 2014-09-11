#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;
typedef long long LL;
#define N 12
LL dp[N][N*(N-1)/2][2];
int bit[N];
LL dfs(int pos,int sum,int lead,int limit){
    if(pos<0){
        return sum;
    }
    if(!limit && dp[pos][sum][lead]!=-1){
        return dp[pos][sum][lead];
    }
    int li=limit?bit[pos]:9;
    LL ans=0;
    for(int i=0;i<=li;i++){
        ans+=dfs(pos-1,sum+(i==0&&lead),lead||i,limit&&(i==li));
    }
    if(!limit){
        dp[pos][sum][lead]=ans;
    }
    return ans;

}
LL solve(LL n){
    if(n==-1) return -1;
    int cnt=0;
    while(n){
        bit[cnt++]=n%10;
        n/=10;
    }
    return dfs(cnt-1,0,0,1);
}
int main(){
    memset(dp,-1,sizeof dp);
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++){
        LL m,n;
        scanf("%lld%lld",&m,&n);
        printf("Case %d: %lld\n",cas,solve(n)-solve(m-1));
    }
    return 0;
}
