#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define maxn 500001
long long f[maxn];
map<int,int>m;
void init()
{
    m.clear();
    f[0]=0;
    m[0]++;
    for(int i=1;i<maxn;i++)
    {
        if(f[i-1]-i<0)
        {
            f[i]=f[i-1]+i;
            m[f[i]]++;
        }
        else if(m[f[i-1]-i])
        {
            f[i]=f[i-1]+i;
            m[f[i]]++;
        }
        else
        {
            f[i]=f[i-1]-i;
            m[f[i]]++;
        }
    }
}
int main()
{
    init();
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n<0)
            break;
        printf("%lld\n",f[n]);
    }
    return 0;
}
