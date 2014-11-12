// Send a Table
// http://uva.onlinejudge.org/external/108/10820.pdf
// Euler

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
#define N 50010
typedef long long LL;
LL phi[N];
void init(){
    for(int i=2;i<N;i++) phi[i]=0;
    phi[1]=0;
    for(int i=2;i<N;i++){
        if(!phi[i]){
            for(int j=i;j<N;j+=i){
                if(!phi[j]) phi[j]=j;
                phi[j]=phi[j]/i*(i-1);
            }
        }
    }
    for(int i=3;i<N;i++){
        phi[i]+=phi[i-1];
    }
}
int main(){
    int n;
    init();
    while(scanf("%d",&n)!=EOF){
        if(n==0) break;
        printf("%lld\n",2*phi[n]+1);
    }
    return 0;
}
