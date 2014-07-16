#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
#define maxn 1010
double dp[maxn][2];
double p[50];
double dq[50][50];
int main(){
    int M,T,N;
    while(scanf("%d%d%d",&M,&T,&N)!=EOF){
        if(M==0 && T==0 && N==0) break;
        for(int t=1;t<=T;t++){
            for(int i=1;i<=M;i++){
                scanf("%lf",&p[i]);
            }
            dp[0][0]=1,dp[0][1]=0;
            memset(dq,0,sizeof(dq));
            dq[0][0]=1;
            for(int i=0;i<=M;i++){
                for(int j=0;j<=i;j++){
                    if(i-1>=0 && j-1>=0){
                        dq[i][j]+=dq[i-1][j-1]*p[i];
                    }
                    if(i-1>=0){
                        dq[i][j]+=dq[i-1][j]*(1-p[i]);
                    }

                }
            }
            double none=dq[M][0];
            double done=0;
            for(int i=1;i<N;i++){
                done+=dq[M][i];
            }
            double champion=1-none-done;
            dp[t][0]=dp[t-1][0]*done;
            dp[t][1]=dp[t-1][0]*champion+dp[t-1][1]*(1-none);
        }
        printf("%.3lf\n",dp[T][1]);
    }
    return 0;
}
