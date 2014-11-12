#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;
long long a[1000001];
long long f[1000001]={0};
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        priority_queue<long long>q;
        while(!q.empty())
            q.pop();
        long long sum=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
            sum+=a[i];
        }
        sum/=n;
        q.push(0);
        for(int i=1;i<n;i++)
        {
            f[i]=f[i-1]-(sum-a[i]);
            q.push(f[i]);
        }
        int cnt=q.size()/2;
        while(cnt--)
            q.pop();
        long long tmp=q.top();
        long long ans=0;
        for(int i=0;i<n;i++)
            ans+=abs(tmp-f[i]);
        printf("%lld\n",ans);
    }
    return 0;
}
