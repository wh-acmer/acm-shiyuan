#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;
#define maxn 2010
int n,A,B,T;
double p[maxn*2][5];
double dp[maxn*2][5];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&A,&B);
        memset(p,0,sizeof(p));
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=4;j++){
                scanf("%lf",&p[i][j]);
            }
        }
        for(int i=n+1;i<=n+A;i++){
            p[i][4]=1;
        }
        dp[0][4]=1;
        for(int i=0;i<=n;i++){
            double p2=1,p3=1,p4=1;
            for(int j=A;j<=B;j++){
                dp[i+j][3]+=dp[i][2]*p2*p[i+j][3];
                dp[i+j][4]+=dp[i][2]*p2*p[i+j][4];
                p2*=(p[i+j][1]+p[i+j][2]);
                dp[i+j][2]+=dp[i][3]*p3*p[i+j][2];
                dp[i+j][4]+=dp[i][3]*p3*p[i+j][4];
                p3*=(p[i+j][1]+p[i+j][3]);
                dp[i+j][2]+=dp[i][4]*p4*p[i+j][2];
                dp[i+j][3]+=dp[i][4]*p4*p[i+j][3];
                dp[i+j][4]+=dp[i][4]*p4*p[i+j][4];
                p4*=p[i+j][1];
            }
        }
        double ans=0;
        for(int i=1;i<=n+A;i++){
            for(int j=2;j<=4;j++){
                ans+=dp[i][j];
            }
        }
        printf("%.8lf\n",ans);
    }
    return 0;
}
