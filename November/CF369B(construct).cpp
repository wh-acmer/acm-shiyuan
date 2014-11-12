// Valera and Contest
// http://codeforces.com/problemset/problem/369/B
// construct water

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int a[1010];
int main(){
    int n,k,l,r,sall,sk;
    while(cin>>n>>k>>l>>r>>sall>>sk){
        int tmp=sk/k;
        int re=sk%k;
        for(int i=1;i<=k;i++){
            a[i]=tmp;
            if(re){
                re--;
                a[i]++;
            }
        }
        sall-=sk;
        if(sall){
            int kk=n-k;
            tmp=sall/kk;
            re=sall%kk;
            for(int i=k+1;i<=n;i++){
                a[i]=tmp;
                if(re){
                    re--;
                    a[i]++;
                }
            }
        }
        for(int i=1;i<=n;i++) cout<<a[i]<<" ";
        cout<<endl;
    }
    return 0;
}
