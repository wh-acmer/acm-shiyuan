#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
#define pi acos(-1.0)
#define eps 1e-6
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
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%lf%lf",&x,&y);
        for(int i=0;i<3;i++) scanf("%lf",&b[i]);
        sort(b,b+3);
        l=b[0],w=b[1];
        bool ok=false;
        if(solve()+eps<y){
            ok=true;
        }
        swap(l,w);
        if(solve()+eps<y){
            ok=true;
        }
        if(ok){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
    return 0;
}
