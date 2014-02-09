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
int n,m,x;
vector<int>day;
bool ok(int mid)
{
    int now=0;
    int part=m;
    while(now<n&&part)
    {
        if(mid<day[now])
            return false;
        int cnt=mid-day[now];
        now++;
        while(now<n&&cnt>=day[now])
        {
            cnt-=day[now++];
        }
        part--;
    }
    if(part>=0&&now==n)
        return true;
    return false;
}
int main()
{
    scanf("%d%d",&n,&m);
    int l=0,r=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        l=max(l,x);
        r+=x;
        day.push_back(x);
    }
    r++;
    l--;
    while(r-l>1)
    {
        int mid=(l+r)/2;
        if(ok(mid))
            r=mid;
        else
            l=mid;
    }
    printf("%d\n",r);
    return 0;
}
/*
13 9
8 5 8 7 2 8 5 7 6 4 7 6 10
*/
