#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
vector<int>v[42];
vector<int>::iterator it[42];
int value[42];
int last[42];
int main(){
    int T,cas=0;
    scanf("%d",&T);
    while(T--){
        int n,m,x,y;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++) scanf("%d",&value[i]);
        for(int i=1;i<=n;i++){
            last[i]=-1;
            scanf("%d",&x);
            v[i].clear();
            for(int j=1;j<=x;j++) scanf("%d",&y),v[i].push_back(value[y]);
            sort(v[i].begin(),v[i].end());
            it[i]=v[i].begin();
        }
        int now=0;
        long long ans=0;
        while(1){
            bool ok=true;
            for(int i=1;i<=n;i++){
                if(it[i]!=v[i].end()){
                    ok=false;
                    now+=*it[i];
                    if(last[i]==-1){
                        ans+=now;
                        last[i]=now;
                    }
                    else{
                        ans+=max(0,now-last[i]-20);
                        last[i]=now;
                    }
                    it[i]++;
                }
            }
            if(ok) break;
        }
        printf("Case %d: %lld\n",++cas,ans);
    }
    return 0;
}
