#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;
#define maxn 105
char a[maxn][maxn];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++) scanf("%s",a[i]+1);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(a[i][j]=='#' && (i-1>=1 &&a[i-1][j]=='#') && (i+1<=n && a[i+1][j]=='#') &&
                   (j-1>=1 && a[i][j-1]=='#') && (j+1<=n && a[i][j+1]=='#') ) {
                   a[i][j]='.';
                   a[i+1][j]='.';
                   a[i-1][j]='.';
                   a[i][j+1]='.';
                   a[i][j-1]='.';
                   }
            }
        }
        bool ok=true;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                if(a[i][j]=='#'){
                    ok=false;
                    break;
                }
        }
        if(ok) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
