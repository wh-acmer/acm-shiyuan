#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;
typedef long long LL;
#define N 12
int bit[N];
LL dp[N][3][13];
LL dfs(int pos,int status,int remain,int limit){
    if(pos==0){
        return status==2 && remain==0;
    }
    if(!limit && dp[pos][status][remain]!=-1){
        return dp[pos][status][remain];
    }
    int li=limit?bit[pos]:9,s;
    LL ans=0;
    for(int i=0;i<=li;i++){
        int re=(remain*10+i)%13;
        if(status==0){
            if(i==1) s=1;
            else s=0;
        }
        else if(status==1){
            if(i==3) s=2;
            else if(i==1) s=1;
            else s=0;
        }
        else{
            s=2;
        }
        ans+=dfs(pos-1,s,re,limit&&li==i);
    }
    if(!limit){
        dp[pos][status][remain]=ans;
    }
    return ans;
}
LL solve(LL n){
    for(int i=1;i<N;i++){
        bit[i]=n%10;
        n/=10;
    }
    return dfs(N-1,0,0,1);
}
int main(){
    LL n;
    memset(dp,-1,sizeof dp);
    while(scanf("%I64d",&n)!=EOF){
        printf("%I64d\n",solve(n));
    }
    return 0;
}
