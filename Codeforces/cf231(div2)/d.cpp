#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define N 1001
int a[N];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++) scanf("%d",&a[i]); sort(a,a+n);
        int _step=0,now,ans=100010,cnt=a[0],mx,mi;
        for(int step=0;step<=20001;step++){
            now=a[0]; mx=0; mi=0;
            for(int j=0;j<n;j++){
                mx=max(mx,a[j]-now);
                mi=min(mi,a[j]-now);
                now+=step;
            }
            int tmp=(mx-mi+1)/2;
            if(tmp<ans){
                ans=tmp;
                _step=step;
                cnt=a[0]+mx-ans;
            }
        }
        printf("%d\n",ans);
        printf("%d %d\n",cnt,_step);
    }
    return 0;
}
