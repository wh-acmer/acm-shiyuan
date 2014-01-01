#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define maxn 65537
bool vis[maxn];
vector<int>prime;
const int mx=6543;
int a[mx];
int main(){
    prime.clear();
    memset(vis,true,sizeof(vis));
    vis[0]=vis[1]=false;
    for(int i=2;i<maxn;i++){
        if(vis[i]){
            prime.push_back(i);
            for(int j=2*i;j<maxn;j+=i)
                vis[j]=false;
        }
    }
    long long n;
    while(scanf("%lld",&n)!=EOF){
        if(n==0) break;
        int ok=1;
        if(n<0) ok=-1,n*=ok;
        memset(a,0,sizeof(a));
        for(int i=0;i<prime.size();i++){
            while(n%prime[i]==0){
               n/=prime[i];
               a[i]++;
            }
        }
        int ans=1;
        if(ok==-1){
            for(int i=31;i>=1;i-=2){
                bool exist=true;
                for(int j=0;j<prime.size();j++){
                    if(a[j]){
                        if(a[j]%i!=0) exist=false;
                    }
                }
                if(exist){
                    ans=i;
                    break;
                }
            }
        }
        else {
            for(int i=31;i>=1;i--){
                bool exist=true;
                for(int j=0;j<prime.size();j++){
                    if(a[j]){
                        if(a[j]%i!=0) exist=false;
                    }
                }
                if(exist){
                    ans=i;
                    break;
                }
            }
        }
        if(n!=1) ans=1;
        printf("%d\n",ans);
    }
    return 0;
}
