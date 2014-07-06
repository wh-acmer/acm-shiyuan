#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
#define N 32
#define inf 10000
#define pi acos(-1.0)
#define eps 1e-8
double x[N],y[N];
int T,n;
double cal(double c){
    double miX=inf,maX=-inf,miY=inf,maY=-inf;
    for(int i=0;i<n;i++){
        double rX=x[i]*cos(c)-y[i]*sin(c);
        double rY=x[i]*sin(c)+y[i]*cos(c);
        miX=min(miX,rX);
        miY=min(miY,rY);
        maX=max(maX,rX);
        maY=max(maY,rY);
    }
    return max(maY-miY,maX-miX);
}
double solve(){
    double l=0.0,r=pi/2,mid,midmid;
    while(l+eps<r){
        mid=(l+r)/2;
        midmid=(mid+r)/2;
        if(cal(mid)<=cal(midmid)){
            r=midmid;
        }
        else{
            l=mid;
        }
    }
    return cal(mid)*cal(mid);
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%lf%lf",&x[i],&y[i]);
        }
        printf("%.2lf\n",solve());
    }
    return 0;
}
