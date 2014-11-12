#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
int a[100001];
int main()
{
    int n,s,t;
    scanf("%d%d%d",&n,&s,&t);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    if(s==t)
    {
        printf("0\n");
        return 0;
    }
    int ans=0;
    int tag=1;
    while(s!=t)
    {
        ans++;
        if(s==a[s])
        {
            tag=0;
            break;
        }
        s=a[s];
        if(ans>100000)
        {
            tag=0;
            break;
        }
    }
    if(!tag)
        printf("-1\n");
    else
        printf("%d\n",ans);
    return 0;
}
