#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
#define N 110
char s[N];
int dp[N][N];
int main(){
    while(scanf("%s",&s)!=EOF){
        if(strcmp(s,"end")==0){
            break;
        }
        int len=strlen(s);
        memset(dp,0,sizeof(dp));
        for(int j=0;j<len;j++){
            for(int i=j-1;i>=0;i--){
                dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                for(int k=i+1;k<=j;k++){
                    if((s[i]=='('&&s[k]==')')||(s[i]=='['&&s[k]==']')){
                        dp[i][k]=max(dp[i][k],dp[i+1][k-1]+2);
                    }
                    dp[i][j]=max(dp[i][k]+dp[k+1][j],dp[i][j]);
                }
            }
        }
        printf("%d\n",dp[0][len-1]);
    }
    return 0;
}
