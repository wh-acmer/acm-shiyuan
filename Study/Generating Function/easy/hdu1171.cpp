#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long LL;
#define maxn 125010
LL f[maxn],g[maxn];
int main(){
    int n,V,M,sum;
    while(scanf("%d",&n)!=EOF){
        if(n<0)  break;  sum=0;
        scanf("%d%d",&V,&M); sum+=V*M;
        memset(f,0,sizeof(f)),memset(g,0,sizeof(g));
        for(int i=0;i<=M;i++) f[i*V]=1;
        for(int i=1;i<n;i++){
            scanf("%d%d",&V,&M),sum+=V*M;
            for(int j=0;j<maxn;j++){
                for(int k=0;k<=V*M && k+j<maxn;k+=V)
                    g[j+k]+=f[j];
            }
            memcpy(f,g,sizeof(g));
            memset(g,0,sizeof(g));
        }
        int ans=0;
        for(int i=sum/2;i>=0;i--){
            if(f[i]){
                ans=i;
                break;
            }
        }
        printf("%d %d\n",sum-ans,ans);
    }
    return 0;
}
