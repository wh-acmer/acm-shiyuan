#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
using namespace std;
#define maxn 310
struct point{
    int x,y;
}pnt[maxn],res[maxn];
int cost[maxn][maxn],dp[maxn][maxn];
int n,p;
bool multi(point sp,point ep,point op){
    return (sp.x-op.x)*(ep.y-op.y)>=(ep.x-op.x)*(sp.y-op.y);
}
bool operator <(const point &l,const point &r){
    return l.y<r.y || (l.y==r.y && l.x<r.x);
}
int graham(int n){
    int i,len,k=0,top=1;
    sort(pnt,pnt+n);
    if(n==0) return 0; res[0]=pnt[0];
    if(n==1) return 1; res[1]=pnt[1];
    if(n==2) return 2; res[2]=pnt[2];
    for(i=2;i<n;i++){
        while(top && multi(pnt[i],res[top],res[top-1])){
            top--;
        }
        res[++top]=pnt[i];
    }
    len=top;
    res[++top]=pnt[n-2];
    for(i=n-3;i>=0;i--){
        while(top!=len && multi(pnt[i],res[top],res[top-1])){
            top--;
        }
        res[++top]=pnt[i];
    }
    return top;
}
int cal(point a,point b){
    return (abs(a.x+b.x)*abs(a.y+b.y))%p;
}
int main(){
    while(scanf("%d%d",&n,&p)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d%d",&pnt[i].x,&pnt[i].y);
        }
        int po=graham(n);
        if(po!=n){
            printf("I can't cut.\n");
        }
        else{
            memset(cost,0,sizeof(cost));
            for(int i=0;i<n;i++){
                for(int j=i+2;j<n;j++){
                    cost[i][j]=cost[j][i]=cal(res[i],res[j]);
                }
            }
            memset(dp,0x3f,sizeof(dp));
            for(int i=0;i<n;i++){
                dp[i][(i+1)%n]=dp[i][i]=0;
            }
            for(int i=n-3;i>=0;i--){
                for(int j=i+2;j<n;j++){
                    for(int k=i;k<=j;k++){
                        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+cost[i][k]+cost[k][j]);
                    }
                }
            }
            printf("%d\n",dp[0][n-1]);
        }
    }
    return 0;
}
