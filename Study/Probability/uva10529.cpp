#include <iostream>
#include <cmath>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdio>
#include <map>
#include <cstring>
using namespace std;
#define maxn 1010
double dp[maxn],pl,pr;
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        if(n==0) break;
        scanf("%lf%lf",&pl,&pr);
        if(pl>pr) swap(pl,pr);
        double e1=(1-pr)/(1-pl-pr);
        double e2=(1-pl)/(1-pl-pr);
        double e3=1/(1-pl-pr);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            dp[i]=e2*dp[i-1]+e3;
            for(int j=1;j<i;j++){
                dp[i]=min(dp[i],dp[j]*e1+dp[i-1-j]*e2+e3);
            }
        }
        printf("%.2lf\n",dp[n]);
    }
    return 0;
}
