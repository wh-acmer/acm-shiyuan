/*
    water
*/
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;
vector<long long>v[11];
int get(long long n)
{
    int ans=0;
    while(n)
    {
        ans++;
        n/=10;
    }
    return ans;
}
long long Pow(long long a,long long b)
{
    long long ans=1;
    while(b)
    {
        if(b&1)
        {
            b--;
            ans=(ans*a);
        }
        else
        {
            b/=2;
            a*=a;
        }
    }
    return ans;
}
int main()
{
    for(int i=1;i<=10;i++)
        v[i].clear();
    for(int i=0;i<3;i++)
        v[1].push_back(i);
    int tmp[9]={10,11,12,20,21,22,30,31,32};
    for(int i=0;i<9;i++)
        v[2].push_back(tmp[i]);
    for(int k=3;k<=10;k++)
    {
        for(long long i=1;i<=3;i++)
        {
            for(int p=k-1;p>=1;p--)
                for(int j=0;j<v[p].size();j++)
                    v[k].push_back(Pow(10,k-1)*i+v[p][j]);
        }
        sort(v[k].begin(),v[k].end());
    }
    long long n;
    while(scanf("%I64d",&n)!=EOF)
    {
        if(n<=3)
        {
            printf("%I64d\n",n);
            continue;
        }
        int l=get(n);
        int ans=0;
        for(int i=1;i<l;i++)
            ans+=v[i].size();
        ans+=lower_bound(v[l].begin(),v[l].end(),n)-v[l].begin();
        printf("%d\n",ans);
    }
    return 0;
}
