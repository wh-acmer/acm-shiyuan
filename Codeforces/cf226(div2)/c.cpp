#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
#define maxn 10000010
bool vis[maxn];
int s[maxn],mx[maxn];
int main(){
    memset(vis,true,sizeof(vis));
    memset(mx,0,sizeof(mx));
    vis[0]=vis[1]=false;
    for(int i=2;i<maxn;i++){
        if(vis[i]){
            mx[i]=i;
            for(int j=2*i;j<maxn;j+=i){
                vis[j]=false;
                if(mx[j]==0) mx[j]=i;
            }
        }
    }
    int n,x,tmp;
    while(scanf("%d",&n)!=EOF){
        memset(s,0,sizeof(s));
        for(int i=0;i<n;i++){
            scanf("%d",&x);
            tmp=0;
            while(x!=1){
                if(tmp!=mx[x]) s[mx[x]]++,tmp=mx[x];
                x/=mx[x];
            }
        }
        for(int i=1;i<maxn;i++)
            s[i]+=s[i-1];
        int m,l,r;
        scanf("%d",&m);
        while(m--){
            scanf("%d%d",&l,&r);
            if(r>maxn-1) r=maxn-1;
            if(r>=l-1)  printf("%d\n",s[r]-s[l-1]);
            else printf("0\n");
        }
    }
    return 0;
}
