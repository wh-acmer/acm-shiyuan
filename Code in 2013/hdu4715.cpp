/*
    water
*/
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
set<int>s;
#define maxn 2001000
bool vis[maxn];
int main()
{
    memset(vis,true,sizeof(vis));
    vis[0]=vis[1]=0;
    s.clear();
    for(int i=2;i<maxn;i++)
        if(vis[i])
        {
            s.insert(i);
            for(int j=2*i;j<maxn;j+=i)
                vis[j]=0;
        }
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        bool tag=1;
        if(n>0)
            tag=0;
        else
            n*=-1;
        set<int>::iterator it=s.begin();
        while(vis[*it+n]==0&&it!=s.end()&&(*it+n<maxn))
            it++;
        if(it==s.end())
            printf("FALL\n");
        else
        {
            if(!tag)
                printf("%d %d\n",*it+n,*it);
            else
                printf("%d %d\n",*it,*it+n);
        }
    }
    return 0;
}
