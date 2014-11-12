#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int a[110];
char str[10];
int main()
{
    int t;
    scanf("%d",&t);
    for(int ii=1;ii<=t;ii++)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        while(m--)
        {
            scanf("%s",str);
            if(str[0]=='P')
            {
                int x,y;
                scanf("%d%d",&x,&y);
                x++;y++;
                swap(a[x],a[y]);
            }
            else if(str[0]=='R')
            {
                for(int i=1;i<=n/2;i++)
                    swap(a[i],a[n+1-i]);
            }
            else if(str[0]=='S')
            {
                int num;
                scanf("%d",&num);
                for(int i=1;i<=n;i++)
                    a[i]+=num;
            }
            else if(str[0]=='M')
            {
                int num;
                scanf("%d",&num);
                for(int i=1;i<=n;i++)
                    a[i]*=num;
            }
            else
            {
                int num;
                scanf("%d",&num);
                for(int i=1;i<=n;i++)
                    a[i]/=num;
            }
        }
        printf("Case %d:\n",ii);
        for(int i=1;i<n;i++)
            printf("%d ",a[i]);
        printf("%d\n",a[n]);
    }
    return 0;
}
