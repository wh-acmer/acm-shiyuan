#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
using namespace std;
#define N 1010
#define eps 1e-6
double dp[N][N];
double p[N][N][3];
int main(){
    int R,C;
    while(scanf("%d%d",&R,&C)!=EOF){
        for(int i=1;i<=R;i++){
            for(int j=1;j<=C;j++){
                for(int k=0;k<=2;k++){
                    scanf("%lf",&p[i][j][k]);
                }
            }
        }
        memset(dp,0,sizeof(dp));
        for(int i=R;i>=1;i--){
            for(int j=C;j>=1;j--){
                if(i==R && j==C) continue;
                if(fabs(p[i][j][0]-1)>eps){
                    dp[i][j]=(1+dp[i][j+1]*p[i][j][1]+dp[i+1][j]*p[i][j][2])/(1-p[i][j][0]);
                }
            }
        }
        printf("%.3lf\n",dp[1][1]*2);
    }
    return 0;
}
