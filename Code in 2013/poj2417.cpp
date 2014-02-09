/*
    babystep
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#define maxn 65535
using namespace std;
struct hash
{
    int a,b,next;
}Hash[maxn*2];
int flg[maxn+66];
int top,idx;
void ins(int a,int b)
{
    int k=b&maxn;
    if(flg[k]!=idx)
    {
        flg[k]=idx;
        Hash[k].next=-1;
        Hash[k].a=a;
        Hash[k].b=b;
        return ;
    }
    while(Hash[k].next!=-1)
    {
        if(Hash[k].b==b)
            return ;
        k=Hash[k].next;
    }
    Hash[k].next=++top;
    Hash[top].next=-1;
    Hash[top].a=a;
    Hash[top].b=b;
}
int find(int b)
{
    int k=b&maxn;
    if(flg[k]!=idx)
        return -1;
    while(k!=-1)
    {
        if(Hash[k].b==b)
            return Hash[k].a;
        k=Hash[k].next;
    }
    return -1;
}
int gcd(int a,int b)
{
    return !b?a:gcd(b,a%b);
}
int exgcd(int a,int b,int &x,int &y)
{
    int t,ans;
    if(!b)
    {
        x=1;
        y=0;
        return a;
    }
    ans=exgcd(b,a%b,x,y);
    t=x;
    x=y;
    y=t-a/b*y;
    return ans;
}
int Inval(int a,int b,int n)
{
    int x,y,e;
    exgcd(a,n,x,y);
    e=(long long)x*b%n;
    return e<0?e+n:e;
}
int pow_mod(long long a,int b,int c)
{
    long long ans=1;
    a%=c;
    while(b)
    {
        if(b&1)
        {
            ans=ans*a%c;
        }
        a=a*a%c;
        b>>=1;
    }
    return ans;
}
int  BabyStep(int A,int B,int C)
{
    top=maxn;
    ++idx;
    long long buf=1%C,D=buf,K;
    int i,d=0,tmp;
    for(i=0;i<=100;buf=buf*A%C,i++)
        if(buf==B)
            return i;
    while((tmp=gcd(A,C))!=1)
    {
        if(B%tmp) return -1;
        ++d;
        C/=tmp;
        B/=tmp;
        D=D*A/tmp%C;
    }
    int M=(int)ceil(sqrt((double)C));
    for(buf=1%C,i=0;i<=M;buf=buf*A%C,++i)
        ins(i,buf);
    for(i=0,K=pow_mod((long long)A,M,C);i<=M;D=D*K%C,++i)
    {
        tmp=Inval((int)D,B,C);
        int w=find(tmp);
        if(tmp>=0&&w!=-1)
          return i*M+w+d;
    }
    return -1;
}
int main()
{
    int A,B,C;
    while(scanf("%d%d%d",&C,&A,&B)!=EOF)
    {
        B%=C;
        int tmp=BabyStep(A,B,C);
        if(tmp<0)
            printf("no solution\n");
        else
            printf("%d\n",tmp);
    }
    return 0;
}
