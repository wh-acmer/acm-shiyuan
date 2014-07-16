#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define N 129
double p[N][N],dp[8][N];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        if(n<0) break;
        int m=(1<<n);
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                scanf("%lf",&p[i][j]);
            }
        }
        memset(dp,0,sizeof(dp));
        for(int i=0;i<m;i++){
            dp[0][i]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<m;k++){
                    if((j>>(i-1)) == ((k>>(i-1))^1) ){
                        dp[i][j]+=dp[i-1][j]*dp[i-1][k]*p[j][k];
                    }
                }
            }
        }
        int ans=1;
        double mx=0;
        for(int i=0;i<m;i++){
            if(dp[n][i]>mx){
                ans=i;
                mx=dp[n][i];
            }
        }
        printf("%d\n",ans+1);
    }
    return 0;
}
