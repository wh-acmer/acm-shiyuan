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
#define eps 1e-9
double H,h,D;
double cal(double x){
    // 墙上影子不存在
    if(x*H<=D*(H-h)) return x*h/(H-h);
    return H+D-(x+((H-h)*D)/x);
}
double solve(){
    double l=0,r=D,mid,midmid;
    while(l+eps<r){
        mid=(l+r)/2;
        midmid=(mid+r)/2;
        if(cal(mid)>=cal(midmid)) r=midmid;
        else l=mid;
    }
    return cal(mid);
}
int main(){
    int T; scanf("%d",&T);
    while(T--){
        scanf("%lf%lf%lf",&H,&h,&D);
        printf("%.3lf\n",solve());
    }
    return 0;
}
