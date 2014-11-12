// Mock Turtles
// http://blog.sina.com.cn/s/blog_8f06da99010125ol.html
// http://blog.csdn.net/acm_cxlove/article/details/7854181

#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;
set<long long>s;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        s.clear();
        long long ans=0;
        long long x;
        for(int i=0;i<n;i++)
        {
            scanf("%I64d",&x);
            s.insert(x);
        }
        set<long long>::iterator it=s.begin();
        for(;it!=s.end();it++)
        {
            if(__builtin_popcount(2* *it)&1)
                ans^=2* *it;
            else
                ans^=2* *it+1;
        }
        if(ans)
            printf("No\n");
        else
            printf("Yes\n");
    }
}
