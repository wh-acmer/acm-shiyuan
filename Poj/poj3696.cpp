#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
typedef long long LL;
#define maxn 50000
bool vis[maxn];
vector<int>v;
LL euler(LL x){
    LL i,res=x;
    for(int i=2;i*i<=x;i++)
        if(x%i==0){
            res=res/i*(i-1);
            while(x%i==0) x/=i;
        }
    if(x>1) res=res/x*(x-1);
    return res;
}
LL gcd(LL a,LL b){
    if(b==0) return a;
    return gcd(b,a%b);
}
LL multi(LL a,LL b,LL mod){
    LL ans=0;
    while(b){
        if(b&1) b--,ans=(ans+a)%mod;
        else b/=2,a=(a+a)%mod;
    }
    return ans;
}
LL Pow(LL a,LL b,LL mod){
    LL ans=1;
    while(b){
        if(b&1) b--,ans=multi(ans,a,mod)%mod;
        else b/=2,a=multi(a,a,mod)%mod;
    }
    return ans;
}
bool ok(LL x,LL m){
    return Pow(10,x,m)==1 ;
}
void init(){
    memset(vis,true,sizeof(vis));
    vis[0]=vis[1]=false;
    for(int i=2;i<maxn;i++){
        if(vis[i]){
            v.push_back(i);
            for(int j=2*i;j<maxn;j+=i)
                vis[j]=false;
        }
    }
}
int main(){
    int cas=0;
    LL L;
    init();
    while(scanf("%I64d",&L)!=EOF && L!=0){
        LL m=9*L/gcd(8,L);
        printf("Case %d: ",++cas);
        if(gcd(10,m)!=1){
            printf("0\n");
            continue;
        }
        LL mm=euler(m);
        for(int i=0;i<v.size() && v[i]<=mm ;i++){
            if(mm%v[i]==0){
                while(mm%v[i]==0 && ok(mm/v[i],m)) mm/=v[i];
            }
        }
        printf("%I64d\n",mm);
    }
    return 0;
}
