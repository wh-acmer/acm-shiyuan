#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;
typedef long long LL;
#define N 10
int bit[N];
int dp[N][3];
int dfs(int pos,int status,int limit){
    if(pos==0){
        return status==2;
    }
    if(!limit && dp[pos][status]!=-1){
        return dp[pos][status];
    }
    int s,li=limit?bit[pos]:9;
    int ans=0;
    for(int i=0;i<=li;i++){
        if(status==0){
            if(i==6) s=1;
            else if(i==4) s=2;
            else s=0;
        }
        else if(status==1){
            if(i==2) s=2;
            else if(i==4) s=2;
            else if(i==6) s=1;
            else s=0;
        }
        else{
            s=2;
        }
        ans+=dfs(pos-1,s,limit&&i==li);
    }
    if(!limit){
        dp[pos][status]=ans;
    }
    return ans;
}
int solve(int n){
    int tmp=n;
    for(int i=1;i<N;i++){
        bit[i]=n%10;
        n/=10;
    }
    memset(dp,-1,sizeof dp);
    return tmp-dfs(N-1,0,1);
}
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        if(n==0 && m==0) break;
        printf("%d\n",solve(m)-solve(n-1));
    }
    return 0;
}
