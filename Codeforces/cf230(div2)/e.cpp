#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
#define mod 1000000007
typedef __int64 LL;
struct Matrix{
    LL m[85][85];
}E,D,T;
LL C[45][45],N,K;
void init(){
    for(int i=1;i<85;i++){
        for(int j=1;j<85;j++)
            E.m[i][j]=(i==j);
    }
    for(int i=0;i<45;i++) C[i][i]=C[i][0]=1,C[i][1]=i;
    for(int i=2;i<45;i++){
        for(int j=1;j<=i;j++)   C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
    }
}
Matrix multi(Matrix A,Matrix B,int M1,int M2,int M3){
    Matrix ans;
    for(int i=1;i<=M1;i++)
        for(int j=1;j<=M3;j++){
            ans.m[i][j]=0;
            for(int k=1;k<=M2;k++)
                ans.m[i][j]=(ans.m[i][j]+A.m[i][k]*B.m[k][j])%mod;
        }
    return ans;
}
Matrix Pow(Matrix A,LL e){
    Matrix ans=E;
    while(e){
        if(e&1) e--,ans=multi(ans,A,2*K+3,2*K+3,2*K+3);
        else e/=2,A=multi(A,A,2*K+3,2*K+3,2*K+3);
    }
    return ans;
}
void _init(){
    memset(D.m,0,sizeof(D.m)); D.m[1][1]=T.m[1][1]=1;
    for(int i=2;i<=K+2;i++) D.m[1][i]=D.m[1][i+K+1]=C[K][i-2],T.m[i][1]=T.m[i+K+1][1]=1;
    for(int i=2;i<=K+2;i++) for(int j=i;j<=K+2;j++) D.m[i][j]=D.m[i][j+K+1]=D.m[i+K+1][j]=C[K-(i-2)][j-i];
    T=multi(Pow(D,N-1),T,2*K+3,2*K+3,1);
}
int main(){
    init();
    while(scanf("%I64d%I64d",&N,&K)!=EOF){
        _init();
        printf("%I64d\n",T.m[1][1]);
    }
    return 0;
}
