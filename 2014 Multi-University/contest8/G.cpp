// C++
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <bitset>
#include <vector>
using namespace std;
#define N 510
int a[N][N],b[N],c[N];
bitset<N>s;
int main(){
    int n,cas=0,x;
    while(scanf("%d",&n)!=EOF){
        if(n==0) break;
        memset(c,0,sizeof c);
        int zero=0,mx=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d%d",&a[i][j],&x);
                c[a[i][j]]++;
            }
        }
        for(int i=0;i<n;i++){
            if(c[i]>mx){
                mx=c[i];
                zero=i;
            }
        }
        for(int i=0;i<n;i++){
            s.reset();
            for(int j=0;j<n;j++){
                s.set(a[i][j]);
            }
            if(s.count()==1 && i==zero) ;
            else  b[s.count()]=i;
        }
        b[0]=zero;
        printf("Case #%d:",++cas);
        for(int i=0;i<n;i++){
            printf(" %d",b[i]);
        }
        printf("\n");
    }
    return 0;
}
