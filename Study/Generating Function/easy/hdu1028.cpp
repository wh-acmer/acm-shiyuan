#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
#define maxn 121
typedef long long LL;
LL f[maxn],g[maxn];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<=n;i++) f[i]=1,g[i]=0;
        for(int i=2;i<=n;i++){
            for(int j=0;j<=n;j++){
                for(int k=0;k+j<=n;k+=i)
                    g[k+j]+=f[j];
            }
            memcpy(f,g,sizeof(g));
            memset(g,0,sizeof(g));
        }
        printf("%lld\n",f[n]);
    }
    return 0;
}
