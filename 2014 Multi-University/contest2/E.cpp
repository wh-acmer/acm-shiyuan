#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
using namespace std;
int a[21],c[7],b[7],vis[130];
int n,K,L,ans,id=1;
set<string>st[7];
set<string>::iterator it;
void pre(){
    for(int k=0;k<7;k++){
        st[k].clear();
        string s="012345";
        for(int i=0;i<k;i++)
            c[i]=i;
        do{
            string str="";
            for(int i=0;i<k;i++) str=str+(s[c[i]]);
            bool ok=false;
            for(int i=0;i<k;i++){
                string tmp="",smp="";
                for(int j=0;j<k;j++){
                    tmp=tmp+str[(i+j)%k];
                    smp=str[(i+j)%k]+smp;
                }
                if(st[k].count(tmp) || st[k].count(smp)){
                    ok=true;
                    break;
                }
            }
            if(!ok) st[k].insert(str);
        }while(next_permutation(c,c+k));
    }
}
void shit(){
    it=st[K].begin();
    for(;it!=st[K].end();it++){
        string s=*it;
        for(int i=0;i<K;i++){
            int now=0;
            for(int j=0;j<K;j++){
                if(i+j>=K)
                    now^=b[s[i+j-K]-'0'];
                else
                    now^=b[s[i+j]-'0'];
                vis[now]=id;
            }
        }
        for(int i=L;;i++){
            if(vis[i]==id)
                ans=max(ans,i);
            else break;
        }
        id++;
    }
}
void cal(){
    int total=(1<<K);
    bool ok=true;
    for(int i=0;i<total;i++){
        int tmp=i,cnt=0;
        for(int j=0;j<K;j++){
            if(tmp&1)
                cnt^=b[j];
            tmp>>=1;
        }
        vis[cnt]=id;
    }
    for(int i=L;i<=ans;i++){
        if(vis[i]!=id){
            ok=false;
            break;
        }
    }
    id++;
    if(ok){
        shit();
    }
}
void dfs(int now,int index){
    if(now==K){
        cal();
        return;
    }
    if(index==n) return ;
    b[now]=a[index];
    dfs(now+1,index+1);
    dfs(now,index+1);
}
void solve(){
    ans=-1;
    id=1;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    dfs(0,0);
}
int main(){
    pre();
    while(scanf("%d%d%d",&n,&K,&L)!=EOF){
        solve();
        if(ans==-1) ans=0;
        printf("%d\n",ans);
    }
    return 0;
}
