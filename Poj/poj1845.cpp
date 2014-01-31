#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
#define maxn 8000
#define mod 9901
vector<int>v;
typedef long long LL;
bool vis[maxn];
int p[1010];
LL multi(LL a,LL b,LL c){
    LL ans=0;
    while(b){
        if(b&1) b--,ans=(ans+a)%c;
        else b/=2,a=(a+a)%c;
    }
    return ans;
}
LL Pow(LL a,LL b,LL c){
    LL ans=1;
    while(b){
        if(b&1) b--,ans=multi(ans,a,c);
        else b/=2,a=multi(a,a,c);
    }
    return ans;
}
LL solve(LL p,LL n){
    return (Pow(p,n+1,(p-1)*mod)-1)/(p-1);
}
int main(){
    v.clear();
    memset(vis,true,sizeof(vis));
    vis[0]=vis[1]=false;
    for(int i=0;i<maxn;i++){
        if(vis[i]){
            v.push_back(i);
            for(int j=2*i;j<maxn;j+=i)
                vis[j]=false;
        }
    }
    LL a,b,tmp,ans;
    while(scanf("%I64d%I64d",&a,&b)!=EOF){
        ans=1;
        for(int i=0;i<v.size() && a>=v[i];i++){
            if(a%v[i]==0){
                tmp=0;
                while(a%v[i]==0){
                    a/=v[i];
                    tmp++;
                }
                tmp*=b;
                ans=multi(ans,solve(v[i],tmp),mod);
            }
        }
        if(a!=1){
            tmp=b;
            ans=multi(ans,solve(a,tmp),mod);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
