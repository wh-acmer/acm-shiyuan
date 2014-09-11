#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;
typedef long long LL;
#define N 20
LL dp[N][3];
int bit[N];
void init(){
    memset(dp,-1,sizeof dp);
}
LL dfs(int pos,int status,int limit){
    if(pos==0){
        return status==2;
    }
    if(!limit && dp[pos][status]!=-1){
        return dp[pos][status];
    }
    int li=limit?bit[pos]:9,s;
    LL ans=0;
    for(int i=0;i<=li;i++){
        if(status==0){
            if(i==4) s=1;
            else s=0;
        }
        if(status==1){
            if(i==4) s=1;
            else if(i==9) s=2;
            else s=0;
        }
        if(status==2){
            s=2;
        }
        ans+=dfs(pos-1,s,limit&&i==li);
    }
    if(!limit){
        dp[pos][status]=ans;
    }
    return ans;
}
LL solve(LL n){
    for(int i=1;i<N;i++){
        bit[i]=n%10;
        n/=10;
    }
    return dfs(N-1,0,1);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        LL n;
        scanf("%I64d",&n);
        init();
        printf("%I64d\n",solve(n));
    }
    return 0;
}
