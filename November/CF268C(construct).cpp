// Beautiful Sets of Points
// http://codeforces.com/problemset/problem/268/C
// constructive algorithm

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <vector>
using namespace std;
typedef long long LL;
#define N 1000010
typedef pair<int,int>P;
vector<P>v;
int n,m;
bool in(int x,int y){
    return x>=0 && x<=n && y>=0 && y<=m;
}
int main(){
    while(cin>>n>>m){
        bool is_swap=false;
        v.clear();
        if(n>m){
            swap(n,m);
            is_swap=true;
        }
        for(int i=0;i<=n;i++){
            if(in(i,m-i)) v.push_back(P(i,m-i));
        }
        cout<<v.size()<<endl;
        for(int i=0;i<v.size();i++){
            if(is_swap) cout<<v[i].second<<" "<<v[i].first<<endl;
            else cout<<v[i].first<<" "<<v[i].second<<endl;
        }
    }
    return 0;
}
