/*
    water
*/
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;
map<pair<int,int>,int>mp;
struct node
{
    int x,y;
}p[1010],p1,p2;
bool cmp(node a,node b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        mp.clear();
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&p[i].x,&p[i].y);
            mp[make_pair(p[i].x,p[i].y)]++;
        }
        sort(p,p+n,cmp);
        int i=0,j=0;
        int ans=0;
        while(i<n && j<n)
        {
            while(p[i].x==p[j+1].x && j+1<n)
                j++;
            for(int ii=i;ii<j;ii++)
                for(int jj=ii+1;jj<=j;jj++)
                {
                    p1.x=p[jj].y-p[ii].y+p[ii].x;
                    p2.x=p1.x;
                    p1.y=p[ii].y;
                    p2.y=p[jj].y;
                    //cout<<p1.x<<":"<<p1.y<<":"<<p2.x<<":"<<p2.y<<endl;
                    if(mp[make_pair(p1.x,p1.y)] && mp[make_pair(p2.x,p2.y)])
                        ans++;
                }
            j++;
            i=j;
        }
        printf("%d\n",ans);
    }
    return 0;
}
