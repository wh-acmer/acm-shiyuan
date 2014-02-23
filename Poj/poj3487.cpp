#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <map>
using namespace std;
#define N 30
char name[2*N],s[N+10],str[10];
int wpre[N][N],mpre[N][N],man[N],woman[N];
map<char,int>Name;
struct node{
    char g,b;
}p[N];
bool cmp(node x,node y){
    if(x.b==y.b) return x.g<y.g; return x.b<y.b;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n; scanf("%d",&n); Name.clear();
        for(int i=1;i<=n;i++) scanf("%s",&str),name[i]=str[0],Name[name[i]]=i;
        for(int i=n+1;i<=2*n;i++) scanf("%s",&str),name[i]=str[0],Name[name[i]]=i;
        for(int i=1;i<=2*n;i++){
            scanf("%s",&s);
            int now=Name[s[0]];
            if(now<=n){ // boy
                for(int j=2;j<=2+n-1;j++) mpre[now][j-1]=Name[s[j]]-n;
            }
            else { // girl
                for(int j=2;j<=2+n-1;j++) wpre[now-n][j-1]=Name[s[j]];
            }
        }
        memset(woman,0,sizeof(woman)),memset(man,0,sizeof(man));
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
            bool out=true;
            for(int i=1;i<=n;i++) if(man[i]==0) out=false;
            if(out) break;
        }
        for(int i=1;i<=n;i++) p[i].b=name[i],p[i].g=name[man[i]+n];
        sort(p+1,p+n+1,cmp);
        for(int i=1;i<=n;i++) printf("%c %c\n",p[i].b,p[i].g);
        if(T) printf("\n");
    }
    return 0;
}
