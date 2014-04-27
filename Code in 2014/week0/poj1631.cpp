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
int dp[40010];
vector<int>v;
int main(){
    int T,x; scanf("%d",&T);
    while(T--){
        int n; scanf("%d",&n); v.clear(); fill(dp,dp+n,INF);
        for(int i=0;i<n;i++) scanf("%d",&x),v.push_back(x);
        for(int i=0;i<n;i++) *lower_bound(dp,dp+n,v[i])=v[i];
        printf("%d\n",lower_bound(dp,dp+n,INF)-dp);
    }
    return 0;
}
