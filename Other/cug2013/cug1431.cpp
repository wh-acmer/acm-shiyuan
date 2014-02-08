#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define maxn 100005
int a[maxn],b[maxn],n;
int get(int *p){
    int sum=0,tmp=0;
    for(int i=1;i<=n;i++){
        tmp+=p[i];
        sum=max(sum,tmp);
        if(tmp<0) tmp=0;
    }
    return sum;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int sum=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=-a[i],sum+=a[i];
        printf("%d\n",max(get(a),sum+get(b)));
    }
    return 0;
}
