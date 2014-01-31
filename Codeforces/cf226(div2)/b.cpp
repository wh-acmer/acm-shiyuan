#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
string s;
vector<int>v;
int main(){
    while(cin>>s){
        v.clear();
        v.push_back(0);
        for(int i=0;i+3<s.size();i++){
            if(s[i]=='b' && s[i+1]=='e' &&
               s[i+2]=='a' && s[i+3]=='r')
            v.push_back(i+1);
        }
        long long ans=0;
        for(int i=1;i<v.size();i++){
            ans+=(long long)(v[i]-v[i-1])*(s.size()-v[i]-2);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
