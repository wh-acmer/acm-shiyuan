#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;
typedef long long LL;
#define N 20
LL dp[N][3];
// dp[i][0]表示不含49的
// dp[i][1]表示不含49，但首位为9的
// dp[i][2]表示含49的
void init(){
    memset(dp,0,sizeof dp);
    dp[0][0]=1;
    for(int i=1;i<N;i++){
        dp[i][0]=dp[i-1][0]*10-dp[i-1][1];
        dp[i][1]=dp[i-1][0];
        dp[i][2]=dp[i-1][2]*10+dp[i-1][1];
    }
}
int bit[N];
LL solve(LL n){
    for(int i=1;i<N;i++){
        bit[i]=n%10;
        n/=10;
    }
    LL ans=0;
    int tag=0;
    for(int i=N-1;i>=1;i--){
        ans+=bit[i]*dp[i-1][2];
        if(tag){
            ans+=bit[i]*dp[i-1][0];
        }
        else{
            if(bit[i]>4){
                ans+=dp[i-1][1];
            }
            if(bit[i+1]==4 && bit[i]>9){ // impossible
                ans+=dp[i][1];
            }
        }
        if(bit[i]==9 && bit[i+1]==4){
            tag=1;
        }
    }
    return ans;
}
int main(){
    LL n;
    int T;
    init();
    scanf("%d",&T);
    while(T--){
        scanf("%I64d",&n);
        printf("%I64d\n",solve(n+1));
    }
    return 0;
}
