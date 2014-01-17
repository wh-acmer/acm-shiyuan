#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
#define maxn 5001
struct node{
    int l,w;
}p[maxn];
bool cmp(node a,node b){
    if(a.l==b.l) return a.w<b.w;
    return a.l<=b.l;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        vector<node>v;
        v.clear();
        for(int i=0;i<n;i++){
            scanf("%d%d",&p[i].l,&p[i].w);
            v.push_back(p[i]);
        }
        sort(v.begin(),v.end(),cmp);
        vector<node>tmp;
        int ans=0;
        while(true){
            if(v.empty()) break;
            tmp.clear();
            int l=v[0].l,w=v[0].w;
            for(int i=1;i<v.size();i++){
                if(l<=v[i].l && w<=v[i].w){
                    l=v[i].l;
                    w=v[i].w;
                }
                else{
                    tmp.push_back(v[i]);
                }
            }
            ans++;
            //v.clear();
            v.assign(tmp.begin(),tmp.end());
        }
        printf("%d\n",ans);
    }
    return 0;
}
