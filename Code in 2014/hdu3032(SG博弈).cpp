// SG´ò±í
/*
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;
#define maxn 2000
set<int>s;
int sg[maxn];
int solve()
{
    int i=0;
    while(s.count(i))
        i++;
    return i;
}
int main()
{
    int n;
    scanf("%d",&n);
    sg[0]=0;
    for(int i=0;i<=n;i++)
    {
        s.clear();
        for(int j=0;j<i;j++)
        {
            s.insert(sg[j]);
            s.insert(sg[j]^sg[i-j]);
        }
        sg[i]=solve();
    }
    for(int i=1;i<=n;i++)
        cout<<i<<":"<<sg[i]<<endl;
}
*/

#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int sg(int n)
{
    if(n%4==0)
        return n-1;
    if(n%4==3)
        return n+1;
    return n;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int ans=0,x;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            ans^=sg(x);
        }
        if(ans)
            printf("Alice\n");
        else
            printf("Bob\n");
    }
    return 0;
}
