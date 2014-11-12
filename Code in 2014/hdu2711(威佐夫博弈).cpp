#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
double tmp=(sqrt(5.0)+1)/2;
map<int,int>mp;
map<int,int>ans;
int main()
{
    mp.clear();
    for(int i=0;i<1000010;i++)
        mp[(int)i*tmp]=(int)i*tmp+i;
    map<int,int>::iterator it=mp.begin();
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF,m+n)
    {
        ans.clear();
        if(mp[n]==m)
            printf("0\n");
        else
        {
            printf("1\n");
            map<int,int>::iterator it=mp.begin(),ii=mp.end(),jj=mp.end();
            for(;it!=mp.end() && (it->first<=m);it++)
            {
                if(it->second==m)
                {
                    ii=it;
                }
                else if(it->second==n)
                {
                    jj=it;
                }
                if(n-it->first == m-it->second && m-it->second>0)
                    ans[it->first]=it->second;
            }
            for(it=ans.begin();it!=ans.end();it++)
            {
                printf("%d %d\n",it->first,it->second);
            }
            if(mp[n]&&mp[n]<m)
                printf("%d %d\n",n,mp[n]);
            if(ii!=mp.end()&&ii->first<n)
                printf("%d %d\n",ii->first,m);
            if(jj!=mp.end())
                printf("%d %d\n",jj->first,jj->second);
        }
    }
    return 0;
}
