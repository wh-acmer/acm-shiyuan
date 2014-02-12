/*
    sg game
*/
/*
// SG ´ò±í
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;
set<int>s;
const int maxn = 2001;
int sg[maxn];
int get()
{
    int i=0;
    while(s.count(i))
        i++;
    return i;
}
int main()
{
    int n,p,q;
    scanf("%d%d%d",&n,&p,&q);
    sg[1]=0;
    for(int i=2;i<=n;i++)
    {
        s.clear();
        for(int j=p;j<=q;j++)
            if(i-j>=1)
                s.insert(sg[i-j]);
        sg[i]=get();
    }
    sg[0]=0;
    for(int i=1;i<=n;i++)
    {
        cout<<i<<":"<<sg[i]<<endl;
    }
    return 0;
}
*/

// AC ´úÂë
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;
int main()
{
    int n,p,q;
    while(scanf("%d%d%d",&n,&p,&q)!=EOF)
    {
        int tmp=n%(p+q);
        if(tmp==0 || tmp>p)
            printf("WIN\n");
        else
            printf("LOST\n");
    }
    return 0;
}
