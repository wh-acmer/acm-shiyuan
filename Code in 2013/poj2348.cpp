/*
    game

����a<=b,���b%a==0,����ʤ��
���b>2*a,��ô���ֻ����������ֲ�����Ӧ�ԣ�ֱ��a<b<2*a
���ʱ����û��ѡ�����صģ�Ҳ����Ҫģ��һ����ż��
Ȼ��ع�ͷ���ж�b>2*aʱӦ��ѡ�����ֲ��ԡ�
��ʵ�ǣ�������b>2*a�ľ���ʱ����ǰ��һ�����ڼ�ȥĳһ����������һ�ֱذܵľ��ƣ�
���Եݹ�дһ������������ʱ�˳���
*/

#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
bool win;
void solve(int a,int b)
{
    if(a>b)
        swap(a,b);
    if(b%a==0 || b/a>1)
        return ;
    win=!win;
    b=b%a;
    solve(a,b);
}
int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b),a+b)
    {
        win=1;
        solve(a,b);
        if(win)
            printf("Stan wins\n");
        else
            printf("Ollie wins\n");
    }
    return 0;
}
