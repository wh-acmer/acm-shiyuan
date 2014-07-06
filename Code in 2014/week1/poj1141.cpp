#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
#define N 1100
char s[N];
int dp[N][N],a[N][N],b[N];
void solve(int i,int j){
    if(i>=j) return ;
    if(a[i][j]==-1) solve(i+1,j);
    else{
        b[i]=1;
        b[a[i][j]]=1;
        solve(i+1,a[i][j]-1);
        solve(a[i][j]+1,j);
    }
}
int main(){
    while(gets(s)){
        if(strcmp(s,"")==0){
            printf("\n");
            continue;
        }
        int l=strlen(s);
        memset(dp,0,sizeof(dp));
        memset(a,-1,sizeof(a));
        memset(b,0,sizeof(b));
        for(int i=0;i<l;i++){
            dp[i][i]=1;
        }
        for(int j=0;j<l;j++){
            for(int i=j;i>=0;i--){
                dp[i][j]=dp[i+1][j]+1;
                for(int k=i+1;k<=j;k++){
                    if((s[i]=='('&&s[k]==')')||(s[i]=='['&&s[k]==']')){
                        if(dp[i][j]>dp[i+1][k-1]+dp[k][j]-1){
                            dp[i][j]=dp[i+1][k-1]+dp[k][j]-1;
                            a[i][j]=k;
                        }
                    }
                }
            }
        }
        /*printf("%d\n",dp[0][l-1]);
        for(int i=0;i<l;i++){
            for(int j=0;j<l;j++){
                printf("%d ",a[i][j]);
            }
            printf("\n");
        }*/
        solve(0,l-1);
        for(int i=0;i<l;i++){
            if(b[i]==1){
                printf("%c",s[i]);
            }
            else{
                if(s[i]=='('||s[i]==')'){
                    printf("()");
                }
                else{
                    printf("[]");
                }
            }
        }
        printf("\n");
    }
    return 0;
}
