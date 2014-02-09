/*
    sg game
*/
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;
set<int>s;
int main()
{
    s.clear();
    int two=1;
    for(;two<=1000;two*=2)
        s.insert(two);
    for(int i=1;i<=1000;i++)
    {
        if(s.count(i))
            continue;
        for(set<int>::iterator it=s.begin();it!=s.end();it++)
        {
            if(*it+i<=1000)
                s.insert(*it+i);
        }
    }
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(s.count(n))
            printf("Kiki\n");
        else
            printf("Cici\n");
    }
    return 0;
}
