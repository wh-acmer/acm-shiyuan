#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
typedef long long LL;
LL g[11],f[11];
vector<LL>v;
int main(){
    v.push_back(1ll);
    for(int i=1;i<=10;i++) v.push_back(v[v.size()-1]*i);
    int n,m,x;
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(f,0,sizeof(f)),memset(g,0,sizeof(g));
        scanf("%d",&x); n--;
        for(int i=0;i<=x;i++) f[i]=1;
        while(n--){
            scanf("%d",&x);
            for(int j=0;j<=m;j++){
                for(int k=0;k+j<=m&&k<=x;k++){
                    g[j+k]+=f[j]*v[j+k]/v[j]/v[k];
                }
            }
            memcpy(f,g,sizeof(f));
            memset(g,0,sizeof(g));
        }
        printf("%I64d\n",f[m]);
    }
    return 0;
}
