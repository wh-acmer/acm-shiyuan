#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
int a[1025];
int main(){
    int T; scanf("%d",&T);
    while(T--){
        int n,k; scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        while(k--) next_permutation(a+1,a+n+1);
        for(int i=1;i<n;i++) printf("%d ",a[i]);
        printf("%d\n",a[n]);
    }
    return 0;
}
