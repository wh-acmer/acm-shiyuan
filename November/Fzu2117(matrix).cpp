// Problem 2117 ÌØÊâµÄÊý
// http://acm.fzu.edu.cn/problem.php?pid=2117
// matrix

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long LL;
const LL mod=1000000007LL;
const int N=3;
struct Matrix{
    LL m[N][N];
}E,D;
Matrix Multi(Matrix A,Matrix B){
    Matrix ans;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            ans.m[i][j]=0;
            for(int k=0;k<N;k++){
                ans.m[i][j]=ans.m[i][j]+A.m[i][k]*B.m[k][j];
                if(ans.m[i][j]>=mod) ans.m[i][j]%=mod;
            }
        }
    }
    return ans;
}
void init(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            E.m[i][j]=(i==j);
            D.m[i][j]=0;
            if(E.m[i][j]) D.m[i][j]=3;
        }
    }
    D.m[0][1]=D.m[2][1]=2;
    D.m[1][0]=D.m[1][2]=1;
}
Matrix Pow(Matrix A,LL k){
    Matrix ans=E;
    while(k){
        if(k&1) k--,ans=Multi(A,ans);
        else k>>=1,A=Multi(A,A);
    }
    return ans;
}
LL solve(LL n){
    return Pow(D,n).m[0][0];
}
int main(){
    int T;
    scanf("%d",&T);
    init();
    while(T--){
        LL n;
        scanf("%I64d",&n);
        printf("%I64d\n",solve(n));
    }
    return 0;
}

/*
only AC in Visual C++

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long LL;
const LL mod=1000000007LL;
struct Matrix{
    LL m[4][4];
}E,D;
Matrix Multi(Matrix A,Matrix B){
    Matrix ans;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            ans.m[i][j]=0;
            for(int k=0;k<4;k++){
                ans.m[i][j]=ans.m[i][j]+A.m[i][k]*B.m[k][j];
                if(ans.m[i][j]>mod) ans.m[i][j]%=mod;
            }
        }
    }
    return ans;
}
void init(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            E.m[i][j]=(i==j);
            D.m[i][j]=0;
            if(E.m[i][j]) D.m[i][j]=3;
        }
    }
    D.m[0][1]=D.m[0][2]=1;
    D.m[1][0]=D.m[1][3]=1;
    D.m[2][0]=D.m[2][3]=1;
    D.m[3][1]=D.m[3][2]=1;
}
Matrix Pow(Matrix A,LL k){
    Matrix ans=E;
    while(k){
        if(k&1) k--,ans=Multi(A,ans);
        else k>>=1,A=Multi(A,A);
    }
    return ans;
}
LL solve(LL n){
    Matrix ans=Pow(D,n);
    return ans.m[0][0]%mod;
}
int main(){
    int T;
    scanf("%d",&T);
    init();
    while(T--){
        LL n;
        scanf("%I64d",&n);
        printf("%I64d\n",solve(n));
    }
    return 0;
}


*/
