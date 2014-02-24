#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
#define N 105
typedef long long LL;
LL f[N],g[N];
int main(){
    int n,m,x,y;
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(f,0,sizeof(f)),memset(g,0,sizeof(g));
        scanf("%d%d",&x,&y),n--;
        for(int i=x;i<=y;i++) f[i]=1;
        while(n--){
            scanf("%d%d",&x,&y);
            for(int i=0;i<=m;i++){
                for(int j=x;i+j<=m&&j<=y;j++)
                    g[i+j]+=f[i];
            }
            memcpy(f,g,sizeof(g));
            memset(g,0,sizeof(g));
        }
        printf("%lld\n",f[m]);
    }
    return 0;
}
