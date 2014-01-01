#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int main(){
    int T;
    scanf("%d",&T);
    int n,m;
    while(T--){
        scanf("%d%d",&n,&m);
        if(n==1)    printf("%d\n",m);
        else if(m==1) printf("%d\n",n);
        else{
            int ans=m-1;
            m--,n--;
            int g=gcd(m,n);
            m/=g;
            n/=g;
            ans/=m;
            printf("%d\n",++ans);
        }
    }
    return 0;
}
