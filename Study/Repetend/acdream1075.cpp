#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define maxn 1000010
typedef long long LL;
int prime[maxn];
vector<LL>miaomiao,pika;
int _a,_b,_c,_d;
void Prime(){
    memset(prime,0,sizeof(prime));
    for(int i=2;i<maxn;i++){
        if(!prime[i]) prime[++prime[0]]=i;
        for(int j=1;j<=prime[0]&&prime[j]<maxn/i;j++){
            prime[prime[j]*i]=1;
            if(i%prime[j]==0){
                break;
            }
        }
    }
}
LL factor[100][2];
int fatcnt;
int get_factors(LL n){
    fatcnt=0;
    LL tmp=n;
    for(int i=1;prime[i]<=tmp/prime[i];i++){
        factor[fatcnt][1]=0;
        if(tmp%prime[i]==0){
            factor[fatcnt][0]=prime[i];
            while(tmp%prime[i]==0){
                tmp/=prime[i];
                factor[fatcnt][1]++;
            }
            fatcnt++;
        }
    }
    if(tmp!=1){
        factor[fatcnt][0]=tmp;
        factor[fatcnt][1]=1;
        fatcnt++;
    }
    return fatcnt;
}
LL gcd(LL a,LL b){
    if(b==0){
        return a;
    }
    else{
        return gcd(b,a%b);
    }
}
LL lcm(LL a,LL b){
    return a/gcd(a,b)*b;
}
struct Matrix{
    LL m[2][2];
}E,D,M;
Matrix Multi(Matrix A,Matrix B,LL mod){
    Matrix ans;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            ans.m[i][j]=0;
            for(int k=0;k<2;k++){
                ans.m[i][j]+=(A.m[i][k]*B.m[k][j])%mod;
                if(ans.m[i][j]>=mod){
                    ans.m[i][j]-=mod;
                }
            }
        }
    }
    return ans;
}
void init(){
    memset(E.m,0,sizeof(E.m));
    memset(D.m,0,sizeof(D.m));
    for(int i=0;i<2;i++){
        E.m[i][i]=1;
    }
    D.m[0][0]=_a;
    D.m[1][0]=1;
    D.m[0][1]=_b;
}
Matrix Pow(Matrix A,LL e,LL mod){
    Matrix ans=E;
    while(e){
        if(e&1){
            ans=Multi(ans,A,mod);
        }
        A=Multi(A,A,mod);
        e>>=1;
    }
    return ans;
}
LL Pow(LL a,LL b,LL mod){
    LL ans=1;
    while(b){
        if(b&1){
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;
}
int legendre(LL a,LL p){
    if(Pow(a,(p-1)>>1,p)==1){
        return 1;
    }
    else{
        return -1;
    }
}
int f0=1,f1=1;
LL get_fib(LL n,LL mod)
{
    if(mod==1) return 0;
    return Multi(Pow(D,n-1,mod),M,mod).m[1][0]%mod;
}
LL fac[maxn];
LL G(LL p)
{
    LL num;
    int delta=_a*_a+4*_b;
    int cnt;
    if(legendre(delta,p)==1){
        //num=p-1;
        for(int i=0;i<miaomiao.size();i++){
            if(get_fib(miaomiao[i]+1,p)==f0&&get_fib(miaomiao[i]+2,p)==f1){
                return miaomiao[i];
            }
        }
    }
    else{
        //num=(p-1)*(p+1);
        for(int i=0;i<pika.size();i++){
            if(get_fib(pika[i]+1,p)==f0&&get_fib(pika[i]+2,p)==f1){
                return pika[i];
            }
        }
    }
}
LL find_loop(LL n)
{
    get_factors(n);
    LL ans=1;
    for(int i=0;i<fatcnt;i++)
    {
        LL record=1;
        record=G(factor[i][0]);
        for(int j=1;j<factor[i][1];j++)
            record*=factor[i][0];
        ans=lcm(ans,record);
    }
    return ans;
}
void presolve(){
    pika.clear();
    miaomiao.clear();
    miaomiao.push_back(1);
    miaomiao.push_back(2);
    miaomiao.push_back(500000003);
    miaomiao.push_back(500000003*2);
    sort(miaomiao.begin(),miaomiao.end());
    vector<int>tp;
    tp.clear();
    for(int i=0;i<4;i++) tp.push_back(2);
    for(int i=0;i<2;i++) tp.push_back(3);
    for(int i=0;i<1;i++) tp.push_back(7);
    for(int i=0;i<2;i++) tp.push_back(109);
    for(int i=0;i<1;i++) tp.push_back(167);
    tp.push_back(500000003);
    for(int i=0;i<(1<<tp.size());i++){
        LL now=1;
        for(int j=0;j<tp.size();j++){
            if((1<<j)&i){
                now*=tp[j];
            }
        }
        pika.push_back(now);
    }
    sort(pika.begin(),pika.end());
    pika.erase(unique(pika.begin(),pika.end()),pika.end());
}
int main()
{
    presolve();
    Prime();
    while(scanf("%d%d%d%d",&_a,&_b,&_c,&_d)!=EOF){
        init();
        f0=_c,f1=_d;
        M.m[0][0]=_d;
        M.m[1][0]=_c;
        LL N=1000000007;
        N=find_loop(N);
        printf("%lld\n",N);
    }
    return 0;
}
