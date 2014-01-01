#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
#define maxn 100010
int dpr[maxn],dpl[maxn];
int a[maxn];
int main(){
    int n;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        dpl[0]=0;
        for(int i=1;i<=n;i++) dpl[i]=dpl[i-1]+(a[i]>=0);
        dpr[n+1]=0;
        for(int i=n;i>=1;i--) dpr[i]=dpr[i+1]+(a[i]<=0);
        int ans=maxn;
        for(int i=1;i<n;i++){
            ans=min(ans,dpl[i]+dpr[i+1]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
