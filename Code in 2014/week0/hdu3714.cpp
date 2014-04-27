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
#define maxn 10010
#define eps 1e-12
typedef long long LL;
double a[maxn],b[maxn],c[maxn];
int n;
double cal(double x){
    double ans=a[0]*x*x+b[0]*x+c[0];
    for(int i=1;i<n;i++)
        ans=max(ans,a[i]*x*x+b[i]*x+c[i]);
    return ans;
}
double solve(){
    double l=0,r=1001,mid,midmid;
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
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%lf%lf%lf",&a[i],&b[i],&c[i]);
        printf("%.4lf\n",solve());
    }
    return 0;
}
