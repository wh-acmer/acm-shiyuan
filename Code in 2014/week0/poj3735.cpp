#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
using namespace std;
typedef long long LL;
struct Matrix{
    LL m[110][110];
}E,D;
char op[10];
LL n;
void init(){
    memset(E.m,0,sizeof(E.m));
    for(int i=1;i<110;i++) E.m[i][i]=1;
}
Matrix multi(Matrix A,Matrix B){
    Matrix ans; memset(ans.m,0,sizeof(ans.m));
    for(int i=1;i<=n;i++)
        for(int k=1;k<=n;k++){
            if(A.m[i][k]==0) continue;
            for(int j=1;j<=n;j++)
                ans.m[i][j]+=A.m[i][k]*B.m[k][j];
        }
    return ans;
}
Matrix Pow(Matrix A,LL k){
    Matrix ans=E;
    while(k){
        if(k&1) k--,ans=multi(ans,A);
        else k>>=1,A=multi(A,A);
    }
    return ans;
}
int main(){
    LL m,k,x,y; init();
    while(scanf("%lld%lld%lld",&n,&m,&k)!=EOF){
        if(n==m && m==k && k==0) break;
        n++; Matrix ans=E;
        for(int o=0;o<k;o++){
            scanf("%s",&op);
            Matrix tmp=E;
            if(op[0]=='g') scanf("%lld",&x),tmp.m[x][n]=1;
            else if(op[0]=='e') scanf("%lld",&x),tmp.m[x][x]=0;
            else if(op[0]=='s'){
                scanf("%lld%lld",&x,&y);
                tmp.m[x][x]=0,tmp.m[x][y]=1;
                tmp.m[y][y]=0,tmp.m[y][x]=1;
            }
            ans=multi(tmp,ans);
        }
        Matrix cnt; memset(cnt.m,0,sizeof(cnt.m));
        cnt.m[n][1]=1;
        ans=multi(Pow(ans,m),cnt);
        for(int i=1;i<=n-1;i++){
            printf("%lld",ans.m[i][1]);
            if(i==n-1) printf("\n");
            else printf(" ");
        }
    }
    return 0;
}
