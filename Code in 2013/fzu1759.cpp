/*
    water
*/
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <sstream>
using namespace std;
typedef long long LL;
LL Pow(LL a,LL b,LL mod)
{
    LL ans=1;
    while(b)
    {
        if(b&1)
        {
            b--;
            ans=(ans*a)%mod;
        }
        else
        {
            b/=2;
            a=(a*a)%mod;
        }
    }
    return ans;
}
LL euler(LL n)
{
    if(n==1)
        return 0;
    LL i,res=n;
    for(i=2;i*i<=n;i++)
        if(n%i==0)
        {
            res=res/i*(i-1);
            while(n%i==0)
                n/=i;
        }
    if(n>1)
        res=res/n*(n-1);
    return res;
}

int main()
{
    LL a,b,c;
    string str;
    while(cin>>a>>str>>c)
    {
        b=0;
        LL phi=euler(c);
        for(int i=0;i<str.size();i++)
        {
            b=(b*10+str[i]-'0')%phi;
        }
        b+=phi;
        LL ans=Pow(a,b,c);
        cout<<ans<<endl;
    }
    return 0;
}
