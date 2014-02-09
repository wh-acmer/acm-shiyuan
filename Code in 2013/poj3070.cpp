/*
    water
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define mod 10000
struct Matrix
{
    int m[2][2];
};
Matrix E;
void Init()
{
    E.m[0][0]=E.m[1][1]=1;
    E.m[0][1]=E.m[1][0]=0;
}
Matrix Multi(Matrix A,Matrix B)
{
    Matrix ans;
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
        {
            ans.m[i][j]=0;
            for(int k=0;k<2;k++)
            {
                ans.m[i][j]+=A.m[i][k]*B.m[k][j];
                ans.m[i][j]%=mod;
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
    int n;
    Matrix B;
    B.m[0][0]=1;
    B.m[0][1]=1;
    B.m[1][0]=1;
    B.m[1][1]=0;
    Init();
    while(scanf("%d",&n),n>=0)
    {
        Matrix A=Pow(B,n);
        printf("%d\n",A.m[1][0]);
    }
    return 0;
}
