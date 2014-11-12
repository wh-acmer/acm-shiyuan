#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int x;
    stack<int>s1;
    stack<int>s2;
    stack<int>s3;
    while(!s1.empty())
        s1.pop();
    while(!s2.empty())
        s2.pop();
    while(!s3.empty())
        s3.pop();
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        if(x>0)
            s1.push(x);
        if(x<0)
            s2.push(x);
        if(x==0)
            s3.push(x);
    }
    if(s1.empty()&&!s2.empty())
    {
        x=s2.top();
        s1.push(x);
        s2.pop();
        x=s2.top();
        s1.push(x);
        s2.pop();
    }
    if(s2.size()%2==0)
    {
        x=s2.top();
        s2.pop();
        s3.push(x);
    }
    printf("%d ",s2.size());
    while(s2.size()!=1)
    {
        printf("%d ",s2.top());
        s2.pop();
    }
    printf("%d\n",s2.top());
    printf("%d ",s1.size());
    while(s1.size()!=1)
    {
        printf("%d ",s1.top());
        s1.pop();
    }
    printf("%d\n",s1.top());
    printf("%d ",s3.size());
    while(s3.size()!=1)
    {
        printf("%d ",s3.top());
        s3.pop();
    }
    printf("%d\n",s3.top());
    return 0;
}
