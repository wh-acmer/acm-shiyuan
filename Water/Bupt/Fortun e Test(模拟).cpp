///http://coder.buct.edu.cn/JudgeOnline/problem.php?cid=1023&pid=2
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#define mod 101
using namespace std;
long long Pow(int x,int y)
{ /// (x*10^y)%mod
    int tmp=10;
    long long ans=x%mod;
    while(y)
    {
        if(y&1)
        {
            y--;
            ans=(ans*tmp)%mod;
        }
        else
        {
            y/=2;
            tmp=(tmp*tmp)%mod;
        }
    }
    return ans;
}
int digit(int x)
{
    int ans=0;
    while(x)
    {
        ans++;
        x/=10;
    }
    return ans;
}
void solve(string a)
{
    int l=a.length();
    long long ans=0;
    int tmp=0;
    for(int i=l-1;i>=0;i--)
    {
        //cout<<a[i]<<"~"<<endl;
        int cnt=(a[i]-'a'+1);
        cnt=cnt*cnt;
        ans=(ans+Pow(cnt,tmp))%mod;
        tmp+=digit(cnt);
    }
    printf("%lld\n",ans);
}
int main()
{
    string a;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        cin>>a;
        solve(a);
    }
    return 0;
}
