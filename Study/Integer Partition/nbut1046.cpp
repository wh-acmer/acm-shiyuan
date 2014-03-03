#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
#include <queue>
using namespace std;
int a[60],n;
void dfs(int sum,int size,int mx){
    if(sum==n){
        for(int i=1;i<size;i++){
            printf("%d",a[i]);
            if(i+1==size) printf("\n");
            else printf(" ");
        }
        return ;
    }
    for(int i=mx;i+sum<=n;i++){
        a[size]=i;
        dfs(sum+i,size+1,i);
    }
}
int main(){
    while(scanf("%d",&n)!=EOF){
        memset(a,0,sizeof(a));
        dfs(0,1,1);
    }
    return 0;
}
