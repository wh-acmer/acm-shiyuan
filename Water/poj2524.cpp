#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define maxn 50010
int pre[maxn];
int find(int x){
    if(pre[x]!=x){
        pre[x]=find(pre[x]);
    }
    return pre[x];
}
void mix(int x,int y){
    int px=find(x);
    int py=find(y);
    if(px>py) swap(px,py);
    pre[py]=px;
}
int main(){
    int n,m,x,y,cas=0;
    while(scanf("%d%d",&n,&m)!=EOF){
        if(n+m==0)  break;
        for(int i=1;i<=n;i++)   pre[i]=i;
        for(int i=1;i<=m;i++){
            scanf("%d%d",&x,&y);
            mix(x,y);
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(pre[i]==i)
                ans++;
        }
        printf("Case %d: %d\n",++cas,ans);
    }
    return 0;
}
