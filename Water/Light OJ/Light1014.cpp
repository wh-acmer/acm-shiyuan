#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>v;
int cases,l,p;
void solve()
{
    scanf("%d%d",&p,&l);
    printf("Case %d: ",cases);
    p-=l;
    v.clear();
    for(long long i=1;i*i<=p;i++)
    {
        if(p%i==0)
        {
            if(i>l)
            v.push_back(i);
            if(p!=i*i&&p/i>l)
                v.push_back(p/i);
        }
    }
    sort(v.begin(),v.end());
    if(v.size()==0)
    {
        printf("impossible\n");
        return ;
    }
    for(int i=0;i<v.size()-1;i++)
        printf("%d ",v[i]);
    printf("%d\n",v[v.size()-1]);
    return ;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(cases=1;cases<=t;cases++)
        solve();
    return 0;
}
