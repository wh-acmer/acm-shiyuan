/*
    ���ٶ�=���ٶ�/�뾶
    �ں����˵Ľ��ٶ�>=Բ���˽��ٶ�֮ǰ�����˱�����ͬһ��ֱ����
    �������ٶ���ȵ������ v1/r = v2/R
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
