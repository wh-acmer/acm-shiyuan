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
    while(scanf("%d",&n)!=EOF){
        if(n==0)
            break;
        scanf("%d",&m);
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
        printf("%d\n",ans-1);
    }
    return 0;
}
