#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
typedef long long LL;
#define N 10
int p[2*N+1],q[2*N+1],r[N+1],n,K;
LL ans;
void dfs(int c,int now){
    if(now==K){
        ans++;
        return ;
    }
    if(c>n){
        return ;
    }
    for(int i=1;i<=n;i++){
        if(r[i]==0 && p[n-(i-c)]==0 && q[i+c]==0){
            r[i]=1;
            p[n-(i-c)]=1;
            q[i+c]=1;
            dfs(c+1,now+1);
            r[i]=0;
            p[n-(i-c)]=0;
            q[i+c]=0;
        }
    }
    dfs(c+1,now);
}
int main(){
    while(scanf("%d%d",&n,&K)!=EOF){
        if(n<K) printf("0\n");
        else{
            memset(p,0,sizeof p);
            memset(q,0,sizeof q);
            memset(r,0,sizeof r);
            ans=0;
            dfs(1,0);
            printf("%lld\n",ans);
        }
    }
    return 0;
}

/*
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int n,K,full,ans;
void dfs(int row,int p,int q,int now,int r){
    if(now==K){
        ans++;
        return ;
    }
    if(r>n){
        return ;
    }
    int lowbit=((1<<n)-1) & (~(row|p|q));
    while(lowbit){
        int low=lowbit&(-lowbit);
        lowbit-=low;
        dfs(row+low,(p+low)<<1,(q+low)>>1,now+1,r+1);
    }
    dfs(row,p<<1,q>>1,now,r+1);
}
int main(){
    while(scanf("%d%d",&n,&K)!=EOF){
        if(n<K){
            printf("0\n");
            continue;
        }
        ans=0;
        dfs(0,0,0,0,1);
        printf("%d\n",ans);
    }
    return 0;
}

*/
