/*
    题意：求四连通块中的最大值
    思路：并查集
*/
#include <stdio.h>
#include <string.h>
#define maxn 1000010
int pre[maxn],m,n,num[maxn];
char str[10];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
inline int input()
{
    int ret=0;bool IsN=0;char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') IsN=1;c=getchar();}
    while(c>='0'&&c<='9') ret=ret*10+c-'0',c=getchar();
    return IsN?-ret:ret;
}
inline int find(int x){
    if(x!=pre[x]){
        pre[x]=find(pre[x]);
    }
    return pre[x];
}
bool in(int x,int y){
    return x<=n && y<=n && x>=1 && y>=1 ;
}
int get_num(int x,int y){
    return num[find(x*n-n+y)];
}
void solve(int x,int y,int z){
    int xx,yy;
    int mx=z,tmp;
    int par=x*n-n+y;
    for(int i=0;i<4;i++){
        xx=x+dx[i];
        yy=y+dy[i];
        if(in(xx,yy) && num[xx*n-n+yy]){
            tmp=find(xx*n-n+yy);
            if(num[tmp]>mx){
                mx=num[tmp];
                par=tmp;
            }
        }
    }
    pre[x*n-n+y]=par;
    for(int i=0;i<4;i++){
        xx=x+dx[i];
        yy=y+dy[i];
        if(in(xx,yy) && num[xx*n-n+yy]){
            tmp=find(xx*n-n+yy);
            if(num[tmp]<=mx){
                pre[tmp]=par;
            }
        }
    }
}
int main(){
    int T,x,y,z;
    T=input();
    while(T--){
        n=input();
        m=input();
        //(i-1)*n+j
        for(int i=1;i<=n*n;i++) pre[i]=i;
        memset(num,0,sizeof(num));
        while(m--){
            scanf("%s",&str);
            if(str[0]=='C'){
                x=input();
                y=input();
                z=input();
                num[(x-1)*n+y]=z;
                solve(x,y,z);
            }
            else{
                x=input();
                y=input();
                if(num[x*n-n+y]==0) printf("-1\n");
                else{
                    printf("%d\n",get_num(x,y));
                }
            }
        }
    }
    return 0;
}
