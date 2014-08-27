#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
    int n,m,x,y;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=0;i<(1<<n);i++){
            x=(i^(i>>1))<<m;
            for(int j=0;j<(1<<m);j++){
                y=x|(j^(j>>1));
                printf("%d",y);
                if(j+1==(1<<m)) printf("\n");
                else printf(" ");
            }
        }
    }
    return 0;
}
