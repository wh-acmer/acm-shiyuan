#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
using namespace std;
int f(int a){
    if(a<0) return -a;
    return a;
}
int main(){
    string s,str;
    while(cin>>s){
        cin>>str;
        string x="",y="";
        int i;
        for(i=0;i<s.size();i++){
            if(s[i]!='|') x=x+s[i];
            else break;
        }
        for(i=i+1;i<s.size();i++){
            y=y+s[i];
        }
        //cout<<x<<":"<<y<<endl;
        if((x.size()+y.size()+str.size())%2==1){
            cout<<"Impossible"<<endl;
        }
        else if(f(x.size()-y.size())>str.size()){
            cout<<"Impossible"<<endl;
        }
        else{
            int now=0;
            int last=(x.size()+y.size()+str.size())/2;
            if(x.size()>y.size()){
                int p=last-x.size();
                for(int i=0;i<p;i++) x=x+str[i];
                for(int i=p;i<str.size();i++)
                    y=y+str[i];
                cout<<x<<"|"<<y<<endl;
            }
            else{
                int p=last-y.size();
                for(int i=0;i<p;i++) y=y+str[i];
                for(int i=p;i<str.size();i++)
                    x=x+str[i];
                cout<<x<<"|"<<y<<endl;
            }
        }
    }
    return 0;
}
