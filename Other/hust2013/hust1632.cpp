/*
    题意：旋转一个正方形p度,求扫过的面积
    思路：大于90度的按90度算，其余的可以根据正方形的对角线分成四部分计算
    每部分由一个p度的扇形和两个全等的三角形构成。
*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
#define pi acos(-1.0)
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int L;
        double p;
        scanf("%d%lf",&L,&p);
        p=min(90.0,p);
        p/=180.0;
        p*=pi;
        double x=(pi/2-p)/2;
        double y=sin(pi/4)*L*sin(x)/sin(x+pi/4);
        double ans=y*sin(pi/4)*L*cos(pi/4);
        ans+=p*L*L/4;
        printf("%.2lf\n",ans*4);
    }
    return 0;
}
