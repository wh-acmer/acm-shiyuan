#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;
#define maxn 101
int a[maxn];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        while(1){
            bool ok=true;
            int mi=a[0];
            for(int i=0;i<n;i++) mi=min(mi,a[i]);
            for(int i=0;i<n;i++){
                if(a[i]>mi){
                    ok=false;
                }
                a[i]%=mi;
                if(a[i]==0) a[i]+=mi;
            }
            if(ok) break;
        }
        int sum=0;
        for(int i=0;i<n;i++) sum+=a[i];
        printf("%d\n",sum);
    }
    return 0;
}
