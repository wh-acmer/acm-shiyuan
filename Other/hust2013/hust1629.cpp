/*
    ���⣺n*m�����̣����ٴ���ȡ���������ӣ�ʣ�µĲ����γ��������������б�ţ�������
    ˼·������ҹ��ɷ��ִ���(n*m)/5
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
