/*
    角速度=线速度/半径
    在湖上人的角速度>=圆上人角速度之前，两人保持在同一个直径上
    两个角速度相等的情况是 v1/r = v2/R
*/
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
#define pi acos(-1.0)
int main(){
    double r,R,v1,v2;
    while(scanf("%lf%lf%lf",&R,&v1,&v2)!=EOF){
        r=v1/v2*R;
        if((R-r)/v1>pi*R/v2) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
