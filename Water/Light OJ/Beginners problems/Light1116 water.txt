#include <cstdio>
#include <iostream>
using namespace std;
int t;
int main()
{
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        long long n;
        scanf("%lld",&n);
        printf("Case %d: ",i);
        if(n&1)
        {
            printf("Impossible\n");
        }
        else
        {
            long long ans=1;
            while(n%2==0)
            {
                ans*=2;
                n/=2;
            }
            printf("%lld %lld\n",n,ans);
        }
    }
    return 0;
}
