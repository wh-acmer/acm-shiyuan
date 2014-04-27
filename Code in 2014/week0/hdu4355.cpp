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
#include <map>
using namespace std;
#define maxn 50010
#define eps 1e-6
typedef long long LL;
double x[maxn],w[maxn],mx,mi;
int n;
double tri(double y){
    if(y<0) y*=-1;
    return y*y*y;
}
double cal(double y){
    double ans=0;
    for(int i=0;i<n;i++)
        ans+=tri(x[i]-y)*w[i];
    return ans;
}
double solve(){
    double l=mi,r=mx,mid,midmid;
    while(l+eps<r){
        mid=(l+r)/2;
        midmid=(r+mid)/2;
        if(cal(mid)+eps<cal(midmid)) r=midmid;
        else l=mid;
    }
    return cal(l);
}
int main(){
    int T,cas=0; scanf("%d",&T);
    while(T--){
        scanf("%d",&n); mx=-1000010,mi=-mx;
        for(int i=0;i<n;i++) scanf("%lf%lf",&x[i],&w[i]),mx=max(mx,x[i]),mi=min(mi,x[i]);
        printf("Case #%d: %.0lf\n",++cas,solve());
    }
    return 0;
}
