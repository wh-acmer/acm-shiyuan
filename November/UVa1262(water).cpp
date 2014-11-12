// Password
// http://uva.onlinejudge.org/external/12/1262.pdf
// math ×ÖµäÐòÂÒ¸ã

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
set<char>s[5];
char a[6][5],b[6][5];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<6;i++){
            scanf("%s",&a[i]);
        }
        for(int i=0;i<6;i++){
            scanf("%s",&b[i]);
        }
        for(int i=0;i<5;i++){
            s[i].clear();
            for(int j=0;j<6;j++){
                for(int k=0;k<6;k++){
                    if(a[j][i]==b[k][i]){
                        s[i].insert(a[j][i]);
                    }
                }
            }
        }
        int all=1;
        for(int i=0;i<5;i++){
            all*=s[i].size();
        }
        if(n>all){
            printf("NO\n");
        }
        else{
            n--;
            for(int i=0;i<5;i++){
                all/=s[i].size();
                int count=n/all;
                set<char>::iterator it=s[i].begin();
                while(count--){
                    it++;
                }
                printf("%c",*it);
                n-=n/all*all;
            }
            printf("\n");
        }
    }
    return 0;
}
