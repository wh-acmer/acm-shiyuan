#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define maxn 10010
vector<int>v[maxn];
double e[maxn],k[maxn];
double A[maxn],B[maxn],C[maxn];
#define eps 1e-9
bool dfs(int now,int pre){
    int s=v[now].size();
    A[now]=k[now];
    B[now]=(1-k[now]-e[now])/s;
    C[now]=1-k[now]-e[now];
    double ee=(1-k[now]-e[now])/s;
    double ff=1;
    for(int i=0;i<v[now].size();i++){
        if(v[now][i]==pre)
            continue;
        if(!dfs(v[now][i],now))
            return false;
        A[now]+=ee*A[v[now][i]];
        C[now]+=ee*C[v[now][i]];
        ff-=ee*B[v[now][i]];
    }
    if(fabs(ff)<eps) return false;
    A[now]/=ff,B[now]/=ff,C[now]/=ff;
    return true;
}
int main(){
    int T,cas=0;
    scanf("%d",&T);
    while(T--){
        int n,u,w;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            v[i].clear();
        }
        for(int i=1;i<n;i++){
            scanf("%d%d",&u,&w);
            v[u].push_back(w);
            v[w].push_back(u);
        }
        for(int i=1;i<=n;i++){
            scanf("%lf%lf",&k[i],&e[i]);
            k[i]/=100;
            e[i]/=100;
        }
        printf("Case %d: ",++cas);
        dfs(1,-1);
        if(fabs(1-A[1])>eps){
            printf("%.6lf\n",C[1]/(1-A[1]));
        }
        else{
            printf("impossible\n");
        }
    }
    return 0;
}
