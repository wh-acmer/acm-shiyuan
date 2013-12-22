#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
#define maxn 11
typedef long long LL;
LL dp[maxn][2];
int a[maxn];
LL mx(LL a,LL b,LL c){
    return max(a,max(b,c));
}
LL mi(LL a,LL b,LL c){
    return min(a,min(b,c));
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        memset(dp,0,sizeof(dp));
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        dp[1][0]=a[1];
        dp[1][1]=a[1];
        for(int i=2;i<=n;i++){
            dp[i][0]=max(mx(dp[i-1][0]+a[i],dp[i-1][0]-a[i],dp[i-1][0]*a[i]),
                         mx(dp[i-1][1]+a[i],dp[i-1][1]-a[i],dp[i-1][1]*a[i]));
            dp[i][1]=min(mi(dp[i-1][0]+a[i],dp[i-1][0]-a[i],dp[i-1][0]*a[i]),
                         mi(dp[i-1][1]+a[i],dp[i-1][1]-a[i],dp[i-1][1]*a[i]));
        }
        printf("%lld\n",dp[n][1]);
    }
    return 0;
}
