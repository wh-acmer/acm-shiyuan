// Team
// http://codeforces.com/problemset/problem/401/C
// construct water

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        if(m>=n-1 && m<=2*(n+1)){
            if(m==n-1){
                printf("0");
                for(int i=0;i<m;i++) printf("10");
                printf("\n");
            }
            else if(n==m){
                for(int i=0;i<n;i++) printf("10");
                printf("\n");
            }
            else{
                int re=m-(n+1);
                for(int i=0;i<n;i++){
                    if(re){
                        printf("1");
                        re--;
                    }
                    printf("10");
                }
                if(re) printf("1");
                printf("1\n");
            }
        }
        else{
            printf("-1\n");
        }
    }
    return 0;
}
