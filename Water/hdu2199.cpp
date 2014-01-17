/*
    water
    函数是单调的，直接二分，注意一下上下限
*/
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
#define eps 1e-10
double cal(double x){
    return 8*pow(x,4.0)+7*pow(x,3.0)+2*pow(x,2.0)+3*x+6;
}
int main(){
    int T;
    double y;
    scanf("%d",&T);
    while(T--){
        scanf("%lf",&y);
        double l=0.0,r=100.0,mid;
        if(y<6||y>807020306){
            printf("No solution!\n");
            continue;
        }
        while(r-l>eps){
            mid=(l+r)/2;
            if(cal(mid)+eps<y){
                l=mid;
            }
            else{
                r=mid;
            }
        }
        printf("%.4lf\n",mid);
    }
    return 0;
}
