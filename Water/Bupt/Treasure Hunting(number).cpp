/// http://coder.buct.edu.cn/JudgeOnline/problem.php?cid=1021&pid=1
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
int prime[26]={0,2,3,5,7,11,
      13,17,19,23,29,
      31,37,41,43,47,
      53,59,61,67,71,
      73,79,83,89,97};
unsigned long long cnt[26];
unsigned long long tmp[26];
int solve(unsigned long long x)
{
    unsigned long long ans;
    for(int i=1;i<=25;i++)
    {
        ans=x;
        tmp[i]=0;
        unsigned long long num=prime[i];
        while(ans>=num)
        {
            tmp[i]+=ans/num;
            num*=prime[i];
        }
    }
    for(int i=1;i<=25;i++)
        if(tmp[i]<cnt[i])
            return 0;
    return 1;
}
unsigned long long search(unsigned long long l,unsigned long long r)
{
    unsigned long long mid;
    while(l<=r)
    {
         mid=(l+r)/2;
         if(solve(mid))
            r=mid-1;
         else
            l=mid+1;
    }
    return l;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        memset(cnt,0,sizeof(cnt));
        unsigned long long a,b;
        for(int i=1;i<=n;i++)
        {
            scanf("%llu%llu",&a,&b);
            for(int j=1;j<=25;j++)
            {
                if(a<prime[j])
                    break;
                if(a%prime[j]==0)
                {
                    while(a%prime[j]==0)
                    {
                        a/=prime[j];
                        cnt[j]+=b;
                    }
                }
            }
        }
        int tag=0;
        for(int i=1;i<=25;i++)
        {
            if(cnt[i]!=0)
            {
                tag=1;
                break;
            }
        }
        if(tag)
        {
            unsigned long long l=0,r=10000000000000000ll;
            unsigned long long ans=search(l,r);
            printf("%llu\n",ans);
        }
        else
            printf("0\n");
    }
    return 0;
}
