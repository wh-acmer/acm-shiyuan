// K smallest numbers
// http://codeforces.com/gym/100499/problem/B
// water

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
typedef long long LL;
LL N,K,S,C1,C2,M,x;
multiset<LL>s;
int main(){
    int T;
    cin>>T;
    while(T--){
        s.clear();
        scanf("%I64d%I64d%I64d",&N,&K,&S);
        scanf("%I64d%I64d%I64d",&C1,&C2,&M);
        C1%=M;
        C2%=M;
        s.insert(S);
        x=S;
        multiset<LL>::iterator it=s.begin();
        for(int i=2;i<=N;i++){
            x=(x*C1+C2)%M;
            if(s.size()<100) s.insert(x);
            else{
                it=s.end();
                it--;
                LL tmp=*it;
                if(tmp>x){
                    s.erase(it);
                    s.insert(x);
                }
            }
        }
        it=s.begin();
        while(K--){
            printf("%I64d ",*it);
            *it++;
        }
        printf("\n");
    }
    return 0;
}
