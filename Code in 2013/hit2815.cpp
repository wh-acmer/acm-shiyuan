/*
    water
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
long long exgcd(long long a,long long b,long long &x,long long &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    else
    {
        long long ans=exgcd(b,a%b,x,y);
        long long t=x;
        x=y;
        y=t-a/b*y;
        return ans;
    }
}
long long gcd(long long a,long long b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long a,b;
        cin>>a>>b;
        if(a>b)
            swap(a,b);
        if(gcd(a,b)!=1)
            cout<<-1<<endl;
        else
        {
            if(abs(a+b)==1||abs(a-b)==1)
            {
                cout<<1<<endl;
                continue;
            }
            long long x,y;
            exgcd(a,b,x,y);
            if(x==0||y==0)
            {
                cout<<2<<endl;
                continue;
            }
            int ans=abs(x)+abs(y)-1;
            cout<<ans<<endl;
        }
    }
    return 0;
}
