// 24 Game
// http://codeforces.com/problemset/problem/468/A
// constructive algorithm

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        if(n<=3) printf("NO\n");
        else{
            printf("YES\n");
            if(n==4){
                printf("1 * 2 = 2\n");
                printf("3 * 4 = 12\n");
                printf("2 * 12 = 24\n");
            }
            else if(n==5){
                printf("1 + 2 = 3\n");
                printf("5 - 3 = 2\n");
                printf("2 * 3 = 6\n");
                printf("4 * 6 = 24\n");
            }
            else{
                if(n&1){
                    while(n>5){
                        printf("%d - %d = %d\n",n,n-1,1);
                        printf("%d * %d = %d\n",n-2,1,n-2);
                        n-=2;
                    }
                    printf("1 + 2 = 3\n");
                    printf("5 - 3 = 2\n");
                    printf("2 * 3 = 6\n");
                    printf("4 * 6 = 24\n");
                }
                else{
                    while(n>4){
                        printf("%d - %d = %d\n",n,n-1,1);
                        printf("%d * %d = %d\n",n-2,1,n-2);
                        n-=2;
                    }
                    printf("1 * 2 = 2\n");
                    printf("3 * 4 = 12\n");
                    printf("2 * 12 = 24\n");
                }
            }
        }
    }
    return 0;
}
