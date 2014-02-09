/*
    ¶þ·Ö
*/
#include <cstring>
#include <cmath>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
using namespace std;
int n,k;
vector<double>v;
bool ok(double x)
{
    int ans=0;
    for(int i=0;i<v.size();i++)
        ans+=(int)(v[i]/x);
    if(ans>=k)
        return 1;
    return 0;
}
int main()
{
    double length;
    scanf("%d%d",&n,&k);
    v.clear();
    double inf=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%lf",&length);
        inf=max(inf,length);
        v.push_back(length);
    }
    double l=0,r=inf;
    double mid;
    while(fabs(r-l)>1e-3)
    {
        mid=(l+r)/2;
        if(ok(mid))
            l=mid;
        else
            r=mid;
    }
    printf("%.2lf\n",floor(r*100)/100);
    return 0;
}
