#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
typedef pair<int,int>P;
vector<P>v;
stack<P>st;
int main(){
    int T,n,x;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        while(!st.empty()){
            st.pop();
        }
        int ok=0,zero=0,one=0;
        v.clear();
        for(int i=0;i<n;i++){
            scanf("%d",&x);
            if(x==1){
                if(ok==0){
                    if(one!=0 && zero!=0){
                        v.push_back(P(one,zero));
                    }
                    one=0,zero=0;
                }
                ok=1;
                one++;
            }
            else{
                if(ok==1){
                    zero=1;
                    ok=0;
                }
                else{
                    zero++;
                }
            }
        }
        if(one!=0 && zero!=0){
            v.push_back(P(one,zero));
        }
        for(int i=0;i<v.size();i++){
            if(st.empty()){
                st.push(v[i]);
                double mid=v[i].first/(v[i].first+v[i].second+0.0);
            }
            else{
                int first=0,second=0;
                P be=st.top();
                first+=v[i].first;
                second+=v[i].second;
                double mid=first/(first+second+0.0);
                double m=be.first/(be.first+be.second+0.0);
                while(mid<=m){
                    first+=be.first;
                    second+=be.second;
                    st.pop();
                    if(st.empty()) break;
                    be=st.top();
                    m=be.first/(be.first+be.second+0.0);
                    mid=first/(first+second+0.0);
                }
                st.push(P(first,second));
            }
        }
        double ans=0.0;
        while(!st.empty()){
            P p=st.top();
            double x=p.first/(p.first+p.second+0.0);
            ans+=p.first*(1-x)*(1-x)+p.second*x*x;
            st.pop();
        }
        printf("%.6lf\n",ans);
    }
    return 0;
}
