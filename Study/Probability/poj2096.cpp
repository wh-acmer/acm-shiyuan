#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
#define maxn 1010
double dp[maxn][maxn];
int main(){
    int n,s;
    while(scanf("%d%d",&n,&s)!=EOF){
        memset(dp,0,sizeof(dp));
        for(int i=n;i>=0;i--){
            for(int j=s;j>=0;j--){
                if(i==n && j==s) continue;
                dp[i][j]=(dp[i+1][j] * (n-i+0.0)/n * j/s
                        + dp[i][j+1] * (s-j+0.0)/s * i/n
                        + dp[i+1][j+1] * (n-i+0.0)/n * (s-j+0.0)/s
                        + 1)
                        / (n*s-i*j) * n*s;
            }
        }
        printf("%lf\n",dp[0][0]);
    }
    return 0;
}
