#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <string>
using namespace std;
#define maxn 200010
#define mod 1000000007
typedef long long LL;
struct node{
    LL x,y,num;
    node(){}
    node(LL x,LL y,LL num){
        this->x=x;
        this->y=y;
        this->num=num;
    }
}p[maxn];
int fa[maxn];
map<LL,set<LL> >col;
map<LL,set<LL> >row;
set<LL>s;
set<LL>::iterator it;
char str[5];
inline LL input(){
    LL ret=0;bool isN=0;char c=getchar();
    while(c<'0' || c>'9'){
        if(c=='-') isN=1;
        c=getchar();
    }
    while(c>='0' && c<='9'){
        ret=ret*10+c-'0';
        c=getchar();
    }
    return isN?-ret:ret;
}

inline void output(LL x){
    if(x<0){
        putchar('-');x=-x;
    }
    int len=0,data[20];
    while(x){
        data[len++]=x%10;x/=10;
    }
    if(!len)    data[len++]=0;
    while(len--)
        putchar(data[len] +48);
    putchar('\n');
}
inline LL get_mod(LL x){
    if(x>=mod) return x-x/mod*mod;
    return x;
}
inline LL aabs(LL x){
    if(x<0) x*=-1;
    return x;
}
inline LL sq(LL x){
    x=get_mod(x);
    return get_mod(x*x);
}
inline LL Dis(node a,node b){
    return get_mod(sq(aabs(a.x-b.x))+sq(aabs(a.y-b.y)));
}
int Find(int x){return fa[x]==x?x:fa[x]=Find(fa[x]);}
int main(){
    LL n,m,x,y,t;
    n=input(),m=input();
    col.clear(); row.clear();
    for(int i=1;i<=n;i++){
        x=input(),y=input();
        row[x].insert(i),col[y].insert(i);
        fa[i]=i; p[i]=node(x,y,1);
    }
    t=input();
    LL lastans=0,d,cnt=n+1;
    while(t--){
        scanf("%s",&str);
        if(str[0]=='Q'){
            scanf("%I64d",&x);
            x^=lastans;
            x=Find(x);
            LL r=p[x].x,l=p[x].y;
            lastans=0;
            p[cnt]=node(r,l,0);
            for(it=row[r].begin();it!=row[r].end();it++){
                LL index=*it;
                col[p[index].y].erase(index);
                lastans=get_mod(Dis(p[index],p[x])*p[index].num+lastans);
                fa[index]=cnt;
                p[cnt]=node(r,l,p[index].num+p[cnt].num);
            }
            for(it=col[l].begin();it!=col[l].end();it++){
                LL index=*it;
                col[p[index].x].erase(index);
                lastans=get_mod(Dis(p[index],p[x])*p[index].num+lastans);
                fa[index]=cnt;
                p[cnt]=node(r,l,p[index].num+p[cnt].num);
            }
            row[r].clear(),col[l].clear();
            row[r].insert(cnt),col[l].insert(cnt);
            fa[cnt]=cnt++;
            output(lastans);
        }
        else{
            x=input(),d=input();
            x^=lastans;
            LL X=Find(x);
            p[X].num--;
            if(p[X].num==0){
                row[p[X].x].erase(X);
                col[p[X].y].erase(X);
            }
            LL xx=p[X].x,yy=p[X].y;
            if(str[0]=='U'){
                xx-=d;
            }
            else if(str[0]=='D'){
                xx+=d;
            }
            else if(str[0]=='L'){
                yy-=d;
            }
            else if(str[0]=='R'){
                yy+=d;
            }
            row[xx].insert(x);
            col[yy].insert(x);
            p[x]=node(xx,yy,1);
            fa[x]=x;
        }
    }
    return 0;
}
