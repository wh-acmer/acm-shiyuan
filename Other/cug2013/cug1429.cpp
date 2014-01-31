/*
    题意：10w条线段，求相交的最大值
    思路：排序后，起点相同的保留长度最长的
    然后按x从小到大往右扫，mx记录当前出现的最右端点
    l表示当前线段的左边，r表示右边，r=min(v[i].y,mx);
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
#define maxn 100010
struct seg{
    int x,y;
}p[maxn];
bool cmp(seg a,seg b){
    if(a.x==b.x) return a.y>b.y;
    return a.x<b.x;
}
vector<seg>v;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        v.clear();
        for(int i=0;i<n;i++){
            scanf("%d%d",&p[i].x,&p[i].y);
        }
        sort(p,p+n,cmp);
        v.push_back(p[0]);
        int x=p[0].x;
        for(int i=1;i<n;i++){
            if(p[i].x!=x){
                v.push_back(p[i]);
                x=p[i].x;
            }
        }
        int mi=p[0].x,l=mi,mx=p[0].y,r=mx;
        int ans=0;
        for(int i=1;i<v.size();i++){
            l=v[i].x;
            r=min(mx,v[i].y);
            if(v[i].y>mx){
                mx=v[i].y;
            }
            ans=max(ans,r-l);
        }
        printf("%d\n",ans);
    }
    return 0;
}
