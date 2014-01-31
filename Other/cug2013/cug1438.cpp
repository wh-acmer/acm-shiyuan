/*
    water

*/
#include <stdio.h>
typedef long long LL;
LL gcd(LL a,LL b){
    if(b==0) return a;
    return gcd(b,a%b);
}
LL lcm(LL a,LL b){
    return a/gcd(a,b)*b;
}
int main(){
    int n,m,x;
    while(scanf("%d%d",&n,&m)!=EOF){
        long long ans=1;
        int p=0;
        for(int i=0;i<n;i++) {
            scanf("%d",&x);
            if(m%x==0) p++,ans=lcm(ans,x);
        }
        if(ans!=m) printf("0\n");
        else printf("%d\n",p);
    }
    return 0;
}
