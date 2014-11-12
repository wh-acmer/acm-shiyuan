// Drinks
// http://codeforces.com/problemset/problem/200/B
// water

#include <cstdio>
#include <iostream>
using namespace std;
int main(){
    int n,x;
    while(scanf("%d",&n)!=EOF){
        int count=0;
        for(int i=0;i<n;i++){
            scanf("%d",&x);
            count+=x;
        }
        printf("%.10lf\n",count*1.0/n);
    }
    return 0;
}
