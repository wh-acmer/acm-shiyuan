// Healthy Recipes
// http://codeforces.com/gym/100499/problem/J
// Ä¸º¯Êý

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
typedef long long LL;
#define N 10010
LL dp[2][N];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m,k,x;
        scanf("%d%d%d",&n,&m,&k);
        memset(dp,0,sizeof dp);
        dp[0][0]=1;
        int now=1;
        bool ok=false;
        for(int c=0;c<n;c++){
            scanf("%d",&x);
            for(int j=0;j<=m;j++){
                dp[now][j]=dp[now^1][j];
            }
            for(int j=0;j+x<=m;j++){
                dp[now][j+x]+=dp[1^now][j];
            }
            if(dp[now][m]>=k) ok=true;
            now^=1;
        }
        now^=1;
        if(ok) printf("ENOUGH\n");
        else printf("%I64d\n",dp[now][m]);
    }
    return 0;
}
