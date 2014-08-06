#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
#define maxn 1000010
char s[maxn];
int a[maxn][2],b[maxn][2];
int main(){
    while(scanf("%s",s+1)!=EOF){
        int len=strlen(s+1);
        if(len&1){
            printf("None\n");
            continue;
        }
        a[0][0]=a[0][1]=0;
        int none=0;
        for(int i=1;i<=len;i++){
            if(s[i]=='('){
                a[i][0]=a[i-1][0]+1;
                a[i][1]=a[i-1][1]+1;
            }
            else if(s[i]==')'){
                if(a[i-1][0]==0)a[i][0]=1;
                else a[i][0]=a[i-1][0]-1;
                a[i][1]=a[i-1][1]-1;
            }
            else if(s[i]=='?'){
                if(a[i-1][0]==0)a[i][0]=1;
                else a[i][0]=a[i-1][0]-1;
                a[i][1]=a[i-1][1]+1;
            }
            if(a[i][0]>a[i][1]){
                none=1;
            }
        }
        b[len][0]=b[len][1]=0;
        for(int i=len;i>=1;i--){
            if(s[i]==')'){
                b[i-1][0]=b[i][0]+1;
                b[i-1][1]=b[i][1]+1;
            }
            else if(s[i]=='(')
            {
                if(b[i][0]==0)b[i-1][0]=1;
                else b[i-1][0]=b[i][0]-1;
                b[i-1][1]=b[i][1]-1;
            }
            else if(s[i]=='?')
            {
                if(b[i][0]==0)b[i-1][0]=1;
                else b[i-1][0]=b[i][0]-1;
                b[i-1][1]=b[i][1]+1;
            }
            if(b[i][0]>b[i][1])none=1;
        }
        int many=0;
        for(int i=1;i<=len;i++){
            if(max(a[i][0],b[i][0])<min(a[i][1],b[i][1])){
                many=1;
            }
            else if(max(a[i][0],b[i][0])>min(a[i][1],b[i][1])){
                none=1;
            }
        }
        if(none){
            printf("None\n");
            continue;
        }
        if(many){
            printf("Many\n");
            continue;
        }
        printf("Unique\n");
    }
    return 0;
}
