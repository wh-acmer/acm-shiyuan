// Pole Arrangement
// http://uva.onlinejudge.org/external/16/1638.pdf
// dp

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
typedef long long LL;
#define N 21
LL dp[N][N][N];
void init(){
    memset(dp,0,sizeof dp);
    dp[1][1][1]=1;
    dp[2][2][1]=1;
    dp[2][1][2]=1;
    for(int i=3;i<N;i++){
        for(int j=1;j<=i;j++){
            for(int k=1;k<=i;k++){
                dp[i][j][k]=dp[i-1][j-1][k]+dp[i-1][j][k-1]+dp[i-1][j][k]*(i-2);
            }
        }
    }
}
int main(){
    init();
    int T;
    scanf("%d",&T);
    while(T--){
        int n,l,r;
        scanf("%d%d%d",&n,&l,&r);
        printf("%lld\n",dp[n][l][r]);
    }
    return 0;
}
