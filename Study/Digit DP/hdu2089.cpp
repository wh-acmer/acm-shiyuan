#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;
typedef long long LL;
#define N 10
int dp[N][3];
// dp[i][0] 表示不存在 不吉利数
// dp[i][1] 表示不存在 不吉利数 且 最高位为2
// dp[i][2] 表示存在不吉利数
void init(){
    memset(dp,0,sizeof dp);
    dp[0][0]=1;
    for(int i=1;i<N;i++){
        dp[i][0]=dp[i-1][0]*9-dp[i-1][1];
        dp[i][1]=dp[i-1][0];
        dp[i][2]=dp[i-1][2]*10+dp[i-1][1]+dp[i-1][0];
    }
}
int bit[N];
int solve(int n){
    for(int i=1;i<N;i++){
        bit[i]=n%10;
        n/=10;
    }
    int ans=0,tag=0;
    for(int i=N-1;i>=1;i--){
        ans+=bit[i]*dp[i-1][2];
        if(tag){
            ans+=bit[i]*dp[i-1][0];
        }
        else{
            if(bit[i]>4){
                ans+=dp[i-1][0];
            }
            if(bit[i]>6){
                ans+=dp[i-1][1];
            }
            if(bit[i+1]==6 && bit[i]>2){
                ans+=dp[i][1];
            }
        }
        if(bit[i]==2 && bit[i+1]==6){
            tag=1;
        }
        if(bit[i]==4){
            tag=1;
        }
    }
    return ans;
}
int main(){
    int n,m;
    init();
    while(scanf("%d%d",&n,&m)!=EOF){
        if(n==0 && m==0) break;
        printf("%d\n",(m+1-solve(m+1))-(n-solve(n)));
    }
    return 0;
}
