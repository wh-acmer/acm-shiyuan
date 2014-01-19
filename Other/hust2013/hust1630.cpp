/*
    题意：hdu原题，求最大子方块
    思路：dp枚举左边和右边比当前大的下标，枚举一遍
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define maxn 100010
int a[maxn],l[maxn],r[maxn];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        l[1]=1;
        for(int i=2;i<=n;i++){
            int tmp=i;
            while(tmp>1 && a[i]<=a[tmp-1]) tmp=l[tmp-1];
            l[i]=tmp;
        }
        r[n]=n;
        for(int i=n-1;i>=1;i--){
            int tmp=i;
            while(tmp<n && a[i]<=a[tmp+1]) tmp=r[tmp+1];
            r[i]=tmp;
        }
        long long ans=0;
        for(int i=1;i<=n;i++) ans=max(ans,(r[i]-l[i]+1ll)*a[i]);
        printf("%lld\n",ans);
    }
    return 0;
}
