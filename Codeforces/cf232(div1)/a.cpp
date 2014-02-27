#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <cstring>
using namespace std;
typedef long long LL;
const LL mod=1000000007;
#define maxn 50000
vector<int>prime;
bool vis[maxn];
map<int,int>mp;
int p[5200];
LL Pow(LL a,LL b){
    LL ans=1;
    while(b){
        if(b&1) b--,ans=(ans*a)%mod;
        else b/=2,a=(a*a)%mod;
    }
    return ans;
}
LL C(LL n,LL m){
    if(n<m) return 0;
    LL ans=1;
    for(int i=1;i<=m;i++) // m<=500
        ans=((((n-m+i)*Pow(i,mod-2))%mod)*ans)%mod;
    return ans;
}
int main(){
    memset(vis,true,sizeof(vis));
    vis[0]=vis[1]=false; prime.clear(); mp.clear();
    for(int i=2;i<maxn;i++){
        if(vis[i]){
            prime.push_back(i);
            for(int j=2*i;j<maxn;j+=i) vis[j]=false;
        }
    }
    int n,x;
    while(scanf("%d",&n)!=EOF){
        memset(p,0,sizeof(p));
        for(int i=0;i<n;i++){
            scanf("%d",&x);
            for(int j=0;j<prime.size()&&prime[j]<=x;j++){
                while(x%prime[j]==0) x/=prime[j],p[j]++;
            }
            if(x>1) mp[x]++;
        }
        LL ans=1;
        for(int i=0;i<prime.size();i++){
            if(p[i]){
                ans=(ans*C(p[i]+n-1,n-1))%mod;
            }
        }
        for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++)
            ans=(ans*C(it->second+n-1,n-1))%mod;
        printf("%I64d\n",ans);
    }
    return 0;
}
