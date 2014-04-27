/*
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
#define maxn 3010
#define mod 1000000
int f[maxn],g[maxn];
map<int,int>mp;
map<int,int>::iterator it;
int main(){
    int t,a,s,b,x;
    while(scanf("%d%d%d%d",&t,&a,&s,&b)!=EOF){
        mp.clear(); memset(f,0,sizeof(f)); memset(g,0,sizeof(g));
        for(int i=0;i<a;i++) scanf("%d",&x),mp[x]++;  f[0]=1;
        for(it=mp.begin();it!=mp.end();it++){
            x=it->second;
            for(int i=0;i<=b;i++){
                for(int j=0;j<=x && i+j<=b;j++)
                    g[i+j]+=f[i],g[i+j]%=mod;
            }
            memcpy(f,g,sizeof(g)),memset(g,0,sizeof(g));
        }
        int ans=0;
        for(int i=s;i<=b;i++) ans+=f[i],ans%=mod;
        printf("%d\n",ans);
    }
    return 0;
}
*/
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
#define maxn 100010
#define mod 1000000
int dp[1010][maxn];
int a[1010];
int main(){
    int T,A,S,B,x;
    while(scanf("%d%d%d%d",&T,&A,&S,&B)!=EOF){
        memset(a,0,sizeof(a)); int n=T+1;
        for(int i=0;i<A;i++) scanf("%d",&x),a[x]++;
        for(int i=0;i<=n;i++) dp[i][0]=1;
        for(int i=0;i<n;i++){
            for(int j=1;j<=B;j++){
                if(j-1-a[i]>=0) dp[i+1][j]=(dp[i+1][j-1]+dp[i][j]-dp[i][j-1-a[i]]+mod)%mod;
                else dp[i+1][j]=(dp[i+1][j-1]+dp[i][j])%mod;
            }
        }
        int ans=0;
        for(int i=S;i<=B;i++) ans+=dp[n][i],ans%=mod;
        printf("%d\n",ans);
    }
    return 0;
}
