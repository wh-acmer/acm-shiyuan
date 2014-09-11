#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;
typedef long long LL;
#define N 20
int bit[N];
LL dp[N][N/2];
LL dfs(int pos,int re,int limit){
    if(pos<0){
        return re==0;
    }
    if(!limit && dp[pos][re]!=-1){
        return dp[pos][re];
    }
    int li=limit?bit[pos]:9;
    LL ans=0;
    for(int i=0;i<=li;i++){
        ans+=dfs(pos-1,(re+i)%10,limit&&(i==li));
    }
    if(!limit){
        dp[pos][re]=ans;
    }
    return ans;

}
LL solve(LL n){
    int cnt=0;
    while(n){
        bit[cnt++]=n%10;
        n/=10;
    }
    memset(dp,-1,sizeof dp);
    return dfs(cnt-1,0,1);
}
int main(){
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++){
        LL a,b;
        scanf("%I64d%I64d",&a,&b);
        printf("Case #%d: %I64d\n",cas,solve(b)-solve(a-1));
    }
    return 0;
}
