#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
typedef __int64 LL;
LL val[4][4];
LL ans;
LL dp[45][4][4][4];
LL dfs(int n,int x,int y,int z){
    if(dp[n][x][y][z]!=-1) return dp[n][x][y][z];
    return dp[n][x][y][z]=min(dfs(n-1,x,z,y)+val[x][z]+dfs(n-1,y,x,z),
     dfs(n-1,x,y,z)+val[x][y]+dfs(n-1,z,y,x)+val[y][z]+dfs(n-1,x,y,z));
}
int main(){
    while(scanf("%I64d",&val[1][1])!=EOF){
        for(int i=1;i<=3;i++) for(int j=1;j<=3;j++)
            if(i!=1 || j!=1) scanf("%d",&val[i][j]);
        for(int i=1;i<45;i++) for(int j=1;j<=3;j++) for(int k=1;k<=3;k++)
            for(int l=1;l<=3;l++) dp[i][j][k][l]=-1;
        int n; scanf("%d",&n);
        printf("%I64d\n",dfs(n,1,2,3));
    }
    return 0;
}
