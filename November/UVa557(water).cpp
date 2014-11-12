// Burger
// http://uva.onlinejudge.org/external/5/557.pdf
// water math

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
typedef long long LL;
#define N 100010
double fac[N];
void init(){
    fac[0]=log(1.0);
    for(int i=1;i<N;i++){
        fac[i]=fac[i-1]+log(i+0.0);
    }
}
int main(){
    int n,T;
    scanf("%d",&T);
    init();
    while(T--){
        scanf("%d",&n);
        double ans=0;
        n/=2;
        ans+=fac[2*n-2]-2*fac[n-1];
        ans-=(2*n-2)*log(2);
        printf("%.4lf\n",1-exp(ans));
    }
    return 0;
}
