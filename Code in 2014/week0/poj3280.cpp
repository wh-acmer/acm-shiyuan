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
using namespace std;
#define maxn 2010
char s[maxn],al[10];
int dp[maxn][maxn];
int val[30];
int main(){
    int n,m,x,y;
    while(scanf("%d%d",&n,&m)!=EOF){
        scanf("%s",s+1);
        for(int i=1;i<=n;i++){
            scanf("%s%d%d",&al,&x,&y);
            val[al[0]-'a']=min(x,y);
        }
        for(int i=1;i<=m;i++)
            for(int j=1;j<=m;j++)
                if(i<j) dp[i][j]=0x3fffffff;
                else dp[i][j]=0;

        for(int j=1;j<=m;j++){
            for(int i=j;i>=1;i--){
                dp[i][j]=min(dp[i][j],dp[i+1][j]+val[s[i]-'a']);
                dp[i][j]=min(dp[i][j],dp[i][j-1]+val[s[j]-'a']);
                if(s[i]==s[j]) dp[i][j]=min(dp[i][j],dp[i+1][j-1]);
            }
        }
        printf("%d\n",dp[1][m]);
    }
    return 0;
}
