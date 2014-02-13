/*
    stl
*/
#include <list>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
list<char>li;
list<char>::iterator it;
int T,cas;
string str;
char s;
int main(){
    cas=0;
    scanf("%d",&T);
    while((s==getchar())=='\n');
    while(T--){
        li.clear();
        it=li.begin();
        while((s=getchar())!='\n'){
            if(s=='<'){
                if(it==li.begin()) ;
                else it--;
            }
            else if(s=='>'){
                if(it==li.end()) ;
                else it++;
            }
            else if(s=='-'){
                if(it==li.begin()) ;
                else{
                    it--;
                    it=li.erase(it);
                }
            }
            else{
                li.insert(it,s);
            }
        }
        printf("Case %d: ",++cas);
        for(it=li.begin();it!=li.end();it++) cout<<*it;
        cout<<endl;
    }
    return 0;
}
