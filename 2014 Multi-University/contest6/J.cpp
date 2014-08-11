#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;
string s[2];
typedef pair<int,int>P;
int N[2];
bool ok;
vector<int>B[2],S[2],Pa[2],Tri[2];
vector<P>F[2],Ti[2],TTi[2];
void init(){
    N[1]=N[0]=0;
    B[1].clear(),B[0].clear(),F[1].clear(),F[0].clear(),Ti[1].clear(),Ti[0].clear();
    TTi[1].clear(),TTi[0].clear(),S[1].clear(),S[0].clear();
    Pa[1].clear(),Pa[0].clear(),Tri[1].clear(),Tri[0].clear();
}
void change(int num,int x,int now){
    if(num==1) S[now].push_back(x);
    if(num==2) Pa[now].push_back(x);
    if(num==3) Tri[now].push_back(x);
    if(num==4) B[now].push_back(x);
}
void pre(int ss){
    int now=0,index=0;
    while(index<s[ss].size()){
        if(s[ss][index]==s[ss][now]) index++;
        else{
            if(s[ss][now]-'0'==2) s[ss][now]='K'+2;
            else if(s[ss][now]=='A') s[ss][now]='K'+1;
            else if(s[ss][now]=='Q') s[ss][now]='K'-1;
            else if(s[ss][now]=='T') s[ss][now]='J'-1;
            change(index-now,s[ss][now]-'0',ss),now=index;
        }
    }
    if(s[ss][now]-'0'==2) s[ss][now]='K'+2;
    else if(s[ss][now]=='A') s[ss][now]='K'+1;
    else if(s[ss][now]=='Q') s[ss][now]='K'-1;
    else if(s[ss][now]=='T') s[ss][now]='J'-1;
    change(index-now,s[ss][now]-'0',ss);
}
void re_change(int now){
    for(int i=0;i<Pa[now].size();i++){
        S[now].push_back(Pa[now][i]);
    }
    for(int i=0;i<Tri[now].size();i++){
        S[now].push_back(Tri[now][i]);
        Pa[now].push_back(Tri[now][i]);
    }
    for(int i=0;i<Tri[now].size();i++){
        for(int j=0;j<S[now].size();j++){
            Ti[now].push_back(P(Tri[now][i],S[now][j]));
        }
        for(int j=0;j<Pa[now].size();j++){
            TTi[now].push_back(P(Tri[now][i],Pa[now][j]));
        }
    }
    for(int i=0;i<B[now].size();i++){
        for(int j=0;j<Pa[now].size();j++){
            TTi[now].push_back(P(B[now][i],Pa[now][j]));
        }
    }
    for(int i=0;i<S[now].size();i++){
        if(S[now][i]==('X'-'0') || S[now][i]==('Y'-'0')){
            N[now]++;
        }
    }
    if(N[now]==2) N[now]=1;
    else N[now]=0;
}
void solve(vector<int>v[2]){
    for(int i=0;i<v[0].size();i++){
        int tmp=0;
        for(int j=0;j<v[1].size();j++){
            if(v[1][j]>v[0][i]){
                tmp=1;
            }
        }
        if(tmp) ;
        else ok=true;
    }
}
void ssolve(vector<P>v[2]){
    for(int i=0;i<v[0].size();i++){
        int tmp=0;
        for(int j=0;j<v[1].size();j++){
            if(v[1][j]>v[0][i]){
                tmp=1;
            }
        }
        if(tmp) ;
        else ok=true;
    }
}
int main(){
    int T; cin>>T;
    while(T--){
        cin>>s[0]>>s[1];  init();
        sort(s[0].begin(),s[0].end()),sort(s[1].begin(),s[1].end());
        pre(0);
        pre(1);
        if((S[0].size()==1 && Pa[0].size()==0 && Tri[0].size()==0 && B[0].size()==0) ||
        (S[0].size()==0 && Pa[0].size()==1 && Tri[0].size()==0 && B[0].size()==0) ||
        (S[0].size()==0 && Pa[0].size()==0 && Tri[0].size()==1 && B[0].size()==0) ||
        (S[0].size()==0 && Pa[0].size()==0 && Tri[0].size()==0 && B[0].size()==1) ||
        (S[0].size()==1 && Pa[0].size()==0 && Tri[0].size()==1 && B[0].size()==0) ||
        (S[0].size()==0 && Pa[0].size()==1 && Tri[0].size()==1 && B[0].size()==0) ||
        (S[0].size()==0 && Pa[0].size()==1 && Tri[0].size()==0 && B[0].size()==1) ){
            printf("Yes\n"); continue;
        }
        re_change(0),re_change(1);
        ok=false;
        if(N[0]){
            printf("Yes\n");
            continue;
        }
        if(N[1]){
            printf("No\n");
            continue;
        }
        solve(B);
        if(ok){
            printf("Yes\n");
            continue;
        }
        else if(B[1].size()){
            printf("No\n");
            continue;
        }
        solve(S),solve(Pa),solve(Tri);
        ssolve(Ti),ssolve(TTi),ssolve(F);
        if(ok) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
