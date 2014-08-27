#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long LL;
LL dp[11][144][101];
int cnt[1<<10];
vector<int>v[11];
void init(){
    memset(cnt,0,sizeof cnt);
    for(int i=0;i<(1<<10);i++){
        int tmp=i;
        while(tmp){
            if(tmp&1){
                cnt[i]++;
            }
            tmp>>=1;
        }
    }
    for(int i=1;i<=10;i++){
        v[i].clear();
        for(int j=0;j<(1<<i);j++){
            if((j&(j<<1))==0 && (j&(j>>1))==0){
                v[i].push_back(j);
            }
        }
    }
}
int main(){
    init();
    int n,K;
    while(scanf("%d%d",&n,&K)!=EOF){
        int now=0;
        memset(dp[now],0,sizeof dp[now]);
        dp[0][0][0]=1;
        now^=1;
        for(int i=1;i<=n;i++){
            memset(dp[now],0,sizeof dp[now]);
            for(int j=0;j<v[n].size();j++){
                for(int k=0;k<v[n].size();k++){
                    if((v[n][k]&v[n][j])==0 && (v[n][j]&(v[n][k]>>1))==0 && (v[n][k]&(v[n][j]>>1))==0 ){
                        for(int x=cnt[v[n][j]];x<=K;x++){
                            dp[now][j][x]+=dp[1^now][k][x-cnt[v[n][j]]];
                        }
                    }
                }
            }
            now^=1;
        }
        LL ans=0;
        for(int i=0;i<v[n].size();i++){
            ans+=dp[1^now][i][K];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
