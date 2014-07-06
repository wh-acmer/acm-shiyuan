#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
#define pi acos(-1.0)
#define eps 1e-12
double x,y,l,w;
double b[3];
double cal(double angle){
    return (w*sin(angle)+l*cos(angle)-x)*tan(angle)+w*cos(angle);
}
double solve(){
    double l=0,r=pi/2,mid,midmid;
    while(l+eps<r){
        mid=(l+r)/2;
        midmid=(mid+r)/2;
        if(cal(mid)>=cal(midmid)){
            r=midmid;
        }
        else{
            l=mid;
        }
    }
    return cal(mid);
}
int main(){
    while(scanf("%lf%lf",&x,&y)!=EOF){
        scanf("%lf%lf",&l,&w);
        bool ok=false;
        if(solve()+eps<y){
            ok=true;
        }
        if(ok){
            printf("yes\n");
        }
        else{
            printf("no\n");
        }
    }
    return 0;
}
