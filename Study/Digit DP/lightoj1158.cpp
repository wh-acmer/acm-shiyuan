#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;
typedef long long LL;
#define N 10
int bit[N];
LL dp[1<<N][1005];
char s[N];
int d,len;
LL dfs(int pos,int status,int remain){
    if(pos==len){
        return remain==0;
    }
    if(dp[status][remain]!=-1){
        return dp[status][remain];
    }
    bool vis[N];
    memset(vis,true,sizeof vis);
    LL ans=0;
    for(int i=0;i<len;i++){
        if(((1<<i)&status)==0 && vis[s[i]-'0']){
            vis[s[i]-'0']=false;
            ans+=dfs(pos+1,status|(1<<i),(remain*10+s[i]-'0')%d);
        }
    }
    return dp[status][remain]=ans;
}
int main(){
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++){
        scanf("%s%d",&s,&d);
        len=strlen(s);
        memset(dp,-1,sizeof dp);
        LL ans=dfs(0,0,0);
        printf("Case %d: %lld\n",cas,ans);
    }
    return 0;
}
