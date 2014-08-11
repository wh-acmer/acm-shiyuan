#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
#define maxn 110
int a[maxn][maxn];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m;
        memset(a,0,sizeof(a));
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i&1){
                    if(j&1) a[i][j]=1;
                    else a[i][j]=-1;
                }
                else{
                    if(j&1) a[i][j]=-1;
                    else a[i][j]=1;
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i][j]==1){
                    int now=1;
                    for(int k=0;k<4;k++){
                        if(a[i+dx[k]][j+dy[k]]==-1){
                            now*=2;
                        }
                    }
                    ans+=now;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
