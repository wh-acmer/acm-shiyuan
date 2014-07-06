#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxn 1000010
typedef unsigned long long LL;
int prime[maxn];
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
}E,D;
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
    for(int i=0;i<2;i++){
        E.m[i][i]=1;
    }
    D.m[0][0]=3;
    D.m[1][0]=D.m[0][1]=1;
    D.m[1][1]=0;
    Prime();
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
int f0=0,f1=1;
LL get(LL n,LL mod)
{
    if(mod==1 || n==0) return 0;
    return Pow(D,n,mod).m[1][0]%mod;
}
LL fac[maxn],GG[maxn];
LL G(LL p)
{
    if(p<maxn && GG[p]!=-1) return GG[p];
    LL num;
    if(legendre(13,p)==1){
        num=p-1;
    }
    else{
        num=2*(p+1);
    }
    int cnt=0;
    for(LL i=1;i*i<=num;i++){
        if(num%i==0){
            fac[cnt++]=i;
            if(i*i!=num){
                fac[cnt++]=num/i;
            }
        }
    }
    sort(fac,fac+cnt);
    LL ans;
    for(int i=0;i<cnt;i++){
        if(get(fac[i],p)==f0&&get(fac[i]+1,p)==f1){
            ans=fac[i];
            break;
        }
    }
    if(p<maxn) GG[p]=ans;
    return ans;
}
LL find_loop(LL n)
{
    get_factors(n);
    LL ans=1;
    for(int i=0;i<fatcnt;i++)
    {
        LL record=1;
        if(factor[i][0]==2) record=2;
        else if(factor[i][0]==3) record=3;
        else if(factor[i][0]==5) record=6;
        else if(factor[i][0]==7) record=24;
        else if(factor[i][0]==11) record=12;
        else if(factor[i][0]==13) record=156;
        else  record=G(factor[i][0]);
        for(int j=1;j<factor[i][1];j++)
            record*=factor[i][0];
        ans=lcm(ans,record);
    }
    return ans;
}

int main()
{
    init();
    memset(GG,-1,sizeof(GG));
    LL N;
    LL loop1=1000000007ll;
    LL loop2=find_loop(loop1);
    LL loop3=find_loop(loop2);
    while(scanf("%I64d",&N)!=EOF){
        N=get(N,loop3);
        N=get(N,loop2);
        N=get(N,loop1);
        printf("%I64d\n",N);
    }
    return 0;
}
