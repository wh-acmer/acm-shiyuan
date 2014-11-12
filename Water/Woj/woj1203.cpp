#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
map<int,int>m;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        m.clear();
        int x;
        int tnt=n/2+1;
        while(n--)
        {
            scanf("%d",&x);
            m[x]++;
        }
        map<int,int>::iterator it=m.begin();
        int ans;
        for(;it!=m.end();it++)
            if(it->second>=tnt)
                ans=it->first;
        printf("%d\n",ans);
    }
    return 0;
}
