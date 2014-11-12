// Dreamoon and Stairs
// http://codeforces.com/problemset/problem/476/A
// water

#include <cstdio>
#include <iostream>
using namespace std;
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        int y=((n+2*m-1)/(2*m))*(2*m);
        int x=y-n;
        y=(n-x)/2;
        if(x<0||y<0) printf("-1\n");
        else printf("%d\n",x+y);
    }
    return 0;
}
