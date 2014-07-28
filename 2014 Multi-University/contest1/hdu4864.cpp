#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef long long LL;
typedef pair<int,int>P;
multiset<P>s;
multiset<P>::iterator it;
#define maxn 100010
struct node{
    int x,y;
}p[maxn],q[maxn];
bool cmp(node a,node b){
    if(a.x==b.x) return a.y>b.y;
    return a.x>b.x;
}
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d%d",&p[i].x,&p[i].y);
        }
        LL ans=0,num=0;
        sort(p,p+n,cmp);
        for(int i=0;i<m;i++){
            scanf("%d%d",&q[i].x,&q[i].y);
        }
        sort(q,q+m,cmp);
        int index=0;
        s.clear();
        for(int i=0;i<m;i++){
            while(index<n && p[index].x>=q[i].x){
                s.insert(P(p[index].y,p[index].x));
                index++;
            }
            it=s.lower_bound(P(q[i].y,q[i].x));
            if(it==s.end()) continue;
            num++;
            ans+=500*q[i].x+2*q[i].y;
            s.erase(it);
        }
        printf("%I64d %I64d\n",num,ans);
    }
    return 0;
}
