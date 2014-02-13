/*
    sort
*/
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;
#define N 50
struct node{
    int x,y,val;
}P;
vector<node>v,ans;
bool cmp(node a,node b){
    return a.val<b.val;
}
bool ccmp(node a,node b){
    if(a.x==b.x) return a.y>b.y;
    return a.x>b.x;
}
void show(node p){
    int x=1,y=1;
    while(x!=p.x) printf("(%d,%d) ",x++,y);
    while(y!=p.y) printf("(%d,%d) ",x,y++);
    printf("(%d,%d)\n",x,y);
}
int main(){
    int n,m,k,penalty;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF){
        ans.clear();penalty=0;
        v.clear();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                P.x=i,P.y=j,P.val=i+j-1;
                v.push_back(P);
            }
        }
        sort(v.begin(),v.end(),cmp);
        for(int i=0;i<k;i++)
            ans.push_back(v[i]),penalty+=v[i].val;
        sort(ans.begin(),ans.end(),ccmp);
        printf("%d\n",penalty);
        for(int i=0;i<k;i++){
            show(ans[i]);
        }
    }
    return 0;
}
