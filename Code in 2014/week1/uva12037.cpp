#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
using namespace std;
#define mod 34830
typedef long long LL;
struct Matrix{
    LL m[8][8];
}E,D;
int n;
LL k;
void init(){
    memset(D.m,0,sizeof(D.m)),memset(E.m,0,sizeof(E.m));
    for(int i=1;i<=7;i++) E.m[i][i]=1;
    D.m[1][1]=(k-4)%mod; D.m[4][7]=D.m[5][6]=(k-2)%mod;
    D.m[1][4]=D.m[1][5]=D.m[4][2]=D.m[5][3]=(k-3)%mod;
    D.m[2][1]=D.m[2][5]=D.m[3][1]=D.m[3][4]=D.m[6][2]=D.m[7][3]=1;;
}
Matrix Multi(Matrix A,Matrix B){
    Matrix ans;
    for(int i=1;i<=7;i++){
        for(int j=1;j<=7;j++){
            ans.m[i][j]=0;
            for(int k=1;k<=7;k++) ans.m[i][j]=(ans.m[i][j]+A.m[i][k]*B.m[k][j])%mod;
        }
    }
    return ans;
}
Matrix Pow(Matrix A,LL e){
    Matrix ans=E;
    while(e){
        if(e&1) e--,ans=Multi(ans,A);
        else e/=2,A=Multi(A,A);
    }
    return ans;
}
LL solve(){
    if(n==1) return k%mod;
    if(n==2) return (k*(k-1))%mod;
    if(n==3) return (k*(k-1)%mod)*(k-2)%mod;
    if(k<3) return 0;
    if(n==4) return (k*(k-1)%mod)*((k-2)*(k-3)%mod)%mod;
    init();  D=Pow(D,n-4);
    LL a1=(k*(k-1)%mod)*((k-2)*(k-3)%mod)%mod;
    LL a2=(k*(k-1)%mod)*(k-2)%mod;
    Matrix ans; memset(ans.m,0,sizeof(ans.m));
    ans.m[1][1]=a1;  ans.m[3][1]=a2;  ans=Multi(D,ans);
    return (ans.m[1][1]+ans.m[4][1])%mod;
}
int main(){
    int T; scanf("%d",&T); int cas=0;
    while(T--){
        scanf("%d%lld",&n,&k);
        printf("Case %d: %lld\n",++cas,solve());
    }
    return 0;
}
