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
typedef pair<int,int> P;
#define INF 0x3fffffff
vector<P>v;
vector<int>vt;
int dp[5010];
int main(){
    int T,x,y; scanf("%d",&T);
    while(T--){
        int n; scanf("%d",&n); v.clear();
        for(int i=0;i<n;i++) scanf("%d%d",&x,&y),v.push_back(P(x,y));
        sort(v.begin(),v.end()); vt.clear(); fill(dp,dp+n,INF);
        for(int i=0;i<n;i++) vt.push_back(v[n-1-i].second);
        for(int i=0;i<n;i++) *lower_bound(dp,dp+n,vt[i])=vt[i];
        printf("%d\n",lower_bound(dp,dp+n,INF)-dp);
    }
    return 0;
}
