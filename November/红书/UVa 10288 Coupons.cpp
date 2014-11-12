#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
typedef long long LL;
#define N 35
vector<int>prime;
bool vis[N];
int a[11],b[11];
void init(){
    memset(vis,1,sizeof vis);
    prime.clear();
    vis[0]=vis[1]=0;
    for(int i=2;i<N;i++){
        if(vis[i]){
            prime.push_back(i);
            for(int j=2*i;j<N;j+=i){
                vis[j]=false;
            }
        }
    }
    //printf("%d\n",prime.size());
    for(int i=0;i<prime.size();i++){
        a[i]=prime[i];
    }
}
LL gcd(LL a,LL b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int digit(LL n){
    if(n==0) return 1;
    int ans=0;
    while(n){
        ans++;
        n/=10;
    }
    return ans;
}
int main(){
    init();
    int n;
    while(scanf("%d",&n)!=EOF){
        memset(b,0,sizeof b);
        for(int i=1;i<=n;i++){
            int now=i;
            for(int j=0;j<prime.size();j++){
                int cnt=0;
                while(now%a[j]==0){
                    cnt++;
                    now/=a[j];
                }
                b[j]=max(b[j],cnt);
            }
        }
        LL all=1;
        for(int i=0;i<prime.size();i++){
            for(int j=1;j<=b[i];j++){
                all*=a[i];
            }
        }
        LL ans=0;
        for(int i=1;i<=n;i++){
            ans+=all/i;
        }
        ans*=n;
        LL g=gcd(ans,all);
        ans/=g;
        all/=g;
        LL ex=ans/all;
        ans%=all;
        if(ans==0 || all==1){
            printf("%lld\n",ex);
        }
        else if(ex==0){
            printf("%lld\n",ans);
            printf("%lld\n",all);
        }
        else{
            int d=digit(ex);
            for(int i=0;i<=d;i++) printf(" ");
            printf("%lld\n",ans);
            printf("%lld ",ex);
            int dd=digit(all);
            for(int i=0;i<dd;i++) printf("-");
            printf("\n");
            for(int i=0;i<=d;i++) printf(" ");
            printf("%lld\n",all);
        }
    }
    return 0;
}
