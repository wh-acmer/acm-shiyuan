#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
typedef long long LL;
#define maxn 1000010
#define mod 1000000000
LL dp[maxn];
int main(){
    int n;
    dp[1]=1;
    for(int i=2;i<maxn;i++){
        dp[i]=dp[i-1];
        if(i%2==0) dp[i]+=dp[i/2];
        dp[i]%=mod;
    }
    while(scanf("%d",&n)!=EOF){
        printf("%lld\n",dp[n]);
    }
    return 0;
}
