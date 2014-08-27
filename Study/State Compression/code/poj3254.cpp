#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 13
#define mod 100000000
int a[N];
vector<int>v;
int row,col,x;
LL dp[2][400];
void init(){
    v.clear();
    for(int i=0;i<(1<<col);i++){
        if((i&(i>>1))==0 && (i&(i<<1))==0){
            v.push_back(i);
        }
    }
}
int main(){
    while(scanf("%d%d",&row,&col)!=EOF){
        init();
        for(int i=1;i<=row;i++){
            a[i]=0;
            for(int j=col;j>=1;j--){
                scanf("%d",&x);
                if(x){
                    a[i]|=(1<<(j-1));
                }
            }
        }
        memset(dp[0],0,sizeof dp[0]);
        dp[0][0]=1;
        a[0]=0;
        int now=1;
        for(int i=1;i<=row;i++){
            memset(dp[now],0,sizeof dp[now]);
            for(int j=0;j<v.size();j++){
                if((a[i]&v[j])==v[j]){
                    for(int k=0;k<v.size();k++){
                        if((v[k]&v[j])==0 && (v[k]&a[i-1])==v[k]){
                            dp[now][j]+=dp[now^1][k];
                            dp[now][j]%=mod;
                        }
                    }
                }
            }
            now^=1;
        }
        LL ans=0;
        for(int i=0;i<v.size();i++){
            ans+=dp[now^1][i];
            ans%=mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
