#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
#define maxn 100
int k[3],kind[maxn],l;
char s[maxn];
char str[4][maxn],l1,l2,l3;
int main(){
    while(scanf("%d%d%d",&k[0],&k[1],&k[2])!=EOF){
        if(k[0]+k[1]+k[2]==0) break;
        scanf("%s",&s);
        l=strlen(s);
        l1=0,l2=0,l3=0;
        for(int i=0;i<l;i++){
            if(s[i]>='a' && s[i]<='i') str[0][l1++]=s[i],kind[i]=0;
            else if(s[i]>='j' && s[i]<='r') str[1][l2++]=s[i],kind[i]=1;
            else str[2][l3++]=s[i],kind[i]=2;
        }
        if(l1) k[0]%=l1;
        if(l2) k[1]%=l2;
        if(l3) k[2]%=l3;
        for(int i=0;i<l1;i++) str[3][(i+k[0])%l1]=str[0][i];
        strcpy(str[0],str[3]);
        for(int i=0;i<l2;i++) str[3][(i+k[1])%l2]=str[1][i];
        strcpy(str[1],str[3]);
        for(int i=0;i<l3;i++) str[3][(i+k[2])%l3]=str[2][i];
        strcpy(str[2],str[3]);
        l1=0,l2=0,l3=0;
        for(int i=0;i<l;i++){
            if(kind[i]==0) printf("%c",str[0][l1++]);
            else if(kind[i]==1) printf("%c",str[1][l2++]);
            else  printf("%c",str[2][l3++]);
        }
        printf("\n");
    }
    return 0;
}
