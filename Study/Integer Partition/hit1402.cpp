#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
#define N 52
LL dp1[N][N],dp2[N][N],dp5[N][N],dp4[N][N];
void init(){
    memset(dp1,0,sizeof(dp1));// i分成若干部分，每部分不大于j
    for(int i=0;i<N;i++)
        for(int j=1;j<N;j++){
            if(i==0 || j==1) dp1[i][j]=1;
            else if(i<j) dp1[i][j]=dp1[i][j-1];
            else dp1[i][j]=dp1[i][j-1]+dp1[i-j][j];
        }
    memset(dp2,0,sizeof(dp2)); // i恰好分成k部分
    for(int i=1;i<N;i++)
        for(int j=1;j<N;j++){
            if(j==1) dp2[i][j]=1;
            else if(i>=j) dp2[i][j]=dp2[i-1][j-1]+dp2[i-j][j];
        }
    memset(dp4,0,sizeof(dp4)); // i分成若干部分，每部分为不大于j的奇数
    for(int i=1;i<N;i+=2) dp4[0][i]=1;
    for(int i=1;i<N;i++){
        for(int j=1;j<N;j++){
            if(j&1){
                if(i>=j)
                    dp4[i][j]=dp4[i-j][j]+dp4[i][j-1];
                else
                    dp4[i][j]=dp4[i][j-1];
            }
            else{
                dp4[i][j]=dp4[i][j-1];
            }
        }
    }
    memset(dp5,0,sizeof(dp5)); // i分成若干部分每部分不同
    dp5[0][0]=1;
    for(int i=0;i<N;i++)
        for(int j=1;j<N;j++){
            if(i<j) dp5[i][j]=dp5[i][j-1];
            else if(i>=j) dp5[i][j]=dp5[i][j-1]+dp5[i-j][j-1];
        }
}

int main(){
    init();
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF){
        printf("%lld\n",dp1[n][n]);
        printf("%lld\n",dp2[n][k]);
        printf("%lld\n",dp1[n][k]);
        printf("%lld\n",dp4[n][n]);
        printf("%lld\n\n",dp5[n][n]);
    }
    return 0;
}


/*
    背包做法

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 52
typedef long long LL;
LL dp[N];
LL dfs(int n,int k){
    if(n==0) return 0;
    if(k==1) return 1;
    if(n<k) return 0;
    return dfs(n-k,k)+dfs(n-1,k-1);
}
int main(){
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF){
        memset(dp,0,sizeof(dp)); dp[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++)
                dp[j]+=dp[j-i];
        }
        printf("%lld\n",dp[n]); //  1
        printf("%lld\n",dfs(n,k)); // 2
        memset(dp,0,sizeof(dp)); dp[0]=1;
        for(int i=1;i<=k;i++){
            for(int j=i;j<=n;j++)
                dp[j]+=dp[j-i];
        }
        printf("%lld\n",dp[n]); // 3
        memset(dp,0,sizeof(dp)); dp[0]=1;
        for(int i=1;i<=n;i+=2){
            for(int j=i;j<=n;j++)
                dp[j]+=dp[j-i];
        }
        printf("%lld\n",dp[n]); // 4
        memset(dp,0,sizeof(dp)); dp[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=n;j>=i;j--)
                dp[j]+=dp[j-i];
        }
        printf("%lld\n\n",dp[n]); // 5
    }
    return 0;
}


*/
