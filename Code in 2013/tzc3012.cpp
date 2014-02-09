/*
    matrix
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
struct Matrix
{
    long long m[5][5];
}E,D,T;
long long mod;
void init()
{
    for(int i=1;i<=4;i++)
        for(int j=1;j<=4;j++)
        {
            E.m[i][j]=(i==j);
            D.m[i][j]=0;
            T.m[i][j]=0;
        }
    for(int i=1;i<=4;i++)
        T.m[i][1]=1,D.m[1][i]=1;
    D.m[1][3]=D.m[2][3]=2;
    D.m[2][2]=D.m[2][4]=1;
    D.m[3][2]=D.m[3][3]=D.m[4][2]=1;
}
Matrix Multi(Matrix A,Matrix B)
{
    Matrix ans;
    for(int i=1;i<=4;i++)
        for(int j=1;j<=4;j++)
        {
            ans.m[i][j]=0;
            for(int k=1;k<=4;k++)
                ans.m[i][j]=(ans.m[i][j]+A.m[i][k]*B.m[k][j])%mod;
        }
    return ans;
}
Matrix Pow(Matrix A,long long b)
{
    Matrix ans=E;
    while(b)
    {
        if(b&1)
        {
            b--;
            ans=Multi(ans,A);
        }
        else
        {
            b/=2;
            A=Multi(A,A);
        }
    }
    return ans;
}
long long Pow(long long a,long long b,long long m)
{
    long long ans=1;
    while(b)
    {
        if(b&1)
        {
            b--;
            ans=(ans*a)%m;
        }
        else
        {
            b/=2;
            a=(a*a)%m;
        }
    }
    return ans;
}
long long euler(long long x)
{
    long long i,res=x;
    for(i=2;i*i<=x;i++)
    {
        if(x%i==0)
        {
            res=res/i*(i-1);
            while(x%i==0)
                x/=i;
        }
    }
    if(x>1)
        res=res/x*(x-1);
    return res;
}
int main()
{
    long long a,n,p;
    init();
    while(cin>>a>>n>>p)
    {
        if(a+n+p==0)
            break;
        mod=euler(p);
        Matrix ans=Pow(D,n-1);
        ans=Multi(ans,T);
        long long tmp=ans.m[1][1];
        tmp=tmp+mod;
        tmp=Pow(a,tmp,p);
        cout<<tmp<<endl;
    }
    return 0;
}
