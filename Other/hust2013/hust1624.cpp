/*
    题意：模拟，旋转和对称都算一种
    思路：记录对某点的相对位置
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
#define maxn 110
char s[maxn][maxn];
int vis[maxn][maxn];
struct star{
    vector<pair<int,int> >v;
    int flag;
}p[510];
bool cmp(const pair<int,int> &a,const pair<int,int> &b){
    if(a.first==b.first) return a.second<b.second;
    return a.first<b.first;
}
int dx[]={0,-1,-1,-1,0,1,1,1};
int dy[]={1,1,0,-1,-1,-1,0,1};
int n,m;
void dfs(int x,int y,int now){
    p[now].v.push_back(make_pair(x,y));
    vis[x][y]=1;
    int xx,yy;
    for(int i=0;i<8;i++){
        xx=x+dx[i];
        yy=y+dy[i];
        if(xx>=0 && yy>=0 && xx<n && yy<m && s[xx][yy]=='1' && !vis[xx][yy]){
            dfs(xx,yy,now);
        }
    }
}
void paint(int x,int y,int now){
    vis[x][y]=1;
    s[x][y]='a'+now;
    int xx,yy;
    for(int i=0;i<8;i++){
        xx=x+dx[i];
        yy=y+dy[i];
        if(xx>=0 && yy>=0 && xx<n && yy<m && s[xx][yy]=='1' && !vis[xx][yy]){
            paint(xx,yy,now);
        }
    }
}
bool not_equal(pair<int,int>&a,pair<int,int>&b){
    if(a.first!=b.first) return true;
    if(a.second!=b.second) return true;
    return false;
}
int same(int x,int y){
    if(p[x].v.size()!=p[y].v.size()) return 0;
    sort(p[x].v.begin(),p[x].v.end(),cmp);
    bool ok=false;
    vector<pair<int,int> > vt,py;
    py.assign(p[y].v.begin(),p[y].v.end());
    for(int pi=0;pi<4;pi++){
        for(int i=0;i<py.size();i++){
            vt.assign(py.begin(),py.end());
            for(int j=0;j<vt.size();j++){
                vt[j].first-=py[i].first;
                vt[j].second-=py[i].second;
            }
            sort(vt.begin(),vt.end(),cmp);
            bool pnow=true;
            for(int j=0;j<vt.size();j++){
                if(not_equal(vt[j],p[x].v[j])){
                    pnow=false;
                    break;
                }
            }
            if(pnow){
                return 1;
            }
        }
        for(int pj=0;pj<py.size();pj++){
            swap(py[pj].second,py[pj].first);
            py[pj].first*=-1;
        }
    }
    for(int pi=0;pi<4;pi++){
        for(int i=0;i<py.size();i++){
            vt.assign(py.begin(),py.end());
            for(int j=0;j<vt.size();j++){
                vt[j].first=py[i].first-vt[j].first;
                vt[j].second-=py[i].second;
            }
            sort(vt.begin(),vt.end(),cmp);
            bool pnow=true;
            for(int j=0;j<vt.size();j++){
                if(not_equal(vt[j],p[x].v[j])){
                    pnow=false;
                    break;
                }
            }
            if(pnow){
                return 1;
            }
        }
        for(int pj=0;pj<py.size();pj++){
            swap(py[pj].second,py[pj].first);
            py[pj].first*=-1;
        }
    }
    return 0;
}
int main(){
    int T;
    scanf("%d",&T);
    int hah=0;
    while(T--){
        if(hah) printf("\n");
        else hah++;
        scanf("%d%d",&m,&n);
        memset(vis,false,sizeof(vis));
        for(int i=0;i<n;i++) scanf("%s",&s[i]);
        int now=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                if(!vis[i][j] && s[i][j]=='1'){
                    p[now].flag=-1;
                    p[now].v.clear();
                    dfs(i,j,now);
                    for(int k=p[now].v.size()-1;k>=0;k--){
                        p[now].v[k].first-=p[now].v[0].first;
                        p[now].v[k].second-=p[now].v[0].second;
                    }
                    now++;
                }
            }
        int current=0;
        for(int i=0;i<now;i++){
            if(p[i].flag==-1){
                p[i].flag=current++;
                for(int j=i+1;j<now;j++){
                    if(same(i,j)){
                        p[j].flag=p[i].flag;
                    }
                }
            }
        }
        memset(vis,false,sizeof(vis));
        now=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                if(!vis[i][j] && s[i][j]=='1'){
                    paint(i,j,p[now].flag);
                    now++;
                }
            }
        for(int i=0;i<n;i++)
            printf("%s\n",s[i]);
    }
    return 0;
}
