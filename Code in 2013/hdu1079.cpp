/*
    game

���ڴ󲿷ֵ�date�����������2��29�ţ�������Ҫ�ﵽ��״̬�� 11.4��
�� month+day ��ż̬������11.3����10.4��ʱ���Ǳ�ʤ״̬��
��Ȼ�������Ļ�������������day++,����month++,���ı���ż�󣬺�����Ȼ���ԸĻ�ȥ��
ֱ����󵽴� 11.4 ����̬����
ΨһҪ���ǵ����������month++֮�����첻���ڵģ�����1.31�����Ǻ���ֻ����2.1����̬�������԰� 1.31����ż̬��
�Լ�������9.30�ı任ֻ����10.1�����������ż̬֮����ż̬������Ϊ������9.31����
ϸ��һ�£�month++���������ڵ��º���Ϊ��̬���У�1.31  3.31  5.31  7.31
��������8.1 ���� 8.31����ѡ�񣬵���������������̬��
month++�󣬺�������ѡ��Ϊ��̬���У� 4.30  6.30  9.30  11.30
*/

#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int t,y,m,d,tmp;
    bool tag;
    scanf("%d",&t);
    while(t--)
    {
        tag=false;;
        scanf("%d%d%d",&y,&m,&d);
        tmp=m+d;
        if(y==2001 && m==11 && d==4)
            tag=false;
        else if((m==1||m==3||m==5||m==7)&&d==31) // 8.31 10.31 �� 12.31 ��������
            tag=true;
        else if((m==4||m==6||m==9||m==11)&&d==30) //������ѡ��Ϊ��̬
            tag=true;
        // ����2.28�Ĳ����ǲ������꣬����������3.28Ϊ��̬
        else if(tmp%2==0)
            tag=true;
        if(tag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}