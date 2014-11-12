#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <stack>
using namespace std;
map<int,int>m1,m2;
stack<map<int,int>::iterator>s1;
stack<map<int,int>::iterator>s2;
int a[11],b[11];
int gcd(int a,int b)
{
    if(a<0)
        a*=(-1);
    if(b<0)
        b*=(-1);
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        m1.clear();
        m2.clear();
        while(!s1.empty())
            s1.pop();
        while(!s2.empty())
            s2.pop();
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
            scanf("%d",&b[i]);
        for(int i=1;i<=n;i++)
        {
            m1[b[i]]+=a[i];
            m2[b[i]]=1;
        }
        map<int,int>::iterator it=m1.begin(),is=m2.begin();
        for(;it!=m1.end();it++,is++)
        {
            int tmp=gcd(it->first+1,it->second);
            it->second/=tmp;
            is->second*=(it->first+1)/tmp;
            s1.push(it);
            s2.push(is);
        }
        int tag=1;
        while(!s1.empty())
        {
            int tmp=s1.top()->first;
            int cnt=s1.top()->second;
            int tnt=s2.top()->second;
            s1.pop();
            s2.pop();
            if(cnt==0)
                continue;
            if(tag)
            {
                tag=0;
            }
            else
            {
                if(cnt*tnt>0)
                    printf("+");
            }
            if(tnt==1)
            {
                if(cnt==1);
                else if(cnt==-1)
                    printf("-");
                else
                    printf("%d",cnt);
            }
            else
                printf("%d/%d",cnt,tnt);
            printf("x");
            if(tmp==0);
            else
                printf("^%d",tmp+1);
        }
        printf("\n");
    }
    return 0;
}
