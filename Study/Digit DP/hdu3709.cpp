#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;
typedef long long LL;
#define N 20
LL dp[N][N][9*(N+1)*N/2];
int bit[N];
LL x,y;
LL dfs(int pos,int cen,int val,int limit){
    if(pos==0){
        return val==0;
    }
    if(val<0) return 0;
    if(!limit && dp[pos][cen][val]!=-1){
        return dp[pos][cen][val];
    }
    int li=limit?bit[pos]:9;
    LL ans=0;
    for(int i=0;i<=li;i++){
        ans+=dfs(pos-1,cen,val+(pos-cen)*i,limit&&(i==li));
    }
    if(!limit){
        dp[pos][cen][val]=ans;
    }
    return ans;
}
LL solve(LL n){
    int cnt=0;
    while(n){
        bit[++cnt]=n%10;
        n/=10;
    }
    bit[cnt+1]=0;
    LL ans=0;
    for(int i=1;i<=cnt;i++){
        ans+=dfs(cnt,i,0,1);
    }
    return ans-cnt+1;
}
int main(){
    int T;
    scanf("%d",&T);
    memset(dp,-1,sizeof dp);
    while(T--){
        scanf("%I64d%I64d",&x,&y);
        printf("%I64d\n",solve(y)-solve(x-1));
    }
    return 0;
}
