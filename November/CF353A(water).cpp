// Domino
// http://codeforces.com/problemset/problem/353/A
// water

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n,x,y;
    while(scanf("%d",&n)!=EOF){
        int count1=0,count2=0;
        int xx=0,yy=0;
        while(n--){
            scanf("%d%d",&x,&y);
            if(x%2==0 && y%2==0) ;
            else if(x%2==0 && y%2){
                count2++;
                yy++;
            }
            else if(x%2 && y%2==0){
                count1++;
                xx++;
            }
            else{
                xx++;
                yy++;
            }
        }
        if((xx&1) && (yy&1)){
            if(count1|count2){
                printf("1\n");
            }
            else{
                printf("-1\n");
            }
        }
        else if((xx&1) && !(yy&1)){
            printf("-1\n");
        }
        else if(!(xx&1) && (yy&1)){
            printf("-1\n");
        }
        else{
            printf("0\n");
        }
    }
    return 0;
}
