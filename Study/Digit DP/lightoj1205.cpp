#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long LL;
#define N 20
LL dp[N][N][2];
int bit[N];
int vis[N];
LL dfs(int pos,int len,int ok,int limit){
    if(pos<0){
        return ok;
    }
    if(!limit && dp[pos][len][ok]!=-1){
        return dp[pos][len][ok];
    }
    LL ans=0;
    int li=limit?bit[pos]:9;
    for(int i=0;i<=li;i++){
        vis[pos]=i;
        if(pos==len && i==0){
            ans+=dfs(pos-1,len-1,ok,limit&(i==li));
        }
        else if(ok && pos<(len+1)/2){
            ans+=dfs(pos-1,len,i==vis[len-pos],limit&(i==li));
        }
        else{
            ans+=dfs(pos-1,len,ok,limit&(i==li));
        }
    }
    if(!limit){
        dp[pos][len][ok]=ans;
    }
    return ans;
}
LL solve(LL n){
    int cnt=0;
    while(n){
        bit[cnt++]=n%10;
        n/=10;
    }
    return dfs(cnt-1,cnt-1,1,1);
}
int main(){
    int T;
    scanf("%d",&T);
    memset(dp,-1,sizeof dp);
    for(int cas=1;cas<=T;cas++){
        LL l,r;
        scanf("%lld%lld",&l,&r);
        if(l>r) swap(l,r);
        printf("Case %d: %lld\n",cas,solve(r)-solve(l-1));
    }
    return 0;
}
