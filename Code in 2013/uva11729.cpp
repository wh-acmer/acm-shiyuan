/*
    water
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
struct node{
    int t1,t2;
}p[1001];
bool cmp(node a,node b)
{
    return a.t2>b.t2;
}
int main()
{
    int n;
    int cases=0;
    while(scanf("%d",&n)!=EOF,n)
    {
        for(int i=0;i<n;i++)
            scanf("%d %d",&p[i].t1,&p[i].t2);
        sort(p,p+n,cmp);
        int ans=0;
        int tmp=0;
        for(int i=0;i<n;i++)
        {
            tmp+=p[i].t1;
            ans=max(ans,tmp+p[i].t2);
        }
        printf("Case %d: ",++cases);
        printf("%d\n",ans);
    }
    return 0;
}
