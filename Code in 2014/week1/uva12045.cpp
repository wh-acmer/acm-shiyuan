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
typedef long long LL;
#define mod 1000000007
struct Matrix{
    LL m[3][3];
}D,E;
void init(){
    for(int i=1;i<=2;i++)
        for(int j=1;j<=2;j++)
            E.m[i][j]=(i==j);
    D.m[1][1]=D.m[2][1]=D.m[1][2]=1;
    D.m[2][2]=0;
}
Matrix Multi(Matrix A,Matrix B){
    Matrix ans;
    for(int i=1;i<=2;i++)
        for(int j=1;j<=2;j++){
            ans.m[i][j]=0;
            for(int k=1;k<=2;k++)
                ans.m[i][j]=(ans.m[i][j]+A.m[i][k]*B.m[k][j])%mod;
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
LL get_fib(int n){
    return Pow(D,n+1).m[2][1];
}
LL gcd(LL x,LL y){
    if(y==0) return x;
    return gcd(y,x%y);
}
LL lcm(LL x,LL y){
    return x/gcd(x,y)*y;
}
LL Pow(LL a,LL b){
    LL ans=1;
    while(b){
        if(b&1) b--,ans=(ans*a)%mod;
        else b/=2,a=(a*a)%mod;
    }
    return ans;
}
LL get(LL n){
    return Pow(D,n).m[2][1];
}
int main(){
    init(); int T; scanf("%d",&T);
    while(T--){
        LL a,b,c,n,m;
        scanf("%lld%lld%lld%lld%lld",&a,&n,&b,&m,&c);
        if(a>=44 || b>=44){
            printf("Impossible\n");
            continue;
        }
        LL fa=get(a),fa1=get(a+1),fb=get(b),fb1=get(b+1);
        bool ok=true; LL x,y;
        if((n*fb1-m*fa1)%(fa*fb1-fa1*fb)==0) x=(n*fb1-m*fa1)/(fa*fb1-fa1*fb);
        else ok=false;
        if((n*fb-m*fa)%(fa1*fb-fa*fb1)==0) y=(n*fb-m*fa)/(fa1*fb-fa*fb1);
        else ok=false;
        if(x<0 || y<0) ok=false;
        if(ok) printf("%lld\n",(get(c)*x+get(c+1)*y)%mod);
        else printf("Impossible\n");
    }
    return 0;
}
