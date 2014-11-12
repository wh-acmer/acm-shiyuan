//  Levko and Permutation
// http://codeforces.com/problemset/problem/361/B
// constructive algorithm

// 注意到n和n-1一定互质，移动一下序列就行

#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define N 100010
int a[N];
int main(){
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF){
        if(n==k){
            printf("-1\n");
            continue;
        }
        if(k==n-1){
            for(int i=1;i<=n;i++) printf("%d ",i);
            printf("\n");
            continue;
        }
        for(int i=1;i<=k+1;i++){
            a[i]=i;
        }
        a[k+2]=1;
        k=k+3;
        while(k<=n){
            a[k]=k-1;
            k++;
        }
        a[1]=n;
        for(int i=1;i<=n;i++){
            printf("%d ",a[i]);
        }
        printf("\n");
    }
}
