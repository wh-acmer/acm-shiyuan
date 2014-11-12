// Levko and Table
// http://codeforces.com/problemset/problem/361/A
// construct + water

#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define N 110
int a[N];
int main(){
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF){
        for(int i=1;i<=n-1;i++) a[i-1]=1;
        a[n-1]=k-(n-1);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                printf("%d ",a[(i+j)%n]);
            }
            printf("\n");
        }
    }
    return 0;
}
