#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <bitset>
using namespace std;
typedef long long LL;
#define N 2048
#define maxn 100010
#define mod 998244353
LL inverse[maxn],fac[maxn];
LL Pow(LL a,LL b){
    LL ans=1;
    while(b){
        if(b&1) b--,ans*=a,ans%=mod;
        else b>>=1,a*=a,a%=mod;
    }
    return ans;
}
void init(){
    fac[0]=1,inverse[0]=1;
    for(int i=1;i<maxn;i++){
        fac[i]=(fac[i-1]*i)%mod;
        inverse[i]=Pow(fac[i],mod-2);
    }
}
LL C(LL n,LL m){
    return fac[n]*(inverse[n-m]*inverse[m]%mod)%mod;
}
map<int,int>mp;
void _init(){
    mp.clear();
    int x=1,now=1;
    while(x<=2048){
        mp[x]=now++;
        x*=2;
    }
}
LL dp[13][2049];
LL num[13];
int main(){
    init();
    _init();
    int n,x,cas=0;
    while(scanf("%d",&n)!=EOF){
        if(n==0) break;
        memset(num,0,sizeof num);
        memset(dp,0,sizeof dp);
        for(int i=0;i<n;i++){
            scanf("%d",&x);
            num[mp[x]]++;
        }
        LL all=0;
        for(int i=1;i<=12;i++){
            all+=num[i];
        }
        all=Pow(2,all);
        for(int i=0;i<=num[1] && i<2048;i++){
            dp[1][i]=C(num[1],i);
        }
        for(int i=2;i<13;i++){
            for(int k=0;k<=num[i] && k*(1<<(i-1))<=2048;k++){
                LL cc=C(num[i],k);
                for(int j=k;j*(1<<(i-1))<2048;j++){
                    dp[i][j]+=(dp[i-1][(j-k)<<1]+dp[i-1][((j-k)<<1)+1])*cc;
                    dp[i][j]%=mod;
                }
            }
        }
        all-=dp[12][0];
        if(all<0) all+=mod;
        all*=Pow(2,num[0]);
        all%=mod;
        printf("Case #%d: %I64d\n",++cas,all);
    }
    return 0;
}
