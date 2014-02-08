/*
    Wa的代码

    正解当然是 按 向量分类之后，按x排序，然后扫一遍

    我和小建建差不多Wa了不下30次  这题过不了 也没办法

    思路应该没问题的
*/

/*  my wa code
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#include <cstdio>
using namespace std;
#define eps 1e-6
#define maxn 100001
typedef pair<int,int> P;
struct point{
    int x,y;
};
struct seg{
    point st,ed;
}p[maxn];
bool cmp(seg a,seg b){
    if(a.st.x==b.st.x){
        if(a.st.x==a.ed.x){
            if(a.st.y==b.st.y) return a.ed.y<b.ed.y;
            return a.st.y<b.st.y;
        }
        return a.ed.x>b.ed.x;
    }
    return a.st.x<b.st.x;
}
map<pair<P,int> ,vector<seg> >mp;
int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
void print(vector<seg> se){
    for(int i=0;i<se.size();i++){
        printf("%d %d %d %d\n",se[i].st.x,se[i].st.y,se[i].ed.x,se[i].ed.y);
    }
}
bool in(int x,seg s){
    return x>s.st.x;
}
inline bool inter(seg j,seg i)
{
    if(j.ed.y<j.st.y)
    {
        if(i.st.x==j.ed.x&&i.st.y==j.ed.y) return 0;
        else if(i.st.x<=j.ed.x&&i.st.y>=j.ed.y) return 1;
        return 0;
    }
    else
    {
        if(i.st.x==j.ed.x&&i.st.y==j.ed.y) return 0;
        else if(i.st.x<=j.ed.x&&i.st.y<=j.ed.y) return 1;
        return 0;
    }
}
int main(){
    int T;
    int cas=0;
    scanf("%d",&T);
    while(T--){
        mp.clear();
        int n;
        scanf("%d",&n);
        seg s;
        int a,b;
        for(int i=0;i<n;i++){
            scanf("%d%d%d%d",&s.st.x,&s.st.y,&s.ed.x,&s.ed.y);
            if(s.st.x>s.ed.x) swap(s.st.x,s.ed.x),swap(s.st.y,s.ed.y);
            if(s.st.x==s.ed.x && s.st.y>s.ed.y) swap(s.st.y,s.ed.y);
            b=s.ed.x-s.st.x;
            a=s.ed.y-s.st.y;
            a*=-1;
            int tmp=gcd(a,b);
            a/=tmp,b/=tmp;
            int an=1;
            if(b<0) b*=-1,a*=-1,an=-1;
            int c ;
            if(a==0){
                //b,c
                b=1;
                c=s.st.y;
            }
            else if(b==0){
                a=1;
                c=s.st.x;

            }
            else{
                c = s.st.y*b + s.st.x*a;
            }
            c*=an;
            pair<P,int>tp;
            tp.first=P(a,b);
            tp.second=c;
            mp[tp].push_back(s);
        }
        map<pair<P,int> ,vector<seg> >::iterator it=mp.begin();
        int ans=0;
        for(it=mp.begin();it!=mp.end();it++){
            vector<seg>v;
            v.assign((it->second).begin(),(it->second).end());
            sort(v.begin(),v.end(),cmp);
            for(int i=0;i+1<v.size();i++){
                int l=i+1,r=v.size()-1,mid;
                int ha=0;
                while(l<=r){
                    mid=(l+r)>>1;
                    if(inter(v[i],v[mid])){
                       ha=mid;
                       l=mid+1;
                    }
                    else{
                        r=mid-1;
                    }
                }
                if(ha)  ans+=ha-i;
            }
        }
        printf("Case %d: %d\n",++cas,ans);
    }
    return 0;
}
*/

/* 小建建的wa代码 */
#include <stdio.h>
#include <string.h>
#include <vector>
#include <math.h>
#include <algorithm>
#include <map>
using namespace std;

inline int input(){
    int ret=0;
    bool isn=0;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') isn=1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        ret=ret*10+c-'0';
        c=getchar();
    }
    return isn?-ret:ret;
}

#define N 100010
#define abs(x) x>0?x:-x
typedef long long ll;

struct ii{
    int x,y;
    double z;
    void init(int _x,int _y,double _z){
        x=_x,y=_y,z=_z;
    }
    bool operator < (const ii &a) const{
        return x<a.x || (x==a.x && y<a.y) || (x==a.x && y==a.y && z<a.z);
    }
};

inline int gcd(int a,int b){
    if(!a) return b;
    if(!b) return a;
    return gcd(b,a%b);
}
struct Point{
    int x,y;
    //   Point(int _x,int _y):x(_x),y(_y){}
    void init(int _x,int _y){
        x=_x,y=_y;
    }
};

bool operator == (Point a,Point b){
    return a.x==b.x && a.y==b.y;
}
inline ll dis(Point a,Point b){
    return (a.x*1LL-b.x*1LL)*1LL*(a.x*1LL-b.x*1LL)+(a.y*1LL-b.y*1LL)*1LL*(a.y-b.y)*1LL;
}
struct Line{
    Point s,t;
    ii k;
    void init(int _x1,int _y1,int _x2,int _y2){
        int x=_x2-_x1,y=_y2-_y1;
        double z;
        int g=gcd(abs(x),abs(y));
        x/=g,y/=g;
        if(x==0) y=_x1,x=0,z=0;
        else if(y==0) x=_y1,y=0,z=0;

        if(x!=0 && y!=0){
            z=atan2(_y1*1.0,_x1*1.0);
        }
        s.init(_x1,_y1),t.init(_x2,_y2),k.init(x,y,z);
    }
    void print(){
        printf("%d %d %d %d\n",s.x,s.y,t.x,t.y);
    }
};

ll ans;
int t,n,x1,x2,yy,y2,cnt=0;
vector<Line>s[N];
map<ii,int>m;

inline bool cmp(Line a,Line b){
    if(a.s.x==b.s.x){
        if(a.s.y==b.s.y){
            if(a.t.x==b.t.x){
                return a.t.y<b.t.y;
            }
            return a.t.x<b.t.x;
        }
        return a.s.y<b.s.y;
    }
    return a.s.x<b.s.x;
}
/*
inline bool cover(Line i,Line j){
    if(i.s==j.s && i.t==j.t) return 1;
    if(i.s==j.t && i.t==j.s) return 1;
    if(i.s==j.s || i.t==j.s) return 0;
    if(i.s==j.t || i.t==j.t) return 0;
    if(dis(i.s,i.t)+dis(j.s,j.t) > dis(i.t,j.s)) return 1;
    return 0;
    }*/

inline bool cover(Line i,Line j){
    if(j.t.y<j.s.y){
        if(i.s == j.t) return 0;
        else if(i.s.x<=j.t.x && i.s.y>=j.t.y) return 1;
        return 0;
    }
    else{
        if(i.s == j.t) return 0;
        else if(i.s.x<=j.t.x && i.s.y<=j.t.y) return 1;
        return 0;
    }
}
int main(){
//   freopen("in","r",stdin);
    t=input();
    for(int ca=0;ca<t;ca++){
        ans=0;
        m.clear();
        for(int i=0;i<=cnt;i++){
            s[i].clear();
        }
        cnt=0;
        n=input();
        for(int i=0;i<n;i++){
            x1=input(),yy=input(),x2=input(),y2=input();
            if(x1>x2) swap(x1,x2),swap(yy,y2);
            else if(x1==x2 && yy>y2) swap(yy,y2);
            Line b;
            b.init(x1,yy,x2,y2);
            if(!m[b.k]) m[b.k]=(++cnt),s[cnt].push_back(b);
            else  s[m[b.k]].push_back(b);
        }
        for(int i=1;i<=cnt;i++) sort(s[i].begin(),s[i].end(),cmp);
        for(int i=1;i<=cnt;i++){
            /*   for(int j=0;j<s[i].size();j++){
                s[i][j].print();
                }*/
            for(int j=0;j<s[i].size();j++){
                int a=j+1,b=s[i].size()-1,tag=j;
                while(a<=b){
                    int mid=(a+b)>>1;
                    if(cover(s[i][mid],s[i][j])) tag=mid,a=mid+1;
                    else b=mid-1;
                }
                //                   printf("%d %d z\n",tag,j);
                ans+=tag*1LL-j*1LL;
            }
        }
        printf("Case %d: %lld\n",ca+1,ans);
    }
    return 0;
}
