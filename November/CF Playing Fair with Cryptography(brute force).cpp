// C - Playing Fair with Cryptography
// http://codeforces.com/gym/100291/attachments/download/2016/20132014-ct-s01e011-codeforces-trainings-season-1-episode-11-en.pdf
// ±©Á¦Ä£Äâ

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
using namespace std;
char a[6][6],b[26];
char s[10001];
bool vis[26];
typedef pair<int,int>P;
map<char,P>mp;
void get_table(){
    mp.clear();
    memset(vis,false,sizeof vis);
    int l=strlen(s);
    int num=0;
    for(int i=0;i<l;i++){
        if(s[i]>='a' && s[i]<='z') s[i]=s[i]-'a'+'A';
        else if(s[i]>='A' && s[i]<='Z') ;
        else continue;
        if(vis[s[i]-'A']) ;
        else{
            vis[s[i]-'A']=true;
            b[num++]=s[i];
        }
    }
    vis['J'-'A']=true;
    for(int i=0;i<26;i++){
        if(vis[i]==false){
            b[num++]=(i+'A');
        }
    }
    num=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            a[i][j]=b[num++];
            mp[a[i][j]]=P(i,j);
        }
    }
}
void encryption(char x,char y){
    P px=mp[x];
    P py=mp[y];
    if(px.first==py.first){
        // the same row
        printf("%c%c",a[px.first][(px.second+1)%5],a[py.first][(py.second+1)%5]);
    }
    else if(px.second==py.second){
        // the same col
        printf("%c%c",a[(px.first+1)%5][px.second],a[(py.first+1)%5][py.second]);
    }
    else{
        // slide
        printf("%c%c",a[px.first][py.second],a[py.first][px.second]);
    }
}
void solve(){
    int l=strlen(s);
    string str="";
    for(int i=0;i<l;i++){
        if(s[i]>='a' && s[i]<='z') str+=(s[i]-'a'+'A');
        else if(s[i]>='A' && s[i]<='Z') str+=s[i];
    }
    l=str.size();
    int now=0;
    int fuck_word=0;
    while(now<l){
        if(now+1==l){
            // the last char
            while(('A'+fuck_word)==str[now] || (fuck_word+'A'=='J')) fuck_word=(fuck_word+1)%26;
            encryption(str[now],'A'+fuck_word);
            fuck_word=(fuck_word+1)%26;
            now++;
        }
        else{
            if(str[now]==str[now+1]){
                // the same
                while(('A'+fuck_word)==str[now] || (fuck_word+'A'=='J')) fuck_word=(fuck_word+1)%26;
                encryption(str[now],'A'+fuck_word);
                fuck_word=(fuck_word+1)%26;
                now++;
            }
            else{
                encryption(str[now],str[now+1]);
                now+=2;
            }
        }
    }
    printf("\n");
}
int main(){
    int T;
    scanf("%d",&T);
    getchar();
    for(int cas=1;cas<=T;cas++){
        gets(s);
        get_table();
        gets(s);
        printf("Case %d: ",cas);
        solve();
    }
    return 0;
}
/*
1
ECNA Programming Contest 2013
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
Case 1: NDPNMQPCPDNMEQ PMCQNQMDPACMPEMYEMCDEDPQEYCYNYMAPYNDPNMQPCPDNMEQPMCQNQMDPACMPEMYEMCDED
*/
