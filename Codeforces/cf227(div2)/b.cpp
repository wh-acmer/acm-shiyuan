#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
#define maxn 3010
int a[maxn],b[maxn];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        for(int i=0;i<m;i++) scanf("%d",&b[i]);
        sort(a,a+n,cmp);
        sort(b,b+m,cmp);
        int index=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(index<m && a[i]<=b[index]){
                index++;
            }
            else ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
