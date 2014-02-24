/*
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
double dp[2][105];
int main(){
    int c,m,n;
    while(scanf("%d",&c)!=EOF && c){
        scanf("%d%d",&n,&m);
        if(n<m || (n-m)&1 || m>c) printf("0.000\n");
        else{
            memset(dp,0,sizeof(dp));
            dp[0][0]=1;
            if(n>1000) n=1000+(n&1);
            int now=0;
            for(int i=1;i<=n;i++){
                for(int j=0;j<=c;j++){
                    dp[now^1][j]=0;
                    if(j-1>=0)  dp[now^1][j]+=dp[now][j-1]*(c-j+1.0)/c;
                    if(j+1<=c)  dp[now^1][j]+=dp[now][j+1]*(j+1.0)/c;
                }
                now^=1;
            }
            printf("%.3lf\n", dp[now][m]);
        }
    }
    return 0;
}
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
long double C[101][101];
void init(){
    for(int i=0;i<101;i++) for(int j=1;j<101;j++) C[i][j]=0.0;
    for(int i=0;i<101;i++) C[i][0]=C[i][i]=1.0;
    for(int i=2;i<101;i++) for(int j=1;j<i;j++) C[i][j]=C[i-1][j-1]+C[i-1][j];
}
int main(){
    init();
    int c,n,m;
    while(scanf("%d",&c)!=EOF && c){
        scanf("%d%d",&n,&m);
        if(m>c || n<m || (n-m)&1){
            printf("0.000\n");
            continue;
        }
        double ans=0,pnt;
        for(int s=0;s<=m;s++)
            for(int t=0;t<=c-m;t++){
                int cnt=c-2*(s+t);
                pnt=C[m][s]/pow(2.0,c+0.0)*C[c-m][t]*pow(1.0*cnt/c,n+0.0);
                if(s&1) ans-=pnt;
                else ans+=pnt;
            }
        for(int i=1;i<=c-m;i++) ans=ans*(m+i)/i;
        printf("%.3lf\n",ans);
    }
    return 0;
}
