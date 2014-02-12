/*
    water
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
struct point
{
    double x,y;
}p[110];
double area(point a,point b,point c)
{
    return fabs(a.x*b.y+a.y*c.x+b.x*c.y-c.x*b.y-b.x*a.y-a.x*c.y)/2;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        double ans=4010*4010;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                for(int k=j+1;k<n;k++)
                {
                    double tmp=area(p[i],p[j],p[k]);
                    if(tmp<1e-6)
                        continue;
                    ans=min(ans,tmp);
                }
        if(fabs(ans-4010*4010)<1e-3)
            printf("Impossible\n");
        else
            printf("%.2lf\n",ans);
    }
    return 0;
}
