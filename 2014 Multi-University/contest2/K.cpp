#include <cstring>
#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
using namespace std;
typedef long long LL;
#define maxn 100010
typedef long long LL;
struct node{
    int e,k;
}p[maxn];
bool cmp(node a,node b){
    if(a.e*b.k==a.k*b.e) return a.k>b.k;
    return a.e*b.k<a.k*b.e;
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++) scanf("%d",&p[i].e);
        for(int i=0;i<n;i++) scanf("%d",&p[i].k);
        sort(p,p+n,cmp);
        LL ans=0,now=0;
        for(int i=0;i<n;i++){
            now+=p[i].e;
            ans+=now*p[i].k;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
