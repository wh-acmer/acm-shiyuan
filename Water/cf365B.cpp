#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define maxn 100010
int dp[maxn];
int a[maxn];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        dp[0]=0;
        int ans=1;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(i==1) dp[i]=1;
            else if(i==2) dp[i]=2;
            else {
                if(a[i]==a[i-1]+a[i-2]){
                    dp[i]=dp[i-1]+1;
                }
                else dp[i]=2;
            }
            ans=max(ans,dp[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
