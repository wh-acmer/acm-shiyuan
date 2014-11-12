#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
int a[100001];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        a[i]=i;
    for(int i=n;i>=n-k+1;i--)
        printf("%d ",a[i]);
    for(int i=1;i<n-k;i++)
        printf("%d ",a[i]);
    printf("%d\n",n-k);
    return 0;
}
