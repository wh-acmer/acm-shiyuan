#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
#define N 10
#define M 82
int bit[N];
int l,r,K;
int dp[N][M+1][M+1][M+1];
int dfs(int pos,int sum,int sd,int limit){
    if(pos<0){
        return sum==0 && sd==0;
    }
    if(!limit && dp[pos][sum][sd][K]!=-1){
        return dp[pos][sum][sd][K];
    }
    int li=limit?bit[pos]:9;
    int ans=0;
    for(int i=0;i<=li;i++){
        ans+=dfs(pos-1,(sum*10+i)%K,(sd+i)%K,limit && (i==li));
    }
    if(!limit){
        dp[pos][sum][sd][K]=ans;
    }
    return ans;

}
int solve(int n){
    int cnt=0;
    while(n){
        bit[cnt++]=n%10;
        n/=10;
    }
    return dfs(cnt-1,0,0,1);
}
int main(){
    int T;
    scanf("%d",&T);
    memset(dp,-1,sizeof dp);
    for(int cas=1;cas<=T;cas++){
        scanf("%d%d%d",&l,&r,&K);
        int ans=0;
        if(K<=M){
            ans=solve(r)-solve(l-1);
        }
        printf("Case %d: %d\n",cas,ans);
    }
    return 0;
}
