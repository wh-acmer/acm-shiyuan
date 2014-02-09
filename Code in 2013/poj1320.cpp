/*
    matrix + 佩尔方程
*/
#include <cstdio>
struct Matrix
{
    int m[3][3];
};
Matrix E,B,D;
void Init()
{
    for(int i=1;i<=2;i++)
    for(int j=1;j<=2;j++)
        E.m[i][j]=(i==j);
    D.m[1][1]=3;
    D.m[2][1]=1;
    B.m[1][1]=B.m[2][2]=3;
    B.m[1][2]=8;
    B.m[2][1]=1;
}
Matrix Multi(Matrix A,Matrix B,int M,int N,int K)
{
    Matrix ans;
    for(int i=1;i<=M;i++)
    for(int j=1;j<=N;j++)
    {
        ans.m[i][j]=0;
        for(int k=1;k<=K;k++)
        {
            ans.m[i][j]+=A.m[i][k]*B.m[k][j];
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
            ans=Multi(ans,A,2,2,2);
        }
        else
        {
            k/=2;
            A=Multi(A,A,2,2,2);
        }
    }
    return ans;
}
int main()
{
    Init();
    for(int i=1;i<=10;i++)
    {
        Matrix ans=Pow(B,i);
        ans=Multi(ans,D,2,1,2);
        printf("%10d%10d\n",ans.m[2][1],(ans.m[1][1]-1)/2);
    }
    return 0;
}
