/*
    ¶þ·Ö
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#define pi acos(-1.0)
using namespace std;
double x,y,v;
int is_ok(double mid)
{
    double vx=v*cos(mid);
    double vy=v*sin(mid);
    double t=x/vx;
    if(fabs(vy*t-4.9*t*t-y)<1e-7)
        return 0;
    else if(vy*t-4.9*t*t>y)
        return 1;
    else
        return -1;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf%lf",&x,&y,&v);
        double l=0,r=pi/2;
        double mid=(l+r)/2;
        while(l<r)
        {
            if(is_ok(mid)==0)
                break;
            else if(is_ok(mid)>0)
                r=mid;
            else
                l=mid;
            mid=(l+r)/2;
        }
        if(mid>0&&mid<pi/2)
            printf("%.6lf\n",mid);
        else
            printf("-1\n");
    }
    return 0;
}
