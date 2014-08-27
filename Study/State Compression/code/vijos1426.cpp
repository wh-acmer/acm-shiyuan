#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
LL dp[5000010];
int f[6];
int val[201][6];
int hash(int i1,int i2,int i3,int i4,int i5){
    return i1+i2*(f[1]+1)+i3*(f[1]+1)*(f[2]+1)+i4*(f[1]+1)*(f[2]+1)*(f[3]+1)+i5*(f[1]+1)*(f[2]+1)*(f[3]+1)*(f[4]+1);
}
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=1;i<=m;i++){
            scanf("%d",&f[i]);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<=m;j++){
                scanf("%d",&val[i][j]);
            }
        }
        LL ans=0;
        memset(dp,0,sizeof dp);
        for(int i=0;i<n;i++){
            for(int i1=f[1];i1>=val[i][1];i1--){
                for(int i2=f[2];i2>=val[i][2];i2--){
                    for(int i3=f[3];i3>=val[i][3];i3--){
                        for(int i4=f[4];i4>=val[i][4];i4--){
                            for(int i5=f[5];i5>=val[i][5];i5--){
                                int j=hash(i1,i2,i3,i4,i5);
                                int k=hash(i1-val[i][1],i2-val[i][2],i3-val[i][3],i4-val[i][4],i5-val[i][5]);
                                if(dp[j]<dp[k]+val[i][0]){
                                    dp[j]=dp[k]+val[i][0];
                                }
                                if(dp[j]>ans){
                                    ans=dp[j];
                                }
                            }
                        }
                    }
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
