#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <set>
#include <queue>
using namespace std;
#define maxn 1000010
struct node{
    int st,ed,ef;
}p[1010];
bool cmp(node a,node b){
    if(a.ed==b.ed) return a.st<b.st;
    return a.ed<b.ed;
}
int dp[2*maxn];
int main(){
    int n,m,r;
    while(scanf("%d%d%d",&n,&m,&r)!=EOF){
        for(int i=0;i<m;i++) scanf("%d%d%d",&p[i].st,&p[i].ed,&p[i].ef);
        sort(p,p+m,cmp); memset(dp,0,sizeof(dp)); int now=0;
        int ans=0;
        for(int i=0;i<=n+r;){
            if(i>0) dp[i]=ans;
            if(i==p[now].ed+r){
                int st=p[now].st;
                dp[i]=max(dp[i],dp[st]+p[now].ef);
                now++;
                ans=max(ans,dp[i]);
                if(now==m) break;
            }
            else{
                i++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
