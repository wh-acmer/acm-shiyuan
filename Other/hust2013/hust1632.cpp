/*
    ���⣺��תһ��������p��,��ɨ�������
    ˼·������90�ȵİ�90���㣬����Ŀ��Ը��������εĶԽ��߷ֳ��Ĳ��ּ���
    ÿ������һ��p�ȵ����κ�����ȫ�ȵ������ι��ɡ�
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
