#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 101
int dp[N][N];
char s[N];
int main(){
    while(scanf("%s",&s)!=EOF){
        if(strcmp(s,"end")==0) break;
        memset(dp,0,sizeof(dp));
        int l=strlen(s);
        for(int j=0;j<l;j++){
            for(int i=0;i<j;i++)
                for(int k=i+1;k<=j;k++){
                    if((s[i]=='('&&s[k]==')')||(s[i]=='['&&s[k]==']'))
                        dp[i][j]=max(dp[i][j],dp[i+1][k-1]+2+dp[k+1][j]);
                }
        }
        printf("%d\n",dp[0][l-1]);
    }
    return 0;
}
