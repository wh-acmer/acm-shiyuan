#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long LL;
LL dp[201][201];
int main(){
    memset(dp,0,sizeof(dp)); dp[1][1]=1;
    for(int i=2;i<201;i++){
        for(int j=1;j<=i;j++){
            dp[i][j]=dp[i-1][j-1]+dp[i-j][j];
        }
    }
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF){
        if(n==0 && k==0) return 0;
        printf("%lld\n",dp[n][k]);
    }
    return 0;
}
