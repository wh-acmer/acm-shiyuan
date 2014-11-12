#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;
int a[210];
int main()
{
    int n;
    scanf("%d",&n);
    int sum=0;
    int cnt=0;
    for(int i=1;i<=2*n-1;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]<0)
        {
            cnt++;
            a[i]*=-1;
        }
    }
    sort(a+1,a+2*n);
    if((n%2==0)&&(cnt&1))
        sum-=2*a[1];
    for(int i=1;i<=2*n-1;i++)
        sum+=a[i];
    printf("%d\n",sum);
    return 0;
}
