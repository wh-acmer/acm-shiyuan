#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int m,d;
        scanf("%d%d",&m,&d);
        if(m==10 && d==21) printf("It's today!!\n");
        else if(m>10 || (m==10 && d>21) ) printf("What a pity, it has passed!\n");
        else {
            int ans=0;
            while(m!=10 ||  d!=21){
                if(d==month[m]) d=1,m++;
                else d++;
                ans++;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
