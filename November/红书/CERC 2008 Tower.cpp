#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
typedef long long LL;
struct Matrix{
    LL m[5][5];
}E,D,F;
LL mod;
void init(){
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            E.m[i][j]=(i==j);
        }
    }
}
Matrix Multi(Matrix A,Matrix B){
    Matrix ans;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            ans.m[i][j]=0;
            for(int k=1;k<=4;k++){
                ans.m[i][j]=(ans.m[i][j]+A.m[i][k]*B.m[k][j])%mod;
            }
        }
    }
    return ans;
}
Matrix Pow(Matrix A,LL e){
    Matrix ans=E;
    while(e){
        if(e&1) e--,ans=Multi(ans,A);
        else e>>=1,A=Multi(A,A);
    }
    return ans;
}
void pre(LL p){
    memset(D.m,0,sizeof D.m);
    D.m[1][1]=D.m[1][3]=D.m[2][3]=1;
    D.m[1][2]=D.m[2][2]=(4*p*p)%mod;
    D.m[1][4]=D.m[2][4]=((-4*p)%mod+mod)%mod;
    D.m[3][2]=1%mod;
    D.m[4][2]=(2*p)%mod;
    D.m[4][4]=mod-1;

    memset(F.m,0,sizeof F.m);
    F.m[1][1]=(1+p*p)%mod;
    F.m[2][1]=(p*p)%mod;
    F.m[3][1]=1%mod;
    F.m[4][1]=(p%mod+mod)%mod;
}
int main(){
    int T;
    scanf("%d",&T);
    init();
    while(T--){
        LL p,n;
        scanf("%lld%lld%lld",&p,&n,&mod);
        pre(p);
        D=Pow(D,n-2);
        F=Multi(D,F);
        printf("%lld\n",F.m[1][1]);
    }
    return 0;
}
