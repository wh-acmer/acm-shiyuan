/*
    题意：划分树
    思路：划分树
*/
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define INF 0x3fffffff
#define N 100010
int sa[N],tree[20][N],sum[20][N];
//sum[i][j]表示i层，1～j里比sa[m]小的数
int n,m,t,x,y,k;
struct node
{
    int l,r;
}root[N*4];
inline int input()
{
    int ret=0;bool IsN=0;char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') IsN=1;c=getchar();}
    while(c>='0'&&c<='9') ret=ret*10+c-'0',c=getchar();
    return IsN?-ret:ret;
}
inline void build(int t,int d,int x,int y)
{
    root[t].l=x;
    root[t].r=y;
    if(x==y) return;
    int m=(x+y)>>1;
    int lless=m-x+1;
    for(int i=x;i<=y;i++)
    {
        if(tree[d][i]<sa[m]) lless--;
    }
    int lp=x,rp=m+1;
    for(int i=x;i<=y;i++)
    {
        if(i==x) sum[d][i]=0;
        else     sum[d][i]=sum[d][i-1];
        if(tree[d][i]<sa[m])
        {
            sum[d][i]++;
            tree[d+1][lp++]=tree[d][i];
        }
        else if(tree[d][i]>sa[m])
        {
            tree[d+1][rp++]=tree[d][i];
        }
        else
        {
            if(lless>0)
            {
                sum[d][i]++;
                lless--;
                tree[d+1][lp++]=tree[d][i];
            }
            else
            {
                tree[d+1][rp++]=tree[d][i];
            }
        }
    }
    build(t*2,d+1,x,m);
    build(t*2+1,d+1,m+1,y);
}

inline int query(int t,int d,int x,int y,int k)
{
    if(x==y) return tree[d][x];
    int ss,s;
    int l=root[t].l,r=root[t].r,m=(l+r)>>1;
    //ss：[l,x)之间被分到左子树的，s：[x,y]被分到左子树的
    if(l==x)
    {
        ss=0;
        s=sum[d][y];
    }
    else
    {
        ss=sum[d][x-1];
        s=sum[d][y]-sum[d][x-1];
    }
    if(s>=k)
    {
        int xx=l+ss;//既然[x,y]的就够了，[l,x-1]就不用了里的ss个就没用了。
        int yy=l+ss+s-1;//将下一次的s减1
        return query(t*2,d+1,xx,yy,k);
    }
    else
    {
        int r1=x-l-ss;//[l,x-1]之间被分到右子树
        int r2=y-x+1-s;//[x,y]之间被分到右子树
        int xx=m+1 +r1;
        int yy=m+1 +r1+r2-1;
        return query(t*2+1,d+1,xx,yy,k-s);
    }
}

int main()
{
    t=input();
    while(t--)
    {
        n=input();
        m=input();
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=n;i++)
        {
            sa[i]=input();
            tree[0][i]=sa[i];
        }
        sort(sa+1,sa+n+1);
        build(1,0,1,n);
        for(int i=1;i<=m;i++)
        {
            x=input();
            y=input();
            k=input();
            int left=1,right=y-x+1,mid,ans=-INF;
	    while(left<=right){
                mid=(left+right)>>1;
                int tmp=query(1,0,x,y,mid);
                if(tmp<=k){
                    left=mid+1;
                }
                else{
                    ans=tmp;
                    right=mid-1;
                }
			}
	   if(ans>k) printf("%d\n",ans);
	   else printf("not exist\n");
        }
    }
    return 0;
}
