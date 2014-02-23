#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long LL;
#define mod 1000000007
struct Matrix{
    LL m[3][3];
}E,D;
Matrix Multi(Matrix A,Matrix B){
    Matrix ans;
    for(int i=1;i<=2;i++)
    for(int j=1;j<=2;j++){
        ans.m[i][j]=0;
        for(int k=1;k<=2;k++) ans.m[i][j]=(ans.m[i][j]+A.m[i][k]*B.m[k][j])%mod;
    }
    return ans;
}
Matrix Pow(Matrix A,LL k){
    Matrix ans=E;
    while(k){
        if(k&1) k--,ans=Multi(ans,A);
        else k/=2,A=Multi(A,A);
    }
    return ans;
}
int main(){
    for(int i=1;i<=2;i++)
        for(int j=1;j<=2;j++)
            E.m[i][j]=(i==j);
    int T;
    scanf("%d",&T);
    while(T--){
        LL n;
        scanf("%lld",&n);
        D.m[1][1]=D.m[1][2]=D.m[2][1]=1;D.m[2][2]=0;
        D=Pow(D,n);
        printf("%lld\n",D.m[1][1]);
    }
    return 0;
}
