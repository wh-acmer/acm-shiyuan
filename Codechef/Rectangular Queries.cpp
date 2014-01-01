#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define maxn 310
int dp[11][maxn][maxn];
int main(){
    int n,x;
    while(scanf("%d",&n)!=EOF){
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&x);
                dp[x][i][j]=1;
            }
        }
        for(int k=1;k<=10;k++)
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    dp[k][i][j]+=dp[k][i][j-1];
                }
            }
        for(int k=1;k<=10;k++)
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    dp[k][j][i]+=dp[k][j-1][i];
                }
            }
        int q;
        scanf("%d",&q);
        while(q--){
            int x1,x2,y1,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            int ans=0;
            for(int k=1;k<=10;k++){
                if(dp[k][x2][y2]-(dp[k][x2][y1-1]+dp[k][x1-1][y2]-2*dp[k][x1-1][y1-1])-dp[k][x1-1][y1-1]>0)
                    ans++;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
