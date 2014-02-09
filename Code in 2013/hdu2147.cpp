/*
    water
*/
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF,m+n)
    {
        if((n&1)&&(m&1))
            printf("What a pity!\n");
        else
            printf("Wonderful!\n");
    }
    return 0;
}
