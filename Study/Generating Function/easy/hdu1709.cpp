#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
using namespace std;
#define maxn 10010
int f[2*maxn],g[2*maxn];
vector<int>v;
int main(){
    int n,x;
    while(scanf("%d",&n)!=EOF){
        memset(f,0,sizeof(f)),memset(g,0,sizeof(g));
        int sum=0; v.clear();
        scanf("%d",&x); sum+=x;
        f[maxn+x]=f[maxn-x]=f[maxn]=1;
        for(int i=1;i<n;i++){
            scanf("%d",&x); sum+=x;
            for(int j=0;j<2*maxn;j++){
                if(f[j]){
                    g[j]=f[j];
                    if(j-x>=0) g[j-x]+=f[j];
                    if(j+x<maxn*2) g[j+x]+=f[j];
                }
            }
            memcpy(f,g,sizeof(g));
            memset(g,0,sizeof(g));
        }
        for(int i=1;i<=sum;i++) if(!f[maxn+i]) v.push_back(i);
        printf("%d\n",v.size());
        for(int i=0;i<v.size();i++){
            printf("%d",v[i]);
            if(i==v.size()-1) printf("\n");
            else printf(" ");
        }
    }
    return 0;
}
