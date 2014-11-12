#include <cstdio>
#include <map>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;
int main()
{
    map<int,int>m1;
    map<int,int>m2;
    map<int,int>m;
    m1.clear();
    m2.clear();
    m.clear();
    stack<map<int,int>::iterator>s;
    while(!s.empty())
        s.pop();
    int a,b;
    while(scanf("%d%d",&a,&b)==2)
    {
        if(a==-1&&b==-1)
            break;
        m1[b]+=a;
    }
    while(scanf("%d%d",&a,&b)==2)
    {
        if(a==-1&&b==-1)
            break;
        m2[b]+=a;
    }
    map<int,int>::iterator ii=m1.begin(),jj=m2.begin();
    for(ii=m1.begin();ii!=m1.end();ii++)
    {
        for(jj=m2.begin();jj!=m2.end();jj++)
        {
            m[ii->first+jj->first]+=ii->second*jj->second;
        }
    }
    map<int,int>::iterator it=m.begin();
    int tag=1;
    for(it=m.begin();it!=m.end();it++)
    {
        if(it->second!=0)
            tag=0;
    }
    if(tag)
        printf("0");
    else
    {
        for(it=m.begin();it!=m.end();it++)
            if(it->second!=0)
                s.push(it);
        while(!s.empty())
        {
            printf("%d %d ",s.top()->second,s.top()->first);
            s.pop();
        }
    }
    printf("\n");
    return 0;
}
