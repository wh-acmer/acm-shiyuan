#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#define pi acos(-1.0)
using namespace std;
double R,r,H,V;
double getV(double mid)
{
    double Rr=r+mid/H*(R-r);
    return pi/3*(Rr*Rr+Rr*r+r*r)*mid;
}
int is_ok(double mid)
{
    if(fabs(getV(mid)-V)<1e-9)
        return 0;
    if(getV(mid)>V)
        return -1;
    else
        return 1;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf%lf%lf",&r,&R,&H,&V);
        double l=0,r=H;
        double mid;
        while(l<r)
        {
            mid=(l+r)/2;
            if(is_ok(mid)==0)
                break;
            else if(is_ok(mid)>0)
                l=mid;
            else
                r=mid;
        }
        printf("%.6lf\n",mid);
    }
    return 0;
}
