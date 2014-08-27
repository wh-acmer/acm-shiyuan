#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int dp[2][(1<<20)];
vector<int>v;
int n;
int a[20][20];
void init(){
    v.clear();
    for(int i=0;i<(1<<n);i++){
        if((i&(i<<1))==0 && (i&(i>>1))==0){
            v.push_back(i);
        }
    }
}
int main(){
    while(scanf("%d",&n)!=EOF){
        init();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&a[i][j]);
            }
        }
        memset(dp,0,sizeof dp);
        for(int i=0;i<v.size();i++){
            dp[0][v[i]]=0;
            int status=v[i];
            for(int j=0;j<n;j++){
                if(status&1){
                    dp[0][v[i]]+=a[0][j];
                }
                status>>=1;
            }
        }
        int now=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<(1<<n);j++){
                dp[now][j]=0;
            }
            for(int j=0;j<v.size();j++){
                int status=v[j],tmp=0;
                for(int k=0;k<n;k++){
                    if(status&1){
                        tmp+=a[i][k];
                    }
                    status>>=1;
                }
                for(int k=0;k<v.size();k++){
                    if((v[j]&v[k])==0){
                        if(dp[1^now][v[k]]>dp[now][v[j]]){
                            dp[now][v[j]]=dp[1^now][v[k]];
                        }
                    }
                }
                dp[now][v[j]]+=tmp;
            }
            now^=1;
        }
        int ans=0;
        for(int i=0;i<(1<<n);i++){
            if(dp[now^1][i]>ans){
                ans=dp[now^1][i];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
