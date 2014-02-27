#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    string s;
    while(cin>>s){
        int ans=0,now=1;
        char str=s[0];
        for(int i=1;i<s.size();i++){
            if(s[i]==str){
                now++;
            }
            if(s[i]!=str || i+1==s.size())
            {
                if(now&1) ;
                else ans++;
                str=s[i];
                now=1;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
