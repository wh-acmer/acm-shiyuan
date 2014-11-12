#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;
#define maxn 100010
int a[maxn],b[maxn];
int ans1[maxn],ans2[maxn];
bool ok;
void query()
{
    int m,x;
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d",&x);
        x++;
        if(ok || x%3==0)
        {
            printf("%d\n",a[x]);
        }
        else
        {
            if(x%3==1)
                printf("%d\n",ans1[x]);
            else
                printf("%d\n",ans2[x]);
        }
    }
    return ;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int index=-1;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]!=-1 && i%3!=0)
                index=i;
        }
        a[0]=0,a[n+1]=0;
        ok=false;
        for(int i=1;i<=n;i++)
            scanf("%d",&b[i]);
        for(int i=3;i<=n;i+=3) // 形如a[i%3==0]的项可以全部求出来
            a[i]=b[i-1]-b[i-2]+a[i-3];
        for(int i=n-2;i>=1;i-=3)
            a[i]=b[i+1]-b[i+2]+a[i+3];
        if((n-2)%3==1 || (n-2)%3==2)
        {
            for(int i=1;i<=n;i++)
                if(a[i]==-1)
                    a[i]=b[i]-a[i-1]-a[i+1];
            ok=1;
        }
        if(ok)
        {
            query();
            continue;
        }
        if(index!=-1)
        { // 从index处推出所有的情况
            if(index%3==1)
            {
                a[index+1]=b[index+1]-a[index+2]-a[index];
                for(int i=index+3;i<=n;i++)
                    a[i]=b[i-1]-a[i-2]-a[i-1];
                for(int i=index-1;i>=1;i--)
                    a[i]=b[i+1]-a[i+2]-a[i+1];
            }
            else if(index%3==2)
            {
                for(int i=index+2;i<=n;i++)
                    a[i]=b[i-1]-a[i-2]-a[i-1];
                for(int i=index-1;i>=1;i--)
                    a[i]=b[i+1]-a[i+2]-a[i+1];
            }
            ok=1;
            query();
            continue;
        }
        //不然就只好贪心了
        for(int i=1;i<=n;i++)
        {
            if(a[i]==-1 && a[i+1]==-1 && i%3==1)
                index=i;
        }
        // 当找到连续满足这样的情况时，可以令i%3==1的那个取得尽量大的
        memcpy(ans1,a,sizeof(a));
        ans1[index]=b[index+1]-ans1[index+2];
        ans1[index+1]=0;
        int mx=0;
        for(int i=index+3;i<=n;i++)
        {
            ans1[i]=b[i-1]-ans1[i-2]-ans1[i-1];
            if(i%3==2)
                mx=min(mx,ans1[i]);
        }
        for(int i=index-2;i>=1;i--)
        {
            ans1[i]=b[i+1]-ans1[i+2]-ans1[i+1];
            if(i%3==2)
                mx=min(mx,ans1[i]);
        }
        if(mx<0)
            for(int i=1;i<=n;i+=3)
                ans1[i]+=mx;
        memcpy(ans2,a,sizeof(a));
        ans2[index+1]=b[index+1]-a[index+2];
        ans2[index]=0;
        mx=0;
        for(int i=index+3;i<=n;i++)
        {
            ans2[i]=b[i-1]-ans2[i-1]-ans2[i-2];
            if(i%3==1)
                mx=min(ans2[i],mx);
        }
        for(int i=index-1;i>=1;i--)
        {
            ans2[i]=b[i+1]-ans2[i+1]-ans2[i+2];
            if(i%3==1)
                mx=min(mx,ans2[i]);
        }
        if(mx<0)
            for(int i=2;i<=n;i+=3)
                ans2[i]+=mx;
        query();
    }
    return 0;
}
