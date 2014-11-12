#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
struct Matrix
{
    int m[40][40];
}E,D;
int n_num=0;
int num[110];
bool is_ok(int n)
{
    if(__builtin_popcount(n)!=2)
        return false;
    string s="";
    int tmp=n;
    while(tmp)
    {
        if(tmp%2==1)
            s="1"+s;
        else
            s="0"+s;
        tmp/=2;
    }
    while(s.size()<10)
        s="0"+s;
    for(int i=0;i<9;i++)
        if(s[i]=='1'&&s[i+1]=='1')
            return false;
    return true;
}
bool is_right(int x,int y)
{
    string s="",t="";
    int cnt=x,tmp=y;
    while(cnt)
    {
        if(cnt&1)
            s="1"+s;
        else
            s="0"+s;
        cnt/=2;
    }
    while(tmp)
    {
        if(tmp&1)
            t="1"+t;
        else
            t="0"+t;
        tmp/=2;
    }
    while(s.size()<10)
        s="0"+s;
    while(t.size()<10)
        t="0"+t;
    for(int i=0;i<=9;i++)
    {
        if(s[i]=='1')
        {
            if(i-1>=0)
            {
                if(t[i-1]=='1')
                    return false;
            }
            if(i+1<=10)
            {
                if(t[i+1]=='1')
                    return false;
            }
            if(t[i]=='1')
                return false;
        }
    }
    return true;
}
void Pre()
{
    for(int i=1;i<=(1<<9)+(1<<8);i++)
    {
        if(is_ok(i))
            num[++n_num]=i;
    }
    memset(D.m,0,sizeof(D.m));
    for(int i=1;i<=n_num;i++)
        for(int j=1;j<=n_num;j++)
        {
            if(is_right(num[i],num[j]))
                D.m[i][j]=1;
        }
}
void init()
{
    for(int i=1;i<=n_num;i++)
        for(int j=1;j<=n_num;j++)
            E.m[i][j]=(i==j);
}
Matrix Multi(Matrix A,Matrix B)
{
    Matrix ans;
    for(int i=1;i<=n_num;i++)
        for(int j=1;j<=n_num;j++)
        {
            ans.m[i][j]=0;
            for(int k=1;k<=n_num;k++)
                ans.m[i][j]+=A.m[i][k]*B.m[k][j];
        }
    return ans;
}
Matrix Pow(Matrix A,int k)
{
    Matrix ans=E;
    while(k)
    {
        if(k&1)
        {
            k--;
            ans=Multi(ans,A);
        }
        else
        {
            k/=2;
            A=Multi(A,A);
        }
    }
    return ans;
}
int main()
{
    Pre();
    init();
    /*
    for(int i=1;i<=n_num;i++)
    {
        for(int j=1;j<=n_num;j++)
            printf("%d ",D.m[i][j]);
        printf("\n");
    }*/
    int t;
    scanf("%d",&t);
    for(int cases=1;cases<=t;cases++)
    {
        int n;
        scanf("%d",&n);
        Matrix tmp=Pow(D,n-1);
        Matrix cnt;
        for(int i=1;i<=n_num;i++)
            cnt.m[i][1]=1;
        Matrix ans;
        for(int i=1;i<=n_num;i++)
            for(int j=1;j<=1;j++)
            {
                ans.m[i][j]=0;
                for(int k=1;k<=n_num;k++)
                    ans.m[i][j]+=tmp.m[i][k]*cnt.m[k][j];
            }
        int sy=0;
        for(int i=1;i<=n_num;i++)
            sy+=ans.m[i][1];
        long long pp=1;
        pp<<=32;
        if(sy<0)
            sy=pp+sy;
        printf("Case %d: %lld\n",cases,sy);
    }
    return 0;
}
