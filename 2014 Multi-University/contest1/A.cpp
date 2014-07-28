#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF){
        if((n/(k-1))&1) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
