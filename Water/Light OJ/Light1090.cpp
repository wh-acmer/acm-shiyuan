#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int solve(int n,int x)
{ /// ¼ÆËãn!ÖÐxµÄÃÝ
    int tmp=x;
    int ans=0;
    while(n>=tmp)
    {
        ans+=n/tmp;
        tmp*=x;
    }
    return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int cases=1;cases<=t;cases++)
    {
        int n,r,p,q;
        scanf("%d%d%d%d",&n,&r,&p,&q);
        long long ans=0;
        int n_2=0,n_5=0;
        while(p%2==0)
        {
            p/=2;
            n_2++;
        }
        while(p%5==0)
        {
            p/=5;
            n_5++;
        }
        n_2*=q;
        n_5*=q;
        int m_2=0,m_5=0;
        m_2+=solve(n,2)-solve(n-r,2)-solve(r,2);
        m_5+=solve(n,5)-solve(n-r,5)-solve(r,5);
        ans=min(n_2+m_2,n_5+m_5);
        printf("Case %d: %lld\n",cases,ans);
    }
    return 0;
}
