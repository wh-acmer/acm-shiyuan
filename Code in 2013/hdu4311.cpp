/*
    ‘§¥¶¿Ì
*/
#include <cstring>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
#define maxn 100010
struct node
{
    long long x,y,l,r,u,d;
}p[maxn];
bool cmp1(node a,node b)
{
    return a.x<b.x;
}
bool cmp2(node a,node b)
{
    return a.y<b.y;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%I64d%I64d",&p[i].x,&p[i].y);
        if(n==1)
        {
            printf("0\n");
            continue;
        }
        sort(p,p+n,cmp1);
        p[0].l=0;
        for(int i=1;i<n;i++)
            p[i].l=p[i-1].l+i*(p[i].x-p[i-1].x);
        p[n-1].r=0;
        for(int i=n-2;i>=0;i--)
            p[i].r=p[i+1].r+(n-1-i)*(p[i+1].x-p[i].x);

        sort(p,p+n,cmp2);
        p[n-1].u=0;
        for(int i=n-2;i>=0;i--)
            p[i].u=p[i+1].u+(n-1-i)*(p[i+1].y-p[i].y);
        p[0].d=0;
        for(int i=1;i<n;i++)
            p[i].d=p[i-1].d+i*(p[i].y-p[i-1].y);
        long long ans=1;
        ans<<=62;
        for(int i=0;i<n;i++)
            ans=min(ans,p[i].u+p[i].l+p[i].r+p[i].d);
        printf("%I64d\n",ans);
    }
    return 0;
}
