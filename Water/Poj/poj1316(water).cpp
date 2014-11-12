#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int vis[10001];
int fun(int n)
{
    int ans=n;
    while(n)
    {
        ans+=n%10;
        n/=10;
    }
    return ans;
}
int main()
{
    memset(vis,0,sizeof(vis));
    for(int i=1;i<10001;i++)
    {
        vis[fun(i)]=1;
    }
    for(int i=1;i<=10000;i++)
    {
        if(vis[i]==0)
            printf("%d\n",i);
    }
    return 0;
}
