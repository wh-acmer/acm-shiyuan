#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
#define maxn 200010
typedef long long LL;
LL a[maxn];
LL dp[maxn];
int main(){
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF){
        a[0]=0;
        for(int i=1;i<=n;i++) scanf("%I64d",&a[i]),a[i]+=a[i-1];
        for(int i=1;i+k-1<=n;i++) dp[i]=a[i+k-1]-a[i-1];
        int x1=n-k-k+1,x2=n-k+1;
        int y1=x1,y2=x2;
        LL mx1=dp[x1]+dp[x2],mx2=dp[x2];
        for(int i=n-k-k;i>=1;i--){
            if(dp[i+k]>=mx2)    mx2=dp[i+k],x2=i+k;
            LL tmp=dp[i]+mx2;
            if(tmp>=mx1)  mx1=tmp,y1=i,y2=x2;
        }
        printf("%d %d\n",y1,y2);
    }
    return 0;
}
