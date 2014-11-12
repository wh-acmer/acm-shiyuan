#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
#define maxn 100010
int c[maxn],t[maxn];
struct Song
{
    int start,end;
}song[maxn];
int tmp=0;
int search_for_the_song(int v,int l,int r)
{
    int mid=(l+r)/2;
    if(song[mid].start<=v&&v<=song[mid].end)
        return mid;
    else if(song[mid].end<v)
        return search_for_the_song(v,mid+1,r);
    else
        return search_for_the_song(v,l,mid-1);
}
int main()
{
    int m,n;
    scanf("%d%d",&n,&m);
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&c[i],&t[i]);
        song[++tmp].start=++cnt;
        cnt+=c[i]*t[i]-1;
        song[tmp].end=cnt;
    }
    int v;
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&v);
        printf("%d\n",search_for_the_song(v,1,tmp));
    }
    return 0;
}
