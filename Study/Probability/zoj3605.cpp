#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int n,m,s,K;
double dp[60][60][60];
int a[60],b[60];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d",&n,&m,&K,&s);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=m;i++){
            scanf("%d%d",&a[i],&b[i]);
        }
        for(int i=0;i<=m;i++){
            dp[i][0][s]=1;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=i;j++){
                int x=a[i],y=b[i];
                for(int k=1;k<=n;k++){
                    if(k==x || k==y){
                        dp[i][j][x]+=dp[i-1][j-1][y]/2;
                        dp[i][j][x]+=dp[i-1][j][x]/2;

                        dp[i][j][y]+=dp[i-1][j-1][x]/2;
                        dp[i][j][y]+=dp[i-1][j][y]/2;
                    }
                    else{
                        dp[i][j][k]+=dp[i-1][j-1][k];
                        dp[i][j][k]+=dp[i-1][j][k];
                    }
                }
            }
        }
        int ans=-1;
        double mx=-1;
        for(int i=1;i<=n;i++){
            if(dp[m][K][i]>mx){
                mx=dp[m][K][i];
                ans=i;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
