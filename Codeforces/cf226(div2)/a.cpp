#include <stdio.h>
#define maxn 110
int a[maxn];
int main(){
    int n,c;
    while(scanf("%d%d",&n,&c)!=EOF){
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        int ans=0;
        for(int i=0;i+1<n;i++){
            if(ans<a[i]-a[i+1]-c) ans=a[i]-a[i+1]-c;
        }
        printf("%d\n",ans);
    }
    return 0;
}
