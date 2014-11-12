// ASCII Area
// http://uva.onlinejudge.org/external/16/1641.pdf
// water

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long LL;
#define N 110
char s[N];
int main(){
    int row,col;
    while(scanf("%d%d",&row,&col)!=EOF){
        int ans=0;
        for(int i=0;i<row;i++){
            scanf("%s",&s);
            int count=0;
            for(int j=0;j<col;j++){
                if(s[j]=='/' || s[j]=='\\'){
                    count++;
                    ans++;
                }
                else{
                    if(count&1){
                        ans+=2;
                    }
                }
            }
        }
        printf("%d\n",ans/2);
    }
    return 0;
}
