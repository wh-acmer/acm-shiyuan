#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
#define maxn 1000010
typedef long long LL;
vector<LL>prime;
bool vis[maxn];
typedef pair<LL,LL>P;
int num[]={3,4,5,6};
LL tmp;
LL ans;
void Prime(){
    memset(vis,true,sizeof(vis));
    vis[0]=vis[1]=false;
    prime.clear();
    for(int i=2;i<maxn;i++){
        if(vis[i]){
            prime.push_back(i);
            for(int j=2*i;j<maxn;j+=i){
                vis[j]=false;
            }
        }
    }
}
vector<P>vt;
vector<LL>tp;
void dfs(LL now,int index){
    if(index==vt.size()){
        tp.push_back(now);
        return;
    }
    LL cnt=1;
    dfs(now*cnt,index+1);
    for(int i=0;i<vt[index].second;i++){
        cnt*=vt[index].first;
        dfs(now*cnt,index+1);
    }
}
void get_factor(LL n){
    vt.clear();
    for(int i=0;i<prime.size() && 1LL*prime[i]*prime[i]<=n;i++){
        if(n%prime[i]==0){
            int cnt=0;
            while(n%prime[i]==0){
                n/=prime[i];
                cnt++;
            }
            vt.push_back(P(prime[i],cnt));
        }
    }
    if(n!=1) vt.push_back(P(n,1));
    tp.clear();
    dfs(1,0);
}
LL pika(LL now,LL x){
    if(now>=3 && now<=6 && now<x) return 1;
    int tag=0;
    for(int i=0;i<4;i++){
        if(x>num[i] && now>num[i] && (now-num[i])%x==0){
            tag=pika((now-num[i])/x,x);
            if(tag) return 1;
        }
    }
    return 0;
}
void solve(LL now,LL last){
    now-=last;
    get_factor(now);
    for(int i=0;i<tp.size();i++){
        if(tp[i]==now) continue;
        if(last>=tp[i]) continue;
        ans+=pika(now/tp[i],tp[i]);
    }
}
int main(){
    Prime();
    int T,cas=0;
    scanf("%d",&T);
    while(T--){
        LL n;
        scanf("%I64d",&n);
        printf("Case #%d: ",++cas);
        if(n>=3 && n<=6) printf("-1\n");
        else{
            ans=0;
            for(int i=0;i<4;i++){
                solve(n,num[i]);
            }
            printf("%I64d\n",ans);
        }
    }
    return 0;
}
