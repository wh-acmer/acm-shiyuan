// GCD XOR
// http://uva.onlinejudge.org/external/127/12716.pdf
// 预处理 类似筛法

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define N 30000005
int dp[N];
int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
void init(){
    memset(dp,0,sizeof dp);
    for(int i=1;i<N;i++){
        for(int j=2*i;j<N;j+=i){
            if((i^j)==(j-i)){
                dp[j]++;
            }
        }
    }
    for(int i=1;i<N;i++){
        dp[i]+=dp[i-1];
    }
}
int main(){
    int T;
    scanf("%d",&T);
    init();
    for(int cas=1;cas<=T;cas++){
        int n;
        scanf("%d",&n);
        printf("Case %d: %d\n",cas,dp[n]);
    }
    return 0;
}
