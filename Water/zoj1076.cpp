/*
    water 贪心
    排尽量多，按结束时间排序即可
*/
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
#define maxn 1001
struct node{
    int id,st,ed;
}p[maxn];
bool cmp(node a,node b){
    return a.ed<=b.ed;
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        if(n==0) return 0;
        for(int i=0;i<n;i++){
            scanf("%d%d",&p[i].st,&p[i].ed);
            p[i].id=i+1;
        }
        if(n==1){
            printf("1\n");
            continue;
        }
        sort(p,p+n,cmp);
        int now=p[0].ed;
        printf("%d",p[0].id);
        for(int i=1;i<n;i++){
            if(p[i].st>=now){
                printf(" %d",p[i].id);
                now=p[i].ed;
            }
        }
        printf("\n");
    }
    return 0;
}
