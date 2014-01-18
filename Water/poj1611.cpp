/*
题意：编号0~n-1的n个人，被分成m组，每组内的人都可以传染，已知0被感染，求被感染的总人数
思路：开始的时候是先判组与组能否合并，最后求集合总元素，结果RE了，防爆栈也不行
后来的做法是，每组的其余人祖先跟第一个人不同的就合并，最后看跟0祖先相同的人数
*/
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;
#define maxn 30010
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
    if(px>py) swap(px,py);
    pre[py]=px;
}
int main(){
    int n,m,x,y,k;
    while(scanf("%d%d",&n,&m)!=EOF){
        if(n+m==0)
            break;
        for(int i=0;i<n;i++)
            pre[i]=i;
        for(int i=1;i<=m;i++){
            scanf("%d",&k);
            scanf("%d",&x);
            for(int j=1;j<k;j++){
                scanf("%d",&y);
                if(find(x)!=find(y))
                    mix(x,y);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
            if(find(0)==find(i))
                ans++;
        printf("%d\n",ans);
    }
    return 0;
}
