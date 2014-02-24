#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long LL;
#define N 301
LL f[N],g[N];
int main(){
    int n;
    for(int i=0;i<N;i++) f[i]=1,g[i]=0;
    for(int i=2;i*i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k+j<N;k+=i*i)
                g[j+k]+=f[j];
        }
        memcpy(f,g,sizeof(g));
        memset(g,0,sizeof(g));
    }
    while(scanf("%d",&n)!=EOF && n){
        printf("%lld\n",f[n]);
    }
    return 0;
}
