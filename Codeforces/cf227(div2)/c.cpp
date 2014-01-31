#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
typedef pair<int,int> P;
pair<int,int>s1,s2;
string s;
bool small(P ss1,P ss2){
    if(ss1.second-ss1.first<ss2.second-ss2.first) return true;
    else if(ss1.second-ss1.first>ss2.second-ss2.first) return false;
    for(int i=ss1.first;i<=ss1.second;i++)
        if(s[i]<s[i-ss1.first+ss2.first]) return true;
        else if(s[i]>s[i-ss1.first+ss2.first]) return false;
    return false;
}
int solve(P S){
    int i=S.second;
    while(s[i]=='0' && i>=0) i--;
    s2.second=S.second;
    s2.first=i;
    s1.first=S.first;
    s1.second=i-1;
    if(s1.second<s1.first) return 1;
    /*cout<<S.first<<":"<<S.second<<endl;
    cout<<s1.first<<":"<<s1.second<<endl;
    cout<<s2.first<<":"<<s2.second<<endl;
    cout<<endl;*/
    if(small(s1,s2))    return 1;
    return solve(s1)+1;

}
int main(){
    while(cin>>s){
        P S(0,s.size()-1);
        cout<<solve(S)<<endl;
    }
    return 0;
}
