/*
    water
*/
#include <cstring>
#include <cmath>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>
#include <cstdio>
using namespace std;
#define maxn 1000000
bool ok[maxn];
int fun(int n)
{
    int ans=0;
    while(n)
    {
        ans+=n%10;
        n/=10;
    }
    return ans;
}
int main()
{
    memset(ok,0,sizeof(ok));
    int tmp;
    for(int i=1;i<=maxn;i++)
    {
        tmp=i+fun(i);
        if(tmp<=maxn)
            ok[tmp]=1;
    }
    for(int i=1;i<=maxn;i++)
        if(!ok[i])
            printf("%d\n",i);
    return 0;
}
