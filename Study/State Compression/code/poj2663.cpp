#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
typedef long long LL;
LL dp[31][7];
int main(){
    dp[0][0]=1;
    for(int i=1;i<=30;i++){
        dp[i][0]=dp[i-1][1]+dp[i-1][4]+dp[i-1][7];
        dp[i][1]=dp[i-1][6]+dp[i-1][0];
        dp[i][2]=dp[i-1][5];
        dp[i][3]=dp[i-1][4];
        dp[i][4]=dp[i-1][0]+dp[i-1][3];
        dp[i][5]=dp[i-1][2];
        dp[i][6]=dp[i-1][1];
        dp[i][7]=dp[i-1][0];
    }
    int n;
    while(scanf("%d",&n)!=EOF){
        if(n==-1) break;
        printf("%lld\n",dp[n][0]);
    }
    return 0;
}
