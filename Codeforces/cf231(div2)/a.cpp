#include <cstring>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstdio>
using namespace std;
typedef __int64 LL;
int main(){
    int num[3];
    string s;
    while(cin>>s){
        memset(num,0,sizeof(num));
        int i=0;
        for(;i<s.size();i++){
            if(s[i]=='+') break;
            else if(s[i]=='|') num[0]++;
        }
        for(;i<s.size();i++){
            if(s[i]=='=') break;
            else if(s[i]=='|') num[1]++;
        }
        for(;i<s.size();i++){
            if(s[i]=='|') num[2]++;
        }
        if(num[0]+num[1]==num[2]) cout<<s<<endl;
        else{
            int tmp=num[2]-num[1]-num[0];
            if(tmp==2){
                num[2]-=tmp/2;
                num[0]+=tmp/2;
                for(int x=0;x<num[0];x++) cout<<"|";
                cout<<"+";
                for(int x=0;x<num[1];x++) cout<<"|";
                cout<<"=";
                for(int x=0;x<num[2];x++) cout<<"|";
                cout<<endl;
            }
            else if(tmp==-2){
                if(num[0]>1) num[0]--;
                else num[1]--;
                num[2]++;
                for(int x=0;x<num[0];x++) cout<<"|";
                cout<<"+";
                for(int x=0;x<num[1];x++) cout<<"|";
                cout<<"=";
                for(int x=0;x<num[2];x++) cout<<"|";
                cout<<endl;
            }
            else printf("Impossible\n");
        }
    }
    return 0;
}
