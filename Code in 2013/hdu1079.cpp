/*
    game

对于大部分的date，包括闰年的2月29号，（最终要达到的状态是 11.4）
当 month+day 是偶态（例如11.3或者10.4）时，是必胜状态，
不然是奇数的话，不管先手是day++,还是month++,他改变奇偶后，后手仍然可以改回去，
直到最后到达 11.4 （奇态）。
唯一要考虑的特殊情况，month++之后那天不存在的（例如1.31，但是后续只能是2.1（奇态），可以把 1.31当作偶态）
以及（比如9.30的变换只能是10.1（特殊情况，偶态之后还是偶态），因为不存在9.31）。
细分一下，month++后续不存在导致后续为奇态的有：1.31  3.31  5.31  7.31
（后续是8.1 或者 8.31可以选择，但两个后续均是奇态）
month++后，后续可以选择为奇态的有： 4.30  6.30  9.30  11.30
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
        else if((m==1||m==3||m==5||m==7)&&d==31) // 8.31 10.31 和 12.31 果断抛弃
            tag=true;
        else if((m==4||m==6||m==9||m==11)&&d==30) //后续可选择为奇态
            tag=true;
        // 对于2.28的不管是不是闰年，后续可以是3.28为奇态
        else if(tmp%2==0)
            tag=true;
        if(tag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
