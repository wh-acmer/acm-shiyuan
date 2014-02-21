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
#define maxn 1000010
int p[maxn];
int main(){
    int n,x,jin,now;
    while(scanf("%d%d",&n,&x)!=EOF){
        bool ok=false;
        for(int i=1;i<=9 && !ok;i++){
            now=1; jin=0;
            p[now]=i;
            while(1){
                if(now==n){
                    if(p[now]*x+jin==p[1] && p[now]) ok=true;
                    break;
                }
                p[now+1]=(p[now]*x+jin)%10;
                jin=(p[now]*x+jin)/10;
                now++;
            }
        }
        if(!ok) printf("Impossible\n");
        else{
            for(int i=n;i>=1;i--) printf("%d",p[i]);
            printf("\n");
        }
    }
    return 0;
}
