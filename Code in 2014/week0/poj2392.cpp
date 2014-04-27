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
#define maxn 40010
struct node{
    int a,h;
}p[4010];
int dp[maxn];
bool cmp(node x,node y){
    return x.a<y.a;
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int now=0,a,c,h,mx=0; memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            scanf("%d%d%d",&h,&a,&c); mx=max(mx,a);
            for(int j=0;j<c;j++) p[now].a=a,p[now].h=h,now++;
        }
        sort(p,p+now,cmp);
        dp[0]=1;
        for(int i=0;i<now;i++)
            for(int j=p[i].a;j>=p[i].h;j--)
                dp[j]=max(dp[j-p[i].h],dp[j]);
        int ans=0;
        for(int i=0;i<=mx;i++)
            if(dp[i]>0) ans=i;
        printf("%d\n",ans);
    }
    return 0;
}
