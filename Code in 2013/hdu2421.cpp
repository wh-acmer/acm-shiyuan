/*
    math

����˵�ĺܼ򵥣��������ֽ⣬Ȼ���Լ��������3���ݵĺ͡�
����i^3��ǰn���=(n*(n+1)/2)^2
����A^B=p1^x1 * p2^x2 * ... * pn^xn
��ô���е�Լ���������� (1+p1)*(1+p2)*...*(1+pn)
Ȼ���Ҿ�ֱ�Ӱ���������Ǹ�n��͵Ĺ�ʽ��������ˣ�һ������Wa������
�����Ƚ�������Ķ���p���ݵ���ʽ�����Ծ���һ�ӵ��ġ�
����ÿ��Լ����Լ�������������Կ����������Ǹ�ʽ�ӵ�չ��ʽ��
���Զ���ĳһ��������p�Լ�������x���ܲ�����Ӱ���Ǵ�0��x�ֱ����������������������ϣ�
��������һ�����Ժ�������ô����ֻ��Ҫ��ÿ�������ӵ��ݴ��������������С�
*/
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;
#define mod 10007
#define maxn 1000100
bool vis[maxn];
vector<long long>v;
long long cnt;
void Prime()
{
    memset(vis,true,sizeof(vis));
    vis[0]=vis[1]=0;
    v.clear();
    for(int i=2;i<maxn;i++)
    {
        if(vis[i])
        {
            v.push_back(i);
            for(int j=2*i;j<maxn;j+=i)
                vis[j]=false;
        }
    }
    //cout<<v.size()<<":"<<v[v.size()-1]<<endl;
}
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
long long niyuan(long long a)
{
    long long x,y;
    exgcd(a,mod,x,y);
    x=(x%mod+mod)%mod;
    return x;
}
int main()
{
    Prime();
    long long a,b;
    int cas=0;
    while(cin>>a>>b)
    {
        //b%=mod;
        long long ans=1,pika=1;
        for(int i=0;i<v.size()&&v[i]*v[i]<=a;i++)
        {
            if(a%v[i]==0)
            {
                cnt=0;
                while(a%v[i]==0)
                {
                    a/=v[i];
                    cnt++;
                }
                ans=1;
                ans=(ans*(1+b*cnt))%mod;
                ans=(ans*(ans+1))%mod;
                ans=(ans*ans)%mod;
                ans=(ans*niyuan(4))%mod;
                pika=(pika*ans)%mod;
            }
        }
        if(a>1)
        {
            ans=1;
            ans*=(b+1);
            ans%=mod;
            ans=(ans*(ans+1))%mod;
            ans=(ans*ans)%mod;
            ans=(ans*niyuan(4))%mod;
            pika=(pika*ans)%mod;
        }
        cout<<"Case "<<++cas<<": "<<pika%mod<<endl;
    }
    return 0;
}
