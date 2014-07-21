#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxn 10010
double dp[2*maxn];
int c[110];
double cal(double x){
    return floor((sqrt(5.0)+1)/2*x*x);
}
int main(){
    int n,f;
    while(scanf("%d%d",&n,&f)!=EOF){
        int mx=f;
        for(int i=0;i<n;i++){
            scanf("%d",&c[i]);
            mx=max(mx,c[i]);
        }
        for(int i=2*mx;i>=0;i--) dp[i]=0;
        for(int i=2*mx;i>=0;i--){
            dp[i]=0;
            for(int j=0;j<n;j++){
                if(i>c[j]) dp[i]+=cal(c[j]);
                else{
                    dp[i]+=dp[i+c[j]]+1;
                }
            }
            dp[i]/=n;
        }
        printf("%.3lf\n",dp[f]);
    }
    return 0;
}
