/*
    water 模拟
    按照题目格式可以用map水过
*/

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
map<string,int>mp;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        mp.clear();
        scanf("%d",&n);
        string s,str;
        int num;
        for(int c=1;c<n;c++){
            cin>>s>>str>>num;
            mp[s]=num;
        }
        int ans=0,now=1;
        while(cin>>str && str!="="){

            if(str=="+" && str.size()==1) now=1;
            else if(str=="-" && str.size()==1) now=-1;
            else if(str[0]=='-' || (str[0]>='0' && str[0]<='9')){
                int i=0;
                int flag=1;
                if(str[i]=='-') flag=-1,i++;
                int num=0;
                for(;i<str.size();i++)
                    num=num*10+str[i]-'0';
                ans=ans+now*flag*num;
            }
            else{
                ans=ans+now*mp[str];
            }
        }
        cin>>str;
        printf("%d\n",ans);
    }
    return 0;
}
