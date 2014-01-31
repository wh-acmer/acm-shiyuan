#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define maxn 1010
int a[maxn][110];
typedef pair<int,int> P;
vector<P>ans;
int main(){
    int n,m,K;
    while(cin>>n>>m>>K){
        ans.clear();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
            a[i][0]=a[i][1];
        }
        int now=1;
        int index=0;
        if(K==0){
            for(int i=now;i<=n;i++){
                bool ok=true;
                for(int j=1;j<=m;j++){
                    for(int k=1;k<j;k++){
                        if(a[i][k]>a[i][j]){
                            //swap(a[i][k],a[i][j]);
                            for(int ii=1;ii<=n;ii++){
                                if(a[ii][k]>a[ii][j])
                                    swap(a[ii][k],a[ii][j]);
                            }
                            ans.push_back(P(k,j));
                            ok=false;
                        }
                    }
                }
                if(ok) now++;
            }
        }
        else{
            for(int i=now;i<=n;i++){
                bool ok=true;
                for(int j=1;j<=m;j++){
                    for(int k=1;k<j;k++){
                        if(a[i][k]<a[i][j]){
                            //swap(a[i][k],a[i][j]);
                            for(int ii=1;ii<=n;ii++){
                                if(a[ii][k]<a[ii][j])
                                    swap(a[ii][k],a[ii][j]);
                            }
                            ans.push_back(P(j,k));
                            ok=false;
                        }
                    }
                }
                if(ok) now++;
            }
        }
        printf("%d\n",ans.size());
        for(int i=0;i<ans.size();i++)
            cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
}
