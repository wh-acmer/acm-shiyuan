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
typedef pair<int,int>P;
vector<P>v;
int dp[1<<16];
int dis(P a,P b){
    if(a.first==b.first) return abs(a.second-b.second);
    if(a.second==b.second) return abs(a.first-b.first);
    return abs(a.first-b.first)*abs(a.second-b.second);
}
int main(){
    int n,x,y;
    while(scanf("%d",&n),n){
        v.clear(); memset(dp,0x3f,sizeof(dp));
        for(int i=0;i<n;i++) scanf("%d%d",&x,&y),v.push_back(P(x,y));
        int inf=dp[0]; dp[0]=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int st=(1<<i)|(1<<j);
                int Minx=min(v[i].first,v[j].first),Maxx=max(v[i].first,v[j].first);
                int Miny=min(v[i].second,v[j].second),Maxy=max(v[i].second,v[j].second);
                for(int k=0;k<n;k++)
                    if(v[k].first>=Minx && v[k].first<=Maxx && v[k].second>=Miny && v[k].second<=Maxy)
                        st|=(1<<k);
                for(int state=0;state<(1<<n);state++){
                    if((state|st)==state || dp[state]==inf) continue;
                    dp[state|st]=min(dp[state|st],dp[state]+dis(v[i],v[j]));
                }
            }
        }
        printf("%d\n",dp[(1<<n)-1]);
    }
    return 0;
}
