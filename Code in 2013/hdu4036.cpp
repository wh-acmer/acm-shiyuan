/*
    ¶þ·Ö
*/
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstdio>
using namespace std;
#define eps 1e-12
const double g = 20.0 ;
struct node
{
    double r,v;
    int x,h;
    int tag;
}p[2100];
int n,m,w;
bool cmp(node a,node b)
{
    if(a.x==b.x)
    {
        return a.tag;
    }
    return a.x<b.x;
}
bool ok(double mid)
{
    double nowv=mid;;
    for(int i=2;i<m+n;i++)
    {
        nowv=sqrt(nowv*nowv-2*g*(p[i].x-p[i-1].x)*p[i-1].r);
        if(p[i].tag==0)
        {
            p[i].r=p[i-1].r;
            if(nowv<p[i].v)
                return false;
        }
    }
    return true;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        int hmx=-100000001,sth;
        scanf("%d%d%d",&n,&m,&w);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&p[i].x,&p[i].h);
            hmx=max(hmx,p[i].h);
            p[i].tag=1; // ¹Õµã
        }
        sth=p[1].h;
        for(int i=1;i<n;i++)
        {
            p[i].r=(0.0+p[i+1].h-p[i].h)/(p[i+1].x-p[i].x);
        }
        for(int i=n+1;i<=n+m;i++)
        {
            scanf("%d%lf%d",&p[i].x,&p[i].v,&w);
            p[i].tag=0;
        }
        sort(p+1,p+m+n+1,cmp);
        //for(int i=1;i<=m+n;i++)
           // cout<<p[i].x<<":"<<p[i].v<<":"<<p[i].tag<<":"<<p[i].r<<endl;

        double r,l,mid;
        l=sqrt(2.0*g*(hmx-sth));
        r=100000000.0;
        double ans=-1;
        for(int u = 0;u < 100;u++)
        {
            mid=(l+r)/2;
            //cout<<mid<<endl;
            if(ok(mid))
            {
                r=mid;
                ans=mid;
            }
            else
                l=mid;
        }
        printf("Case %d: %.2lf\n",cas,ans);
    }
    return 0;
}
