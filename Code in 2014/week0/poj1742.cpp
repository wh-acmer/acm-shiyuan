#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stack>
using namespace std;
#define maxn 100010
int a[110],c[110];
int dp[maxn];
int n,m;
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        if(n==0 && m==0) break;
        memset(dp,-1,sizeof(dp)); dp[0]=0;
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        for(int i=0;i<n;i++) scanf("%d",&c[i]);
        for(int i=0;i<n;i++){
            for(int j=0;j<=m;j++){
                if(dp[j]>=0) dp[j]=c[i];
                else if(j<a[i] || dp[j-a[i]]<0) dp[j]=-1;
                else{
                    dp[j]=dp[j-a[i]]-1;
                }
            }
        }
        int ans=0;
        for(int i=1;i<=m;i++) ans+=(dp[i]>=0);
        printf("%d\n",ans);
    }
    return 0;
}
