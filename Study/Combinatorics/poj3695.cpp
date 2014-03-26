#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
struct rec{
    int lx,ly,rx,ry;
}p[21],R;
int n,Q;
int q[100010];
int ans[(1<<20)+1];
rec jiao(rec a,rec b){
    rec ans;
    ans.lx=a.lx>b.lx?a.lx:b.lx,ans.ly=a.ly>b.ly?a.ly:b.ly;
    ans.rx=a.rx<b.rx?a.rx:b.rx,ans.ry=a.ry<b.ry?a.ry:b.ry;
    return ans;
}
int cal(rec a){
    int ans=(a.rx-a.lx)*(a.ry-a.ly);
    return ans>0?ans:0;
}
void dfs(rec R,int now,int count,int status){
    if(R.lx>=R.rx || R.ly>=R.ry) return ;
    if(now==n){
        if(!status) return ;
        for(int i=1;i<=Q;i++){
            if((q[i]|status)==q[i]){
                if(count&1) ans[q[i]]+=cal(R);
                else ans[q[i]]-=cal(R);
            }
        }
        return ;
    }
    dfs(R,now+1,count,status);
    dfs(jiao(R,p[now+1]),now+1,count+1,(status|(1<<now)));
}
int main(){
    int cas=0;
    while(scanf("%d%d",&n,&Q)!=EOF){
        if(n==0 && Q==0) break;
        memset(ans,0,sizeof(ans));
        for(int i=1;i<=n;i++) scanf("%d%d%d%d",&p[i].lx,&p[i].ly,&p[i].rx,&p[i].ry);
        memset(q,0,sizeof(q));
        for(int i=1;i<=Q;i++){
            int q_n,x;
            scanf("%d",&q_n);
            while(q_n--){
                scanf("%d",&x);
                q[i]|=(1<<(x-1));
            }
        }
        R.lx=0,R.ly=0,R.rx=1010,R.ry=1010;
        dfs(R,0,0,0);
        printf("Case %d:\n",++cas);
        for(int i=1;i<=Q;i++){
            printf("Query %d: %d\n",i,ans[q[i]]);
        }
        printf("\n");
    }
    return 0;
}


