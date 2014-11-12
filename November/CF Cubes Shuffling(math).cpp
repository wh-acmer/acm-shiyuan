// Cubes Shuffling
// http://codeforces.com/gym/100283/problem/K
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
deque<int>q;
vector<int>v;
int a[110];
int main(){
    int T;
    freopen("cubes.in","r",stdin);
    cin>>T;
    for(int cas=1;cas<=T;cas++){
        int n;
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a,a+n);
        q.clear();
        q.push_front(a[0]);
        if(n&1){
            for(int i=1;i<n;i++){
                if(i&1) q.push_front(a[i]);
                else q.push_back(a[i]);
            }
        }
        else{
            for(int i=1;i<n;i++){
                if(i&1) q.push_back(a[i]);
                else q.push_front(a[i]);
            }
        }
        deque<int>::iterator it=q.begin();
        v.clear();
        while(it!=q.end()){
            v.push_back(*it);
            it++;
        }
        printf("Case %d:\n",cas);
        for(int i=0;i<v.size();i++){
            printf("%d",v[i]);
            if(i+1==v.size()) printf("\n");
            else printf(" ");
        }
    }
    return 0;
}
