#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
#define mod 1000000007
#define N 1000010
typedef long long LL;
LL f[N];
int main(){
    f[1]=1;f[2]=2;
    for(int i=3;i<N;i++) f[i]=(f[i-1]+f[i-2])%mod;
    int t;
    scanf("%d",&t);
    while(t--){
        int n; scanf("%d",&n);
        printf("%lld\n",f[n]);
    }
    return 0;
}
