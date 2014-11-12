#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char str[110];
        __int64 n=0,mod;
        scanf("%s%I64d",str,&mod);
        int l=strlen(str);
        if(l>=7)
            n=mod-1;
        else
        {
            int tnt=1;
            for(int i=l-1;i>=0;i--)
            {
                n+=tnt*(str[i]-'0');
                tnt*=10;
            }
        }
        if(n>=mod)
            n=mod-1;
        __int64 tmp=1;
        __int64 ans=1;
        for(int i=1;i<=n;i++)
        {
            tmp=(tmp*i)%mod;
            ans=(ans+tmp)%mod;
        }
        printf("%I64d\n",ans%mod);
    }
    return 0;
}
