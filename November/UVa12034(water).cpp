// Race
// http://uva.onlinejudge.org/external/120/12034.pdf
// 组合数+预处理

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
typedef long long LL;
const LL mod=10056;
const int N=1010;
LL C[N][N];
LL f[N];
void init(){
    for(int i=0;i<N;i++){
        C[i][0]=C[i][i]=1;
    }
    for(int i=2;i<N;i++){
        for(int j=1;j<i;j++){
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
        }
    }
    f[0]=1;
    for(int i=1;i<N;i++){
        f[i]=0;
        for(int j=1;j<=i;j++){
            f[i]+=f[i-j]*C[i][j];
            f[i]%=mod;
        }
    }
}
int main(){
    init();
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++){
        int n;
        scanf("%d",&n);
        printf("Case %d: %lld\n",cas,f[n]);
    }
    return 0;
}
