#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
#define maxn 2010
#define eps 1e-9
double dp[maxn][maxn];
int main(){
    int n,m,k;
    double p1,p2,p3,p4;
    while(scanf("%d%d%d%lf%lf%lf%lf",&n,&m,&k,&p1,&p2,&p3,&p4)!=EOF){
        if(fabs(p4)<eps){
            printf("%.5lf\n",0.0);
            continue;
        }
        p2/=1-p1,p3/=1-p1,p4/=1-p1;
        memset(dp,0,sizeof(dp));
        dp[1][1]=p4/(1-p2);
        for(int i=2;i<=n;i++){
            double e1=p2,e2=p4;
            for(int j=2;j<=i;j++){
                e1*=p2;
                e2*=p2;
                e2+=p3*dp[i-1][j-1];
                if(j<=k){
                    e2+=p4;
                }
            }
            dp[i][i]=e2/(1-e1);
            dp[i][1]=p2*dp[i][i]+p4;
            for(int j=2;j<i;j++){
                dp[i][j]=p2*dp[i][j-1]+p3*dp[i-1][j-1];
                if(j<=k) dp[i][j]+=p4;
            }
        }
        printf("%.5lf\n",dp[n][m]);
    }
    return 0;
}
