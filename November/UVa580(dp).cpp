// Critical Mass
// http://uva.onlinejudge.org/external/5/580.pdf
// ¼ÇÒä»¯ËÑË÷

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
typedef long long LL;
const int N=32;
int dp[N][4][2];
LL dfs(int now,int s,int ok){
    if(dp[now][s][ok]!=-1) return dp[now][s][ok];
    LL ans=0;
    if(now==0){
        return dp[now][s][ok]=(ok==1);
    }
    int state=(s&1)<<1;
    if(ok){
        ans+=dfs(now-1,state|1,ok)+dfs(now-1,state,ok);
    }
    else{
        ans+=dfs(now-1,state|1,s==3)+dfs(now-1,state,ok);
    }
    return dp[now][s][ok]=ans;

}
int main(){
    int n;
    memset(dp,-1,sizeof dp);
    while(scanf("%d",&n)&&n){
       printf("%lld\n",dfs(n,0,0));
    }
    return 0;
}
