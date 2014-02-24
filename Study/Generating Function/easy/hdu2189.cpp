#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
typedef __int64 LL;
#define N 160
bool vis[N];
vector<int>v;
LL f[N],g[N];
int main(){
    memset(vis,true,sizeof(vis));
    vis[0]=vis[1]=false;
    for(int i=2;i<N;i++){
        if(vis[i]) v.push_back(i);
        for(int j=2*i;j<N;j+=i) vis[j]=false;
    }
    int T,x;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&x);
        memset(f,0,sizeof(f)),memset(g,0,sizeof(g)),f[0]=1;
        for(int i=0;i<v.size();i++){
            for(int j=0;j<=x;j++){
                for(int k=0;k+j<=x;k+=v[i]) g[k+j]+=f[j];
            }
            memcpy(f,g,sizeof(f));
            memset(g,0,sizeof(g));
        }
        printf("%lld\n",f[x]);
    }
    return 0;
}
