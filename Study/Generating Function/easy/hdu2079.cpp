#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 45
typedef __int64 LL;
LL g[N],f[N];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,k,a,b; scanf("%d%d",&n,&k);
        memset(f,0,sizeof(f)),memset(g,0,sizeof(g)),f[0]=1;
        while(k--){
            scanf("%d%d",&a,&b);
            for(int i=0;i<=n;i++){
                for(int j=0;j*a+i<=n&&j<=b;j++) g[j*a+i]+=f[i];
            }
            memcpy(f,g,sizeof(f)),memset(g,0,sizeof(g));
        }
        printf("%lld\n",f[n]);
    }
    return 0;
}
