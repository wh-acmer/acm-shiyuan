#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long LL;
vector<int>w,b;
LL dp[11][111],dq[11][111];
int main(){
    int n,K;
    while(scanf("%d%d",&n,&K)!=EOF){
        w.clear(),b.clear();
        w.push_back(n);
        for(int i=n-2;i>=1;i-=2){
            w.push_back(i);
            w.push_back(i);
        }
        for(int i=n-1;i>=1;i-=2){
            b.push_back(i);
            b.push_back(i);
        }
        sort(w.begin(),w.end());
        sort(b.begin(),b.end());
        memset(dp,0,sizeof dp);
        dp[0][0]=1;
        for(int i=0;i<w.size();i++){
            for(int j=0;j<=i+1;j++){
                dp[i+1][j]=dp[i][j];
            }
            for(int j=1;j<=i+1 && w[i]-(j-1)>=0;j++){
                dp[i+1][j]+=(w[i]-(j-1))*dp[i][j-1];
            }
        }
        memset(dq,0,sizeof dq);
        dq[0][0]=1;
        for(int i=0;i<b.size();i++){
            for(int j=0;j<=i+1;j++){
                dq[i+1][j]=dq[i][j];
            }
            for(int j=1;j<=i+1 && b[i]-(j-1)>=0;j++){
                dq[i+1][j]+=(b[i]-(j-1))*dq[i][j-1];
            }
        }
        LL ans=0;
        for(int k=0;k<=K;k++){
            ans+=dp[w.size()][k]*dq[b.size()][K-k];
        }
        printf("%lld\n",ans);
    }
    return 0;
}

