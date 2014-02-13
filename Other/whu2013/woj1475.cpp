/*
    water
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
char s[1010];
int main(){
    int T,m,n,cas=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d\n",&n,&m);
        for(int i=0;i<n;i++) gets(s);
        for(int i=0;i<m;i++) gets(s);
        printf("Case %d: %.6lf\n",++cas,pow(1.0/n,m));
    }
    return 0;
}
