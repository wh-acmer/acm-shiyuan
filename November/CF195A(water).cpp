// Let's Watch Football
// http://codeforces.com/problemset/problem/195/A
// water

#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
    int a,b,c;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF){
        int ans=(a*c+b-1)/b-c;
        printf("%d\n",ans);
    }
    return 0;
}
