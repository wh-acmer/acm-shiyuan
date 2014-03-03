#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
int dfs(int n,int m){ //表示n的拆分中最大堆为m
    if(m==1) return 1;
    if(n==0) return 1;
    if(m>n) return dfs(n,n);
    else return dfs(n-m,m)+dfs(n,m-1);
    return 0;
}
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n,m; scanf("%d%d",&n,&m);
        printf("%d\n",dfs(n,m));
    }
    return 0;
}
