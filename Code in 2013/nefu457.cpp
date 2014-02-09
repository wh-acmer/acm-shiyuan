/*
    matrix
*/
#include <cstring>
#include <cmath>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long mod=10000000;
long long a,b,p,q,l,r;
struct Matrix
{
    long long m[3][3];
}E,D,T;
void init()
{
    for(int i=1;i<=2;i++)
        for(int j=1;j<=2;j++)
            E.m[i][j]=(i==j);
}
void make()
{
    D.m[1][1]=p;
    D.m[1][2]=q;
    D.m[2][1]=1;
    D.m[2][2]=0;

    T.m[1][1]=b;
    T.m[2][1]=a;
}
Matrix Multi(Matrix A,Matrix B)
{
    Matrix ans;
    for(int i=1;i<=2;i++)
        for(int j=1;j<=2;j++)
        {
            ans.m[i][j]=0;
            for(int k=1;k<=2;k++)
                ans.m[i][j]=(ans.m[i][j]+A.m[i][k]*B.m[k][j])%mod;
        }
    return ans;
}
Matrix Pow(Matrix A,long long k)
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
Matrix Add(Matrix A,Matrix B)
{
    Matrix ans;
    for(int i=1;i<=2;i++)
        for(int j=1;j<=2;j++)
        {
            ans.m[i][j]=(A.m[i][j]+B.m[i][j])%mod;
        }
    return ans;
}
Matrix Sum(Matrix A,long long k)
{
    if(k==0)
    {
        Matrix none;
        for(int i=1;i<=2;i++)
            for(int j=1;j<=2;j++)
                none.m[i][j]=0;
        return none;
    }
    if(k==1)
        return A;
    if(k==2)
        return Add(A,Pow(A,2));
    Matrix ans=Sum(A,k/2);
    Matrix cnt=Add(Pow(A,k/2),E);
    if(k&1)
        return Add(Multi(ans,cnt),Pow(A,k));
    return Multi(ans,cnt);
}
long long getans(long long n)
{
    if(n==-1)
        return 0;
    if(n==0)
        return a;
    Matrix ans=Add(Sum(D,n-1),E);
    ans=Multi(ans,T);
    return (ans.m[1][1]+a)%mod;
}
int main()
{
    int t;
    cin>>t;
    init();
    while(t--)
    {
        cin>>a>>b>>p>>q>>l>>r;
        make();
        cout<<((getans(r)-getans(l-1))%mod+mod)%mod<<endl;
    }
    return 0;
}
