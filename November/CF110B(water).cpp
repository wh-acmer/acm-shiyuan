// Lucky String
// http://codeforces.com/problemset/problem/110/B
// water constructive algorithm

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <vector>
using namespace std;
typedef long long LL;
int main(){
    int n;
    string s="abcd";
    while(scanf("%d",&n)!=EOF){
        int l=n/4;
        n%=4;
        for(int i=0;i<l;i++) printf("%s",s.c_str());
        for(int i=0;i<n;i++) printf("%c",s[i]);
        printf("\n");
    }
    return 0;
}
