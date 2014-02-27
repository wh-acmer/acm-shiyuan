#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;
#define maxn 20
int p[maxn],e[maxn],pp[maxn],a[maxn];
set<int>s;
int main(){
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF){
        int ans=0x3ffffff;
        for(int i=0;i<n;i++) scanf("%d%d",&p[i],&e[i]);
        for(int i=0;i<(1<<n);i++){
            for(int j=0;j<n;j++) pp[j]=p[j];
            int state=i,get=0,effort=0;
            int now=0;
            s.clear();
            memset(a,0,sizeof(a));
            while(state){
                if(state&1) a[now]=1;
                else a[now]=0;
                now++,state/=2;
            }
            for(int j=0;j<n;j++){
                if(a[j]) get++,effort+=e[j];
                else pp[j]++,s.insert(j);
            }
            int l=0,r=0;
            for(int j=0;j<n;j++) {
                if(pp[j]>get) l++;
                else if(pp[j]==get && s.count(j)) l++;
            }
            if(l+1<=k) ans=min(ans,effort);
        }
        if(ans==0x3ffffff) ans=-1;
        printf("%d\n",ans);
    }
    return 0;
}
