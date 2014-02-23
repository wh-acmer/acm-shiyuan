#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
#define N 1010
typedef pair<int,int> P;
char s[N][N];
int a[N][N],dp[N][N];
vector<P>ans;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        ans.clear();
        int n,m;
        scanf("%d%d",&n,&m);
        int p,q;
        scanf("%d%d",&p,&q);
        for(int i=1;i<=n;i++)
            scanf("%s",s[i]+1);
        memset(dp,0,sizeof(dp));
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++) a[i][j]=(s[i][j]=='#');
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++) dp[i][j]=dp[i][j-1]+a[i][j];
        }
        for(int j=1;j<=m;j++){
            for(int i=1;i<=n;i++) dp[i][j]+=dp[i-1][j];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i+p-1<=n && j+q-1<=m){
                    if(dp[i+p-1][j+q-1]-dp[i+p-1][j-1]-dp[i-1][j+q-1]+dp[i-1][j-1]==p*q)
                        ans.push_back(P(i-1,j-1));
                }
            }
        }
        printf("%d\n",ans.size());
        for(int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].first,ans[i].second);
    }
    return 0;
}
