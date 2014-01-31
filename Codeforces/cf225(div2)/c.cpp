#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n,x;
    __int64 ans,tmp;
    while(scanf("%d",&n)!=EOF){
        ans=0,tmp=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&x);
            if(x) tmp++;
            else ans+=tmp;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
