#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
using namespace std;
#define INF 0x3fffffff
int n,m,p,a,b,t[11],u,v,x,d[40][40];
double dp[(1<<10)][40];
int main(){
    while(scanf("%d%d%d%d%d",&n,&m,&p,&a,&b) && (n||m||p||a||b)){
        for(int i=0;i<n;i++) scanf("%d",&t[i]); memset(d,-1,sizeof(d));
        for(int i=0;i<p;i++) scanf("%d%d%d",&u,&v,&x),--u,--v,d[u][v]=x,d[v][u]=x;
        for(int i=0;i<(1<<n);i++) fill(dp[i],dp[i]+m,INF);
        dp[(1<<n)-1][a-1]=0; double ans=INF;
        for(int state=(1<<n)-1;state>=0;state--){
            ans=min(ans,dp[state][b-1]);
            for(int i=0;i<n;i++){
                if(state&(1<<i)){
                    for(u=0;u<m;u++){
                        for(v=0;v<m;v++){
                            if(d[u][v]>=0){
                                dp[state&(~(1<<i))][v]=min(dp[state&(~(1<<i))][v],dp[state][u]+1.0*d[u][v]/t[i]);
                            }
                        }
                    }
                }
            }
        }
        if(ans==INF) printf("Impossible\n");
        else printf("%.3lf\n",ans);
    }
    return 0;
}
