#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
map<string,int>wet;
map<int,string>wether;
void init(){
    wet.clear(); wether.clear();
    wet["Dry"]=0; wet["Dryish"]=1; wet["Damp"]=2; wet["Soggy"]=3;
    wether[0]="Sunny"; wether[1]="Cloudy"; wether[2]="Rainy";
}
double p1[3][3]={{0.5,0.375,0.125},{0.25,0.125,0.625},{0.25,0.375,0.375}};
double p2[3][4]={{0.6,0.2,0.15,0.05},{0.25,0.3,0.2,0.25},{0.05,0.10,0.35,0.50}};
double dp[52][3];
char s[10];
int p[52][3];
void solve(int n,int last){
    if(n==0) return ;
    solve(n-1,p[n][last]);
    printf("%s\n",wether[last].c_str());
}
int main(){
    init(); int T; scanf("%d",&T);
    for(int cas=1;cas<=T;cas++){
        int n; scanf("%d",&n); printf("Case #%d:\n",cas);
        for(int i=1;i<=n;i++){
            for(int j=0;j<=2;j++)
                dp[i][j]=-1;
        }
        dp[1][0]=0.63,dp[1][1]=0.17,dp[1][3]=0.20;
        for(int i=1;i<=n;i++){
            scanf("%s",&s);
            int now=wet[s];
            for(int j=0;j<3;j++){
                if(i==1) dp[i][j]=dp[i][j]*p2[j][now];
                else{
                    dp[i][j]=-1;
                    for(int k=0;k<3;k++){
                        if(dp[i][j]<dp[i-1][k]*p1[k][j]*p2[j][now]){
                            dp[i][j]=dp[i-1][k]*p1[k][j]*p2[j][now];
                            p[i][j]=k;
                        }
                    }
                }
            }
        }
        int last=0;
        for(int i=0;i<3;i++){
            if(dp[n][i]>dp[n][last]){
                last=i;
            }
        }
        solve(n,last);
    }
    return 0;
}
