#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
#define maxn 1010
int a[maxn][maxn];
int get(int x,int y,int i,int j){
    return a[i][j]-a[x-1][j]-a[i][y-1]+a[x-1][y-1];
}
bool ok(int i,int j,int mid){
    return get(i,j,i+mid,j+mid)==0;
}
int main(){
    int n,T,x,y;
    while(scanf("%d%d",&n,&T)!=EOF){
        memset(a,0,sizeof(a));
        for(int i=0;i<T;i++){
            scanf("%d%d",&x,&y);
            a[x][y]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                a[i][j]+=a[i][j-1];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                a[i][j]+=a[i-1][j];
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int l=0,r=min(n-j,n-i),mid,tmp=0;
                while(l<=r){
                    mid=(l+r)/2;
                    if(ok(i,j,mid)){
                        l=mid+1;
                        ans=max(ans,mid+1);
                    }
                    else{
                        r=mid-1;
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
