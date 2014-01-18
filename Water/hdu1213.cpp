#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;
#define maxn 1010
int pre[maxn];
int find(int x){
    if(x!=pre[x]){
        pre[x]=find(pre[x]);
    }
    return pre[x];
}
void mix(int x,int y){
    int px=find(x);
    int py=find(y);
    if(px>py)   swap(px,py);
    pre[py]=px;
}
int main()
{
    int n,m,x,y;
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            pre[i]=i;
        for(int i=1;i<=m;i++){
            scanf("%d%d",&x,&y);
            mix(x,y);
        }
        int ans=0;
        for(int i=1;i<=n;i++)
            if(pre[i]==i)
                ans++;
        printf("%d\n",ans);
    }
    return 0;
}
