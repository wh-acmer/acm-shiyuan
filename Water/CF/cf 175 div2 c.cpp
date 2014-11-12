#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
int a[300010];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    long long ans=0;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        ans+=abs(a[i]-i);
    printf("%I64d\n",ans);
    return 0;
}
