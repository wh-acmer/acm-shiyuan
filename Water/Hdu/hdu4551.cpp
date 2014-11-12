#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <stack>
using namespace std;
bool is_leap(int n)
{
    if(n%4==0)
    {
        if(n%100==0)
        {
            if(n%400==0)
                return 1;
            return 0;
        }
        return 1;
    }
    return 0;
}
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int lcm(int a,int b)
{
    return a/gcd(a,b)*b;
}
int month[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int num[11];
int main()
{
    int t;
    scanf("%d",&t);
    for(int cases=1;cases<=t;cases++)
    {
        int m,d,y;
        memset(num,0,sizeof(num));
        scanf("%d%d%d",&m,&d,&y);
        if(is_leap(y))
            month[2]=29;
        else
            month[2]=28;
        printf("Case #%d: ",cases);
        stack<int>s1,s2;
        while(!s1.empty())
            s1.pop();
        while(!s2.empty())
            s2.pop();
        for(int i=1;i<=12;i++)
        {
            int mon=i;
            int day=m*d/i;
            if(gcd(mon,day)!=m||lcm(mon,day)!=d)
                continue;
            else
            {
                if(mon>=1&&mon<=12)
                {
                    if(day>=1&&day<=month[mon])
                    {
                        s1.push(mon);
                        s2.push(day);
                    }
                }
            }
        }
        if(s1.empty())
            printf("-1\n");
        else if(s1.size()==1)
        {
            printf("%d/%02d/%02d\n",y,s1.top(),s2.top());
        }
        else
            printf("1\n");
    }
    return 0;
}
