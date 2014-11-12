#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define maxn 20001
int a[maxn];
int b[maxn];
int main()
{
    int m,n;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(m==0&&n==0)
            break;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=m;i++)
            scanf("%d",&b[i]);
        sort(a+1,a+n+1);
        sort(b+1,b+m+1);
        int tou=1;
        int sum=0;
        int tag=0;
        for(int i=1;i<=m;i++)
        {
            if(b[i]>=a[tou])
            {
                //printf("%d......%d\n",b[i],a[tou]);
                sum+=b[i];
                tou++;
            }
            if(tou==n+1)
            {
                tag=1;
                break;
            }
        }
        if(tag)
            printf("%d\n",sum);
        else
            printf("Loowater is doomed!\n");
    }
    return 0;
}
