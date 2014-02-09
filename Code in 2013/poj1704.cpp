/*
    game
*/
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int>v;
int main()
{
    int n,x,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        v.clear();
        while(n--)
        {
            scanf("%d",&x);
            v.push_back(x);
        }
        if(v.size()&1)
            v.push_back(0);
        sort(v.begin(),v.end());
        int ans=0;
        for(int i=0;i<v.size();i+=2)
            ans^=(v[i+1]-v[i]-1);
        if(ans)
            printf("Georgia will win\n");
        else
            printf("Bob will win\n");
    }
    return 0;
}
