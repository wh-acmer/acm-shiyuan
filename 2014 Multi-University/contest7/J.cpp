#include <cstdio>
#include <iostream>
#include <cmath>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define maxn 500010
typedef long long LL;
#define mod (1LL<<32)
LL Sum[maxn],g[maxn];
void init(){
    memset(g,0,sizeof g);
    for(LL i=1;i<maxn;i++){
        for(LL j=i;j<maxn;j+=i){
            g[j]+=(j/i+1)*(j/i)/2;
        }
    }
    Sum[0]=0;
    for(int i=1;i<maxn;i++){
        Sum[i]=Sum[i-1]+g[i]*i;
        Sum[i]%=mod;
    }
}
int main(){
    init();
    int T,cas=0;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        printf("Case #%d: %I64d\n",++cas,Sum[n]);
    }
    return 0;
}
