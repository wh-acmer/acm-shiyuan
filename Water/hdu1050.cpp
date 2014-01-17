/*
    尽量少的回合做完所有操作
    按开始时间排序
    注意一下对门的那种关系，我是把所有奇数变成偶数做的
    例如 1 3  和 4 5  转化成 2 4 和 4 6 需要两个回合
*/
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define maxn 210
struct node{
    int st,ed;
    bool ok;
}p[maxn];
bool cmp(node a,node b)
{
    if(a.st==b.st) return a.ed<b.ed;
    return a.st<b.st;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        vector<node>v1,v2;
        v1.clear();
        v2.clear();
        for(int i=0;i<n;i++){
            scanf("%d%d",&p[i].st,&p[i].ed);
            if(p[i].st>p[i].ed) swap(p[i].ed,p[i].st);
            if(p[i].st&1) p[i].st++;
            if(p[i].ed&1) p[i].ed++;
            p[i].ok=true;
            v1.push_back(p[i]);
        }
        int ans=0;
        while(true){
            if(v1.empty()) break;
            sort(v1.begin(),v1.end(),cmp);
            int now=v1[0].ed;
            v1[0].ok=false;
            for(int i=1;i<v1.size();i++){
                if(v1[i].st>now){
                    v1[i].ok=false;
                    now=v1[i].ed;
                }
            }
            v2.clear();
            for(int i=0;i<v1.size();i++){
                if(v1[i].ok) v2.push_back(v1[i]);
            }
            v1.clear();
            v1.assign(v2.begin(),v2.end());
            ans++;
        }
        printf("%d\n",ans*10);
    }
    return 0;
}
