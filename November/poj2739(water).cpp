// Sum of Consecutive Prime Numbers
// http://poj.org/problem?id=2739
// water binary search

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
#define N 10010
bool vis[N];
vector<int>v;
LL dp[1500];
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
    dp[0]=0;
    for(int i=0;i<v.size();i++){
        dp[i+1]=dp[i]+v[i];
    }
}
bool can(int x){
    int index=lower_bound(dp,dp+1+v.size(),x)-dp;
    return dp[index]==x;
}
int main(){
    int n;
    init();
    while(scanf("%d",&n)&&n){
        int ans=0;
        for(int i=0;i<v.size();i++){
            if(can(dp[i]+n)){
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
