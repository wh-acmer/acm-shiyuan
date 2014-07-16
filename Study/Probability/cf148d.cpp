#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 1010
int w,b;
double dp[maxn][maxn],dragon[maxn][maxn];
int main(){
    while(scanf("%d%d",&w,&b)!=EOF){
        memset(dp,0,sizeof(dp));
        memset(dragon,0,sizeof(dragon));
        for(int i=1;i<=w;i++){
            dp[i][0]=1.0;
        }
        for(int i=1;i<=w;i++){
            for(int j=1;j<=b;j++){
                dp[i][j]=1.0*i/(i+j)+1.0*j/(i+j)*dragon[i][j-1];
                dragon[i][j] = 1.0*j / (i+j) * dp[i-1][j-1] * (i*1.0)/(i+j-1);
                dragon[i][j]+=1.0*j/(i+j)*dp[i][j-2]*(j-1.0)/(i+j-1);
            }
        }
        printf("%.12lf\n",dp[w][b]);
    }
    return 0;
}
