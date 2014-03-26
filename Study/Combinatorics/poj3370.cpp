#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
LL S;
struct node{
    int id,re;
}p[100005];
bool cmp(node a,node b){
    if(a.re==b.re) return a.id<b.id; return a.re<b.re;
}
int main(){
    int n,c,x;
    while(scanf("%d%d",&c,&n)!=EOF){
        if(c==0 && n==0) break;
        int index=-1; S=0;
        for(int i=0;i<n;i++){
            scanf("%d",&x);
            S+=x;
            p[i].id=i+1;
            p[i].re=S%c;
            if(index==-1 && p[i].re==0) index=i;
        }
        if(index!=-1){
            for(int i=0;i<index;i++) printf("%d ",i+1);
            printf("%d\n",index+1);
        }
        else{
            sort(p,p+n,cmp);
            int pnt;
            for(int i=0;i+1<n;i++){
                if(index==-1 && p[i].re==p[i+1].re){
                    index=p[i].id;
                    pnt=p[i+1].id;
                }
            }
            if(index==-1) printf("no sweets\n");
            else{
                for(int i=index+1;i<pnt;i++) printf("%d ",i);
                printf("%d\n",pnt);
            }
        }
    }
    return 0;
}
