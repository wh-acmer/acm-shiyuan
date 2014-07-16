#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define maxn 2010
int hp1,hp2;
double p1[7],p2[7];
double dp[maxn][maxn];
/// dp[i][j] 表示分别伤害对方i,j的概率
int main(){
    while(scanf("%d%d",&hp1,&hp2)!=EOF){
        for(int i=1;i<=6;i++){
            scanf("%lf",&p1[i]);
        }
        for(int i=1;i<=6;i++){
            scanf("%lf",&p2[i]);
        }
        double win=0,lose=0;
        for(int i=1;i<=6;i++){
            for(int j=1;j<=6;j++){
                if(i>j){
                    win+=p1[i]*p2[j];
                }
                if(i<j){
                    lose+=p1[i]*p2[j];
                }
            }
        }
        double total=win+lose;
        win/=total;
        lose/=total;
        for(int i=0;i<=hp2;i++){
            for(int j=0;j<=hp1;j++){
                if(i==0 && j==0) dp[i][j]=1;
                else dp[i][j]=0;
                if(i>0 && j<hp1) dp[i][j]+=dp[i-1][j]*win;
                if(j>0 && i<hp2) dp[i][j]+=dp[i][j-1]*lose;
            }
        }
        double ans=0;
        for(int i=0;i<hp1;i++){
            ans+=dp[hp2][i];
        }
        printf("%.6lf\n",ans);
    }
    return 0;
}
