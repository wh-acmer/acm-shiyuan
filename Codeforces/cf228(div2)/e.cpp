#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
vector<int>v;
int a[101];
int main(){
    int n,x,y,l,r;
    while(scanf("%d",&n)!=EOF){
        l=0,r=0;
        v.clear();
        while(n--){
            scanf("%d",&x);
            for(int i=1;i<=x;i++) scanf("%d",&a[i]);
            if(x&1){
                for(int i=1;i<=x/2;i++) l+=a[i];
                for(int i=x/2+2;i<=x;i++) r+=a[i];
                v.push_back(a[x/2+1]);
            }
            else {
                for(int i=1;i<=x/2;i++) l+=a[i];
                for(int i=x/2+1;i<=x;i++) r+=a[i];
            }
        }
        sort(v.begin(),v.end(),cmp);
        for(int i=0;i<v.size();i++){
            if(i&1) r+=v[i];
            else l+=v[i];
        }
        printf("%d %d\n",l,r);
    }
    return 0;
}
