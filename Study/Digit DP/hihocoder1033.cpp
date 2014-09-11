#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>P;
#define mod 1000000007
#define N 20
P dp[N][N*9][2][2];
LL l,r,k,ten[N];
int bit[N];
void init(){
    ten[0]=1;
    for(int i=1;i<N;i++){
        ten[i]=(ten[i-1]*10)%mod;
    }
}
P dfs(int pos,int sum,int x,int lead,int limit){
    if(pos<0){
        if(sum==k) return P(0,1);
        return P(0,0);
    }
    if(!limit && dp[pos][sum][x][lead].second!=-1){
        return dp[pos][sum][x][lead];
    }
    int li=limit?bit[pos]:9;
    LL ans=0,cnt=0;
    if(lead==0) x=1;
    int p=1;
    if(x==0) p=-1;
    for(int i=0;i<=li;i++){
        P tmp=dfs(pos-1,sum+p*i,!x,lead||i,limit&&(i==li));
        ans+=tmp.second*i*ten[pos]+tmp.first;
        cnt+=tmp.second;
        ans%=mod,cnt%=mod;
    }
    if(!limit){
        dp[pos][sum][x][lead]=P(ans,cnt);
    }
    return P(ans,cnt);
}
LL solve(LL n){
    int cnt=0;
    while(n){
        bit[cnt++]=n%10;
        n/=10;
    }
    return dfs(cnt-1,100,1,0,1).first;
}
int main(){
    init();
    while(scanf("%lld%lld%lld",&l,&r,&k)!=EOF){
        memset(dp,-1,sizeof dp);
        k+=100;
        printf("%lld\n",(solve(r)-solve(l-1)+mod)%mod);
    }
    return 0;
}
