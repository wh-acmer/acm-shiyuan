/*
    NOI2013 矩阵游戏

    构造矩阵：

    D = | a b |    T = | c d |   A = | 1 |
        | 0 1 |        | 0 1 |       | 1 |

    M = D^(m-1) * ( T * D^(m-1) )^(n-1) * A

    费马小定理 指数模p-1
    注意a=1,c=1时,幂不存在,是个等差数列.没有幂不能模p-1.

*/
#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define mod 1000000007
typedef long long LL;
struct Matrix{
    LL m[3][3];
}E,D,T;
char s1[1000010],s2[1000010];
void init(){
    for(int i=1;i<=2;i++)
        for(int j=1;j<=2;j++)
            E.m[i][j]=(i==j);
}
Matrix multi(Matrix A,Matrix B){
    Matrix ans;
    for(int i=1;i<=2;i++){
        for(int j=1;j<=2;j++){
            ans.m[i][j]=0;
            for(int k=1;k<=2;k++)
                ans.m[i][j]=(ans.m[i][j]+A.m[i][k]*B.m[k][j])%mod;
        }
    }
    return ans;
}
Matrix Pow(Matrix A,LL k){
    Matrix ans=E;
    while(k){
        if(k&1) k--,ans=multi(ans,A);
        else k/=2,A=multi(A,A);
    }
    return ans;
}
inline LL input(char *s,LL Mod){
    int l=strlen(s),i=0,flag=1;
    LL ans=0;
    if(s[i]=='-') i++,flag=-1;
    while(i<l)  ans=(ans*10+s[i]-'0')%Mod,i++;
    return ((ans*flag)%Mod+Mod)%Mod;
}
void Print(Matrix A){
    for(int i=1;i<=2;i++){
        for(int j=1;j<=2;j++)
            printf("%d ",A.m[i][j]);
        printf("\n");
    }
}
int main(){
    /*freopen("matrixb.in","r",stdin);
    freopen("matrixb.out","w",stdout);*/
    LL n,m,a,b,c,d,eul;
    init();
    while(scanf("%s",&s1)!=EOF){
        scanf("%s",&s2);
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        D.m[1][1]=a,D.m[1][2]=b,D.m[2][1]=0,D.m[2][2]=1;
        if(a==1) eul=mod;
        else eul=mod-1;
        n=input(s1,eul);
        if(c==1) eul=mod;
        else eul=mod-1;
        m=input(s2,eul);
        D=Pow(D,m-1);
        T.m[1][1]=c,T.m[1][2]=d,T.m[2][1]=0,T.m[2][2]=1;
        T=Pow(multi(T,D),n-1);
        D=multi(D,T);
        printf("%lld\n",(D.m[1][1]+D.m[1][2])%mod);
    }
    return 0;
}
