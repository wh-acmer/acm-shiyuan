/*#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;
int a[10001];
int main(){
    memset(a,0,sizeof(a));
    a[1]=1;
    a[2]=0;
    a[3]=1;
    a[4]=1;
    a[5]=0;
    for(int i=6;i<=10000;i++){
        int p=0;
        for(int j=(i+1)/2;j<i;j++){
            if(a[i]==1) break;
            if(a[j]==0) a[i]=1,p=j;
        }
        if(p==0) a[i]=0;
    }
    for(int i=1;i<=10000;i++){
        //cout<<i<<":"<<a[i]<<endl;
        if(a[i]==0) cout<<i<<endl;
    }
}*/
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;
set<int>s;
int main(){
    int mx=1000000001;
    s.clear();
    int now=2;
    while(now<mx){
        s.insert(now);
        now=now*2+1;
    }
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        if(s.count(n))
            printf("Bob\n");
        else
            printf("Alice\n");
    }
    return 0;
}
