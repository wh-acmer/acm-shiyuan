/*
    ¶þ·Ö
*/
#include <cstring>
#include <cmath>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
using namespace std;
vector<int>stone;
int L,n,m,x;
bool ok(int mid)
{
    int now=0;
    int cur=0;
    for(int i=1;i<stone.size();i++)
    {
        if(stone[i]-stone[now]<mid)
        {
            cur++;
            if(cur>m)
                return false;
        }
        else
            now=i;
    }
    return true;
}
int main()
{
   scanf("%d%d%d",&L,&n,&m);
   stone.clear();
   stone.push_back(0);
   stone.push_back(L);
   for(int i=0;i<n;i++)
   {
       scanf("%d",&x);
       stone.push_back(x);
   }
   sort(stone.begin(),stone.end());
   int l=-1,r=L+1,mid;
   while(r-l>1)
   {
       mid=(l+r)/2;
       if(ok(mid))
          l=mid;
       else
          r=mid;
   }
   printf("%d\n",l);
   return 0;
}
