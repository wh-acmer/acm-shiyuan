#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;
#define N 9
int bit[N];
int x,y;
int dp[N][9*(1<<N)];
int dfs(int pos,int remain,int limit){
    if(pos<0){
        return remain>=0;
    }
    if(!limit && dp[pos][remain]!=-1){
        return dp[pos][remain];
    }
    int li=limit?bit[pos]:9;
    int ans=0;
    for(int i=0;i<=li;i++){
        if(remain>=i*(1<<pos)){
            ans+=dfs(pos-1,remain-i*(1<<pos),limit&&(i==li));
        }
    }
    if(!limit){
        dp[pos][remain]=ans;
    }
    return ans;
}
int solve(){
    int cnt=0;
    while(y){
        bit[cnt++]=y%10;
        y/=10;
    }
    int Fa=0,two=1;
    while(x){
        Fa+=two*(x%10);
        x/=10;
        two*=2;
    }
    return dfs(cnt-1,Fa,1);
}
int main(){
    int T;
    scanf("%d",&T);
    memset(dp,-1,sizeof dp);
    for(int cas=1;cas<=T;cas++){
        scanf("%d%d",&x,&y);
        printf("Case #%d: %d\n",cas,solve());
    }
    return 0;
}
