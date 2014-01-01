#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define maxn 110
int dp[maxn][2*maxn];
int a[maxn];
int main(){
    int L,n,X,Y;
    while(scanf("%d%d%d%d",&L,&n,&X,&Y)!=EOF){
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=X+Y;j++){
                if(j>i) break;
                if(j==0) dp[i][j]=max(dp[i][j],((L>=a[i])?1:0)+max(dp[i-1][0],dp[i-1][X+Y]));
                else if(j==1) dp[i][j]=max(dp[i][j],((min(5,L+1)>=a[i])?1:0)+max(dp[i-1][0],dp[i-1][X+Y]));
                else if(j>1 && j<=X) dp[i][j]=max(dp[i][j],((min(5,L+1)>=a[i])?1:0)+dp[i-1][j-1]);
                else if(j>X && j<=X+Y) dp[i][j]=max(dp[i][j],((0>=a[i])?1:0)+dp[i-1][j-1]);
            }
        }
        int ans=0;
        for(int i=0;i<=X+Y;i++) ans=max(ans,dp[n][i]);
        printf("%d\n",ans);
    }
    return 0;
}
