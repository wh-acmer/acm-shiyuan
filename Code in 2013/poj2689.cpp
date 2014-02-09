/*
    分段筛法
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;
#define maxn 50000
int num[5200];
bool prime[maxn];
int n_prime=0;
bool cnt[1000001];//开始时，maxn设为100w，求出距离100w的数字间最多有78498个素数
map<unsigned __int64,int>m;
unsigned __int64 l,r;
void Prime()
{
    memset(prime,true,sizeof(prime));
    prime[0]=prime[1]=0;
    for(int i=2;i<maxn;i++)
        if(prime[i])
        {
            num[++n_prime]=i;
            for(int j=2*i;j<maxn;j+=i)
                prime[j]=0;
        }
    //cout<<n_prime<<":"<<num[n_prime]<<endl;
}
void make_prime()
{
    m.clear();
    unsigned __int64 tmp;
    memset(cnt,true,sizeof(cnt));
    for(int i=1;i<=n_prime;i++)
    {
        tmp=l/num[i];
        while(tmp*num[i]<l||tmp<=1)
            tmp++;
        for(unsigned __int64 j=tmp*num[i];j<=r;j+=num[i])
        {
            if(j>=l&&j<=r)
                cnt[j-l]=0;
        }
    }
    if(l==1)
        cnt[0]=0;
    for(unsigned __int64 i=0;i+l<=r;i++)
        if(cnt[i]&&i+l<=r&&i>=0)
            m[i+l]++;
}
int main()
{
    Prime();
    while(scanf("%I64u%I64u",&l,&r)!=EOF)
    {
        if(l>r)
            swap(l,r);
        make_prime();
        if(m.size()==1)
            cout<<"There are no adjacent primes."<<endl;
        else
        {
            map<unsigned __int64,int>::iterator it=m.begin(),ii=m.begin();
            ii++;
            unsigned __int64 mx=0,mi=1000001;
            unsigned __int64 a=-1,b=-1,c=-1,d=-1;
            for(;ii!=m.end();ii++,it++)
            {
                if(ii->first-it->first>mx)
                {
                    mx=ii->first-it->first;
                    c=it->first,d=ii->first;
                }
                if(ii->first-it->first<mi)
                {
                    mi=ii->first-it->first;
                    a=it->first,b=ii->first;
                }
            }
            printf("%I64u,%I64u are closest, %I64u,%I64u are most distant.\n",a,b,c,d);
        }
    }
    return 0;
}
