/*
   分别求 n! 对 431 内的 87 个质数的幂
*/
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
#define maxn 450
typedef long long LL;
bool vis[maxn];
int a[maxn][100];
vector<int>v;
void init(){
    v.clear();
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
int get(int n,int p){
    int ans=0;
    while(n){
        n/=p;
        ans+=n;
    }
    return ans;
}
int main(){
    init();
    memset(a,0,sizeof(a));
    for(int i=0;i<maxn;i++){
        for(int j=0;j<v.size();j++)
            a[i][j]=get(i,v[j]);
    }
    int n,k,tmp;
    while(scanf("%d%d",&n,&k)!=EOF){
        LL ans=1;
        for(int i=0;i<v.size();i++){
            tmp=a[n][i]-a[k][i]-a[n-k][i];
            if(tmp) ans*=tmp+1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
