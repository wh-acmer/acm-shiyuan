#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
struct Matrix
{
    long long m[3][3];
}E,D;
int num[65];
int tum[65];
long long p,q;
void init()
{
    for(int i=1;i<=2;i++)
        for(int j=1;j<=2;j++)
            E.m[i][j]=(i==j);
}
void make()
{
    D.m[1][1]=p;
    D.m[1][2]=-q;
    D.m[2][1]=1;
    D.m[2][2]=0;
}
Matrix Multi(Matrix A,Matrix B)
{
    Matrix ans;
    for(int i=1;i<=2;i++)
        for(int j=1;j<=2;j++)
        {
            ans.m[i][j]=0;
            for(int k=1;k<=2;k++)
            {
                ans.m[i][j]=(ans.m[i][j]+A.m[i][k]*B.m[k][j]);
            }
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
    int t;
    scanf("%d",&t);
    init();
    for(int cases=1;cases<=t;cases++)
    {
        long long n;
        scanf("%lld%lld%lld",&p,&q,&n);
        make();
        Matrix tmp;
        tmp.m[1][1]=p;
        tmp.m[2][1]=2;
        printf("Case %d: ",cases);
        if(n==0)
            printf("%lld\n",2);
        else
        {
            Matrix ans=Pow(D,n-1);
            Matrix cnt;
            for(int i=1;i<=2;i++)
            {
                cnt.m[i][1]=0;
                for(int j=1;j<=2;j++)
                    cnt.m[i][1]=(cnt.m[i][1]+ans.m[i][j]*tmp.m[j][1]);
            }
            if(cnt.m[1][1]>0)
                printf("%lld\n",cnt.m[1][1]);
            else{
                    cnt.m[1][1]*=-1;
                for(int i=0;i<=64;i++)
                {
                    num[i]=0;
                    tum[i]=0;
                }
                num[64]=1;
                int tnt=0;
                while(cnt.m[1][1])
                {
                    tum[tnt++]=cnt.m[1][1]%2;
                    cnt.m[1][1]/=2;
                }

                int carry=0;
                for(int i=0;i<=64;i++)
                {
                    num[i]-=tum[i]+carry;
                    if(num[i]<0)
                    {
                        num[i]+=2;
                        carry=1;
                    }
                    else
                        carry=0;
                }
                unsigned long long sy=0;
                long long pp=1;
                for(int i=0;i<=64;i++)
                {
                    sy+=num[i]*pp;
                    pp*=2;
                }
                printf("%llu\n",sy);
            }
        }
    }
    return 0;
}
