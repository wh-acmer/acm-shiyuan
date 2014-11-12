// Add bricks in the wall
// http://acm.hust.edu.cn/vjudge/problem/viewProblem.action?id=37594
// water

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
int a[10][10];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        for(int i=1;i<=9;i+=2){
            for(int j=1;j<=i;j+=2){
                scanf("%d",&a[i][j]);
            }
        }
        for(int i=9;i>=1;i--){
            if(i&1){
                for(int j=1;j<=i;j++){
                    if(!(j&1)){
                        a[i][j]=(a[i-2][j-1]-a[i][j-1]-a[i][j+1])/2;
                    }
                }
            }
            else{
                for(int j=1;j<=i;j++){
                    a[i][j]=a[i+1][j]+a[i+1][j+1];
                }
            }
        }
        for(int i=1;i<=9;i++){
            for(int j=1;j<=i;j++){
                printf("%d",a[i][j]);
                if(j==i) printf("\n");
                else printf(" ");
            }
        }
    }
    return 0;
}
