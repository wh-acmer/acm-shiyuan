/*
    求由不超过n的数的乘积组成的最大平方数
    对n!进行分解，p的偶数幂的全部除掉该质因子
*/

#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define maxn 10000010
#define Mod  1000000007
typedef __int64 LL;
bool vis[maxn];
LL fac[maxn];
vector<int>v;
LL Pow(LL a,LL b){
    LL ans=1;
    while(b){
        if(b&1) ans=(ans*a)%Mod,b--;
        else a=(a*a)%Mod,b/=2;
    }
    return ans;
}
int get(int n,int p){
    int ans=0;
    while(n){
        ans+=n/p;
        n/=p;
    }
    return ans;
}
int main(){
    fac[0]=1;
    for(int i=1;i<maxn;i++) fac[i]=(fac[i-1]*i)%Mod;
    v.clear();
    memset(vis,true,sizeof(vis));
    vis[0]=vis[1]=false;
    for(int i=2;i<maxn;i++){
        if(vis[i]){
            v.push_back(i);
            for(int j=2*i;j<maxn;j+=i) vis[j]=false;
        }
    }
    int n;
    while(scanf("%d",&n)!=EOF){
        if(n==0) break;
        int pos=0;
        LL ans=1;
        while(v[pos]<=n && pos<v.size()){
            int tmp=get(n,v[pos]);
            if(tmp&1)   ans=(ans*v[pos])%Mod;
            pos++;
        }
        printf("%I64d\n",(fac[n]*Pow(ans,Mod-2))%Mod);
    }
    return 0;
}

