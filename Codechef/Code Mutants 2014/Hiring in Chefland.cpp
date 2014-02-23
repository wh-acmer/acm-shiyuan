#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 101
int woman[N],man[N],wpre[N][N],mpre[N][N];
int main(){
    int T,n; scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int H=0,C=0;
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) scanf("%d",&wpre[i][j]);
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) scanf("%d",&mpre[i][j]);
        for(int i=1;i<=n;i++) woman[i]=0,man[i]=0;
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
        for(int i=1;i<=n;i++) if(man[i]==mpre[i][1]) C++;
        for(int i=1;i<=n;i++) if(wpre[man[i]][1]==i) H++;
        printf("%d %d\n",H,C);
    }
    return 0;
}
