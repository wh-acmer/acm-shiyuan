#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
using namespace std;
#define maxn 100010
double dp[maxn],dq[maxn];
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        dp[0]=0;
        dp[1]=1;
        double ans=1;
        for(int i=2;i<=m;i++){
            dp[i]=dp[i-1]*dq[i-1]+(dp[i-1]-1.0/n)*dp[i-1];
            dq[i]=1-dp[i];
            ans+=dp[i];
        }
        printf("%.12lf\n",ans);
    }
    return 0;
}
