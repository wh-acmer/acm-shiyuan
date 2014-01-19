/*
    题意：n*m的棋盘，至少从中取出多少棋子，剩下的不会形成五个（横着竖着斜着）连续的
    思路：打表找规律发现答案是(n*m)/5
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",x*y/5);
    }
    return 0;
}
