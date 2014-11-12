// Headshot
// http://uva.onlinejudge.org/external/16/1636.pdf
// water math

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
int main(){
    string s;
    while(cin>>s){
        int oo=0;
        int o=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                o++;
                if(s[(i+1)%s.size()]=='0') oo++;
            }
        }
        int ans=oo*s.size()-o*o;
        if(ans==0) printf("EQUAL\n");
        else if(ans<0) printf("ROTATE\n");
        else printf("SHOOT\n");
    }
    return 0;
}
