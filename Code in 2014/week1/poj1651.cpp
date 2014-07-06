#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <cstdio>
using namespace std;
#define N 110
int dp[N][N],a[N];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        memset(dp,0,sizeof(dp));
        for(int j=2;j<n;j++){
            dp[j-2][j]=a[j-2]*a[j-1]*a[j];
            for(int i=j-3;i>=0;i--){
                dp[i][j]=min(a[i]*a[i+1]*a[j]+dp[i+1][j],a[i]*a[j-1]*a[j]+dp[i][j-1]);
                for(int k=i;k<=j;k++){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+a[i]*a[k]*a[j]);
                }
            }
        }
        /*for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                printf("%d ",dp[i][j]);
            }
            printf("\n");
        }*/
        printf("%d\n",dp[0][n-1]);
    }
    return 0;
}
