// Sum of Different Primes
// http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemId=1822
// dp water

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define N 1150
bool vis[N];
vector<int>v;
void init(){
    v.clear();
    memset(vis,true,sizeof vis);
    vis[0]=vis[1]=false;
    for(int i=2;i<N;i++){
        if(vis[i]){
            v.push_back(i);
            for(int j=2*i;j<N;j+=i){
                vis[j]=false;
            }
        }
    }
}
int dp[N][15];
void solve(){
    memset(dp,0,sizeof dp);
    dp[0][0]=1;
    for(int i=0;i<v.size();i++){
        for(int j=N-1;j>=v[i];j--){
            for(int k=14;k>0;k--){
                dp[j][k]+=dp[j-v[i]][k-1];
            }
        }
    }
}
int main(){
    init();
    solve();
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF){
        if(n==0 && k==0) break;
        printf("%d\n",dp[n][k]);
    }
    return 0;
}
