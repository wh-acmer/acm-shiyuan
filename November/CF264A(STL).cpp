// Escape from Stones
// http://codeforces.com/problemset/problem/264/A
// STL

#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <list>
using namespace std;
#define N 1000010
char s[N];
list<int>li;
list<int>::iterator ll,rr,it;
int main(){
    while(scanf("%s",&s)!=EOF){
        int len=strlen(s);
        li.clear();
        li.push_back(-1);
        ll=li.begin();
        rr=ll;
        li.push_back(-1);
        rr++;
        for(int i=0;i<len;i++){
            if(s[i]=='l'){
                it=ll;
                li.insert(++it,i+1);
                rr=ll;
                rr++;
            }
            else{
                it=ll;
                li.insert(++it,i+1);
                ll=rr;
                ll--;
            }
        }
        for(it=li.begin();it!=li.end();it++){
            if(*it>0) printf("%d\n",*it);
        }
    }
    return 0;
}
