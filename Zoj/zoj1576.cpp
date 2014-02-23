#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
using namespace std;
#define N 505
map<string,int>Wname,Mname;
int mpre[N][N],wpre[N][N],woman[N],man[N];
string s[2*N][N];
int check[N];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        Wname.clear(),Mname.clear();
        for(int i=1;i<=2*n;i++){
            for(int j=0;j<=n;j++) cin>>s[i][j];
            if(i<=n) Mname[s[i][0]]=i;
            else Wname[s[i][0]]=i;
        }
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) mpre[i][j]=Wname[s[i][j]]-n;
        for(int i=n+1;i<=n+n;i++) for(int j=1;j<=n;j++) wpre[i-n][j]=Mname[s[i][j]];
        memset(woman,0,sizeof(woman)),memset(man,0,sizeof(man));
        bool impossible=false;
        while(1){
            for(int i=1;i<=n;i++){
                if(man[i]==0){
                    bool ok=false; int index=1;
                    while(!ok && index<=n){
                        int lover=mpre[i][index];
                        if(woman[lover]==0){
                            woman[lover]=i;
                            man[i]=lover;
                            ok=true;
                        }
                        else{
                            bool they_are_better=false;
                            for(int j=1;j<=n;j++){
                                if(wpre[lover][j]==woman[lover]) break;
                                else if(wpre[lover][j]==i){
                                    they_are_better=true;
                                    break;
                                }
                            }
                            if(they_are_better){
                                man[woman[lover]]=0;
                                woman[lover]=i;
                                man[i]=lover;
                                ok=true;
                            }
                        }
                        index++;
                    }
                }
            }
            bool change=false;
            for(int i=1;i<=n;i++) if(man[i]!=check[i]) change=true;
            if(!change){
                impossible=true;
                break;
            }
            memcpy(check,man,sizeof(man));
            bool out=true;
            for(int i=1;i<=n;i++) if(man[i]==0) out=false;
            if(out) break;
        }
        if(impossible) printf("Impossible\n");
        else for(int i=1;i<=n;i++) printf("%s %s\n",s[i][0].c_str(),s[man[i]+n][0].c_str());
        printf("\n");
    }
    return 0;
}
