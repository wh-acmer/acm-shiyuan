// Purification
// http://codeforces.com/problemset/problem/329/A
// water

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <vector>
using namespace std;
#define N 110
char s[N][N];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%s",&s[i]);
        }
        int ok=0;
        for(int i=0;i<n;i++){
            bool now=true;
            for(int j=0;j<n;j++){
                if(s[i][j]=='.') now=false;
            }
            if(now) ok|=1;
            now=true;
            for(int j=0;j<n;j++){
                if(s[j][i]=='.') now=false;
            }
            if(now) ok|=2;
        }
        if(ok==3) printf("-1\n");
        else if(ok==2||ok==0){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(s[i][j]=='.'){
                        printf("%d %d\n",i+1,j+1);
                        break;
                    }
                }
            }
        }
        else if(ok==1){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(s[j][i]=='.'){
                        printf("%d %d\n",j+1,i+1);
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
