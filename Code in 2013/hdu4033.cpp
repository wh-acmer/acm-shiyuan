/*
    ¶þ·Ö
*/
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstdio>
using namespace std;
#define eps 1e-9
#define pi acos(-1.0)
double d[110];
int n;
bool legal(double a,double b,double c)
{
    if(a+b<c || a+c<b || b+c<a)
        return false;

    return true;
}
bool ok(double mid)
{
    for(int i=1;i<n;i++)
        if(!legal(d[i],d[i+1],mid))
            return false;
    if(!legal(d[n],d[1],mid))
        return false;
    return true;
}
double cc(double a,double b,double c)
{
    return (a*a+b*b-c*c)/(2*a*b);
}
double fabs(double x)
{
    return x>0?x:-x;
}
int erfen(double x)
{
    double ans=0,tmp;
    for(int i=1;i<n;i++)
    {
        tmp=cc(d[i],d[i+1],x);
        tmp=acos(tmp);
        ans+=tmp;
    }
    ans+=acos(cc(d[n],d[1],x));
    if(ans>2*pi)
        return -1;
    if(fabs(ans-2*pi)<eps)
        return 0;
    return 1;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%lf",&d[i]);
            d[i]*=100;
        }
        double l=0.0,r=2000000000.0,mid;
        double ans=-1;
        bool laputa=0;
        while(r-l>eps)
        {
            mid=(r+l)/2;
            //cout<<mid<<endl;
            if(!ok(mid))
            {
                r=mid;
                continue;
            }
            int p=erfen(mid);
            if(p==0)
            {
                laputa=1;
                ans=mid;
                break;
            }
            else if(p==1)
                l+=(mid-l)/2;
            else
                r-=(r-mid)/2;
        }
        if(laputa)
            printf("Case %d: %.3lf\n",cas,mid/100);
        else
            printf("Case %d: impossible\n",cas);
    }
    return 0;
}
