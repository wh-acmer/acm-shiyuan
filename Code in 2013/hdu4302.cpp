/*
    Ä£Äâ
*/
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <cstdio>
using namespace std;
map<int,int>m;
map<int,int>::iterator it,ii,jj;
int ca=0;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int l,n,op,x=0,y;
        scanf("%d%d",&l,&n);
        m.clear();
        long long ans=0;
        int tag=1;
        while(n--)
        {
            scanf("%d",&op);
            if(op==0)
            {
                scanf("%d",&y);
                m[y]++;
            }
            else
            {
                if(m.size()==0)
                    continue;
                it=m.find(x);
                if(it!=m.end())
                {
                    it->second--;
                    if(it->second<=0)
                        m.erase(it);
                    continue;
                }
                m[x]++;
                it=m.find(x);
                ii=it;
                jj=it;
                ii--;
                jj++;
                if(it==m.begin())
                {
                    tag=1;
                    ans+=jj->first-x;
                    it->second--;
                    if(it->second<=0)
                        m.erase(it);
                    x=jj->first;
                    jj->second--;
                    if(jj->second<=0)
                        m.erase(jj);
                    continue;
                }
                if(jj==m.end())
                {
                    tag=-1;
                    ans+=x-ii->first;
                    it->second--;
                    if(it->second<=0)
                        m.erase(it);
                    x=ii->first;
                    ii->second--;
                    if(ii->second<=0)
                        m.erase(ii);
                    continue;
                }
                if(jj->first-x==x-ii->first)
                {
                    if(tag==1)
                    {
                        tag=1;
                        ans+=jj->first-x;
                        it->second--;
                        if(it->second<=0)
                            m.erase(it);
                        x=jj->first;
                        jj->second--;
                        if(jj->second<=0)
                            m.erase(jj);
                        continue;
                    }
                    else
                    {
                        tag=-1;
                        ans+=x-ii->first;
                        it->second--;
                        if(it->second<=0)
                            m.erase(it);
                        x=ii->first;
                        ii->second--;
                        if(ii->second<=0)
                            m.erase(ii);
                        continue;
                    }
                }
                if(jj->first-x<x-ii->first)
                {
                    tag=1;
                    ans+=jj->first-x;
                    it->second--;
                    if(it->second<=0)
                        m.erase(it);
                    x=jj->first;
                    jj->second--;
                    if(jj->second<=0)
                        m.erase(jj);
                    continue;
                }
                else
                {
                    tag=-1;
                    ans+=x-ii->first;
                    it->second--;
                    if(it->second<=0)
                        m.erase(it);
                    x=ii->first;
                    ii->second--;
                    if(ii->second<=0)
                        m.erase(ii);
                    continue;
                }
            }
        }
        printf("Case %d: %I64d\n",++ca,ans);
    }
    return 0;
}
