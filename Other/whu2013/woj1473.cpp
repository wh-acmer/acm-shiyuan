/*
    乱搞

    随机越多 死得越快

*/
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>
#include <stack>
using namespace std;
string a[310];
double xx[10];
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<10;i++)
        xx[i]=i;
    for(int cases=1;cases<=t;cases++)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            cin>>a[i];
        int tag=0;
        for(int ii=0;ii<10;ii++)
        {
            double x=xx[ii];
            stack<double>s;
            while(!s.empty())
                s.pop();
            for(int i=1;i<=n;i++)
            {
                if(a[i]=="x")
                    s.push(x);
                else if(a[i]=="sin")
                {
                    double tmp=s.top();
                    s.pop();
                    tmp=sin(tmp);
                    s.push(tmp);
                }
                else if(a[i]=="cos")
                {
                    double tmp=s.top();
                    s.pop();
                    tmp=cos(tmp);
                    s.push(tmp);
                }
                else if(a[i]=="tan")
                {
                    double tmp=s.top();
                    s.pop();
                    tmp=tan(tmp);
                    s.push(tmp);
                }
                else if(a[i]=="+")
                {
                    double tmp=s.top();
                    s.pop();
                    tmp+=s.top();
                    s.pop();
                    s.push(tmp);
                }
                else if(a[i]=="*")
                {
                    double tmp=s.top();
                    s.pop();
                    tmp*=s.top();
                    s.pop();
                    s.push(tmp);
                }
                else if(a[i]=="-")
                {
                    double tmp=-s.top();
                    s.pop();
                    tmp+=s.top();
                    s.pop();
                    s.push(tmp);
                }
            }
            if(s.size()==1&&fabs(s.top())<1e-6)
                tag++;
        }
        printf("Case %d: ",cases);
        if(tag==10)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
