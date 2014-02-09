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
int n,c;
vector<int>cow;
bool ok(int mid)
{
    int now=0;
    for(int i=1;i<c;i++)
    {
        int cnt=now+1;
        while(cnt<n&&cow[cnt]-cow[now]<mid)
            cnt++;
        now=cnt;
        if(cnt>=n)
            return false;
    }
    return true;
}
int main()
{
    cow.clear();
    scanf("%d%d",&n,&c);
    int x;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        cow.push_back(x);
    }
    sort(cow.begin(),cow.end());
    int l=-1,r=cow[cow.size()-1]-cow[0];
    int mid;
    while(r-l>1)
    {
        mid=(l+r)>>1;
        if(ok(mid))
            l=mid;
        else
            r=mid;
    }
    printf("%d\n",l);
    return 0;
}
