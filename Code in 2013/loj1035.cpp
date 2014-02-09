/*
分解质因素，求一个数的阶乘对某一个质数的幂：n/p + n/p^2 + n/p^3 + ....
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <queue>
using namespace std;
int prime[26]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int main()
{
    int t;
    scanf("%d",&t);
    int n;
    for(int cases=1;cases<=t;cases++)
    {
        scanf("%d",&n);
        printf("Case %d: %d = ",cases,n);
        map<int,int>m;
        m.clear();
        for(int i=1;i<=25;i++)
        {
            int tmp=n;
            int cnt=prime[i];
            while(n/cnt)
            {
                m[prime[i]]+=n/cnt;
                cnt*=prime[i];
            }
        }
        deque<map<int,int>::iterator>q;
        while(!q.empty())
            q.pop_front();
        map<int,int>::iterator it=m.begin();
        for(;it!=m.end();it++)
            q.push_back(it);
        while(q.size()!=1)
        {
            printf("%d (%d) * ",q.front()->first,q.front()->second);
            q.pop_front();
        }
        printf("%d (%d)\n",q.front()->first,q.front()->second);
    }
    return 0;
}
