#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
#define N 51
typedef __int64 LL;
LL f[N],g[N];
int main(){
    int T,x; scanf("%d",&T);
    while(T--){
        memset(f,0,sizeof(f)),memset(g,0,sizeof(g)); f[0]=1;
        for(int i=0;i<26;i++){
            scanf("%d",&x);
            for(int j=0;j<N;j++){
                for(int k=0;k*(i+1)+j<N&&k<=x;k++)
                    g[j+k*(i+1)]+=f[j];
            }
            memcpy(f,g,sizeof(f)),memset(g,0,sizeof(g));

        }
        for(int i=2;i<N;i++) f[i]+=f[i-1];
        printf("%lld\n",f[N-1]);
    }
    return 0;
}
