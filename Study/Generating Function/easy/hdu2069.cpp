/*
    generating function
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
typedef long long LL;
#define N 255
int val[5]={1,5,10,25,50};
int dp[N][N],ddp[N][N];
int ans[N];
int main(){
    memset(dp,0,sizeof(dp));
    for(int i=0;i<N;i++) dp[i][i]=1;
    memcpy(ddp,dp,sizeof(dp));
    for(int i=1;i<5;i++){
        for(int j=0;j<N;j++){
            for(int l=0;l<=100;l++){
                for(int k=val[i];k+j<N;k+=val[i]){
                    if(l+k/val[i]<=100) dp[k+j][l+k/val[i]]+=ddp[j][l];
                }
            }
        }
        memcpy(ddp,dp,sizeof(ddp));
    }
    for(int i=0;i<N;i++){
        ans[i]=0;
        for(int j=0;j<=100;j++) ans[i]+=dp[i][j];
    }
    ans[0]=1;
    int n;
    while(scanf("%d",&n)!=EOF){
        printf("%d\n",ans[n]);
    }
    return 0;
}
/*
brute force

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
int val[6]={0,50,25,10,5,1};
int num[6];
int main(){
    int n,ans;
    while(scanf("%d",&n)!=EOF){
        ans=0;
        for(int i=1;i<=5;i++) num[i]=n/val[i];
        int x1,x2,x3,x4,x5;
        for(x1=0;x1<=num[1];x1++)
            for(x2=0;x2<=num[2];x2++)
                for(x3=0;x3<=num[3];x3++)
                    for(x4=0;x4<=num[4];x4++){
                        x5=n-x1*val[1]-x2*val[2]
                        -x3*val[3]-x4*val[4];
                        if(x5>=0 && x1+x2+x3+x4+x5<=100)
                            ans++;
                    }
        printf("%d\n",ans);
    }
    return 0;
}
*/
