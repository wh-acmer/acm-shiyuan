/*
    题意：一个8*8的棋盘，两个棋子K同时走，可以走到"." "#" ，问能否在"."相遇
    思路：其实可以先固定一个棋子，看另外一个能否走偶数步过来，偶数步就意味着，两棋子的横纵坐标之差能够被4整除
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
char s[8][8];
vector<int>d;
int main(){
    int n;
    int st=0;
    scanf("%d",&n);
    while(n--){
        d.clear();
        if(st==0)   st++;
        else getchar();
        for(int i=0;i<8;i++){
            scanf("%s",&s[i]);
        }
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(s[i][j]=='K'){
                    d.push_back(i);
                    d.push_back(j);
                }
            }
        }
        if((d[0]-d[2])%4==0 && (d[1]-d[3])%4==0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
