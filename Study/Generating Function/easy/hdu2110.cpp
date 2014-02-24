#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
typedef __int64 LL;
#define maxn 10010
#define mod 10000
int n,p[101],m[101],sum;
LL f[maxn],g[maxn];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF && n){
        sum=0;
        for(int i=0;i<n;i++) scanf("%d%d",&p[i],&m[i]),sum+=p[i]*m[i];
        LL cnt=sum/3;
        memset(f,0,sizeof(f)),memset(g,0,sizeof(g)),f[0]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<=cnt;j++){
                for(int k=0;k*p[i]+j<=cnt&&k<=m[i];k++)
                    g[k*p[i]+j]=(f[j]+g[k*p[i]+j])%mod;
            }
            memcpy(f,g,sizeof(f));
            memset(g,0,sizeof(g));
        }
        if(f[cnt]==0 || cnt*3!=sum) printf("sorry\n");
        else printf("%I64d\n",f[cnt]%mod);
    }
}
