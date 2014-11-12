#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;
bool is_ok(int n)
{
    int cnt=(int)sqrt(n);
    cnt*=cnt;
    if(cnt==n)
        return 1;
    return 0;
}
int main()
{
    int n;
    scanf("%d",&n);
    int ans=0;
    for(int i=1;i<=n;i+=3)
        for(int j=i+1;j<=n;j++)
        {
            if(i*i+j*j>n*n)
                break;
            if(is_ok(i*i+j*j))
                ans++;
        }
    for(int i=2;i<=n;i+=3)
        for(int j=i+1;j<=n;j++)
        {
            if(i*i+j*j>n*n)
                break;
            if(is_ok(i*i+j*j))
                ans++;
        }
    for(int i=3;i<=n;i+=3)
        for(int j=i+1;j<=n;j++)
        {
            if(i*i+j*j>n*n)
                break;
            if(is_ok(i*i+j*j))
                ans++;
        }
        printf("%d\n",ans);
        return 0;
}
