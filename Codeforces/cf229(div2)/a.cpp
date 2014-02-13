/*
    water
*/
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;
map<int,int>m1,m2;
int main(){
    int n,x,y;
    while(scanf("%d",&n)!=EOF){
        m1.clear();m2.clear();
        while(n--){
            scanf("%d%d",&x,&y);
            m1[x]++,m2[y]++;
        }
        printf("%d\n",min(m1.size(),m2.size()));
    }
    return 0;
}
