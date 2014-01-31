#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#include <cstdio>
#include <map>
using namespace std;
#define maxn 100005
typedef __int64 LL;
int ki[maxn];
int l[maxn],c[maxn];
vector<LL>index;
//map<LL,int>mp;
int solve(LL now){
    //if(mp[now]) return mp[now];
    int tmp=lower_bound(index.begin(),index.end(),now)-index.begin();
    if(ki[tmp]==1) return l[tmp];//mp[now]=l[tmp];
    else{
        long long pt=now-index[tmp-1];
        pt%=l[tmp];
        if(pt==0) pt+=l[tmp];
        return solve(pt);
    }
}
int main(){
    int m,n,kind;
    while(scanf("%d",&m)!=EOF){
        index.clear();
        //mp.clear();
        LL now=0;
        for(int i=0;i<m;i++){
            scanf("%d",&ki[i]);
            if(ki[i]==1){
                scanf("%d",&l[i]);
                now++;
                index.push_back(now);
            }
            else{
                scanf("%d%d",&l[i],&c[i]);
                now+=l[i]*c[i];
                index.push_back(now);
            }
        }
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%I64d",&now);
            if(i+1==n) printf("%d\n",solve(now));
            else printf("%d ",solve(now));
        }
    }
    return 0;
}
