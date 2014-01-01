#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define maxn 100005
#define inf ((1ll)<<60)
vector<int>a[maxn];
vector<int>b[maxn];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m,x;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            a[i].clear(),b[i].clear();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                scanf("%d",&x);
                a[i].push_back(x);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                scanf("%d",&x);
                b[i].push_back(x);
            }
        }
        long long dp[2][m];
        int index=0;
        long long mi=inf;
        // dp[0][i] -- 当前物品在第i家店买，累计的值
            for(int j=0;j<m;j++){
                dp[0][j]=a[0][j];
                if(dp[0][j]<mi){
                    mi=dp[0][j];
                    index=j;
                }
            }
        for(int i=1;i<n;i++){
            int pindex=0;
            long long tmp=inf;
            if(i&1){
                for(int j=0;j<m;j++){
                    if(j==index)
                        dp[1][j]=dp[0][j]+max(0,a[i][j]-b[i-1][j]);
                    else
                        dp[1][j]=min(dp[0][index]+a[i][j],dp[0][j]+max(0,a[i][j]-b[i-1][j]));
                    if(dp[1][j]<tmp){
                        tmp=dp[1][j];
                        pindex=j;
                    }
                }
            }
            else{
                for(int j=0;j<m;j++){
                    //dp[1][j]=min(dp[0][index]+a[i][j]);
                    if(j==index)
                        dp[0][j]=dp[1][j]+max(0,a[i][j]-b[i-1][j]);
                    else
                        dp[0][j]=min(dp[1][index]+a[i][j],dp[1][j]+max(0,a[i][j]-b[i-1][j]));
                    if(dp[0][j]<tmp){
                        tmp=dp[0][j];
                        pindex=j;
                    }
                }
            }
            index=pindex;
            mi=tmp;
        }
        printf("%lld\n",mi);
    }
    return 0;
}
