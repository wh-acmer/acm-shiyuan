// Count
// http://acm.hdu.edu.cn/showproblem.php?pid=4472
// water

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
typedef long long LL;
#define N 1010
LL dp[N];
const LL mod=1000000007;
LL solve(int n){
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n]=0;
    for(int i=1;i<n;i++){
        if((n-1)%i==0){
            dp[n]+=solve((n-1)/i);
            dp[n]%=mod;
        }
    }
    return dp[n];
}
void init(){
    memset(dp,-1,sizeof dp);
    dp[1]=1;
    dp[2]=1;
}
int main(){
    init();
    int cas=0,n;
    while(scanf("%d",&n)!=EOF){
        printf("Case %d: %I64d\n",++cas,solve(n));
    }
    return 0;
}
