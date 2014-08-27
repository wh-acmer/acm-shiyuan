#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int dp[1<<14];
int main(){
    int n,m,x,y,z;
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(dp,0,sizeof dp);
        for(int i=1;i<=n;i++){
            scanf("%d",&x);
            int z=0;
            for(int j=1;j<=x;j++){
                scanf("%d",&y);
                z|=(1<<(y-1));
            }
            dp[z]=1;
            for(int j=0;j<(1<<14);j++){
                if(dp[j]){
                    dp[j|z]=1;
                }
            }
        }
        int ans=0;
        for(int i=0;i<(1<<14);i++){
            if(dp[i]){
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
