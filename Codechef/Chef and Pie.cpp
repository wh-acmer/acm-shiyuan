#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define maxn 2010
int a[maxn];
int ans;
struct Tree{
    int num;
    Tree *son[2];
    Tree(){
        num=0;
        son[0]=NULL;
        son[1]=NULL;
    }
    ~Tree(){
        num=0;
        son[0]=NULL;
        son[1]=NULL;
    }
};
Tree *tree;
int n;
void insert(Tree *nod,int x,int bit,int index){
    if(bit==-1){
        nod->num=index;
        return ;
    }
    bool now=(x&(1<<bit));
    if(nod->son[now]==0)
        nod->son[now]=new Tree;
    insert(nod->son[now],x,bit-1,index);
}
void query(int x,int p,int q){
    Tree *nod=tree;
    for(int i=31;i>=0;i--){
        bool now=x&(1<<i);
        if(nod->son[now^1]) nod=nod->son[now^1];
        else nod=nod->son[now];
    }
    if((x^a[nod->num])>ans && nod->num!=p && nod->num!=q && nod->num){
        ans=x^a[nod->num];
    }
}
void dest(Tree *&nod){
    if(nod->son[0])
        dest(nod->son[0]);
    if(nod->son[1])
        dest(nod->son[1]);
    delete nod;
}
void solve(){
    insert(tree,0,31,0);
    for(int i=1;i<=n;i++)
        insert(tree,a[i],31,i);
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
            query(a[i]^a[j],i,j);
}
int brute(){
    int pika=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            for(int k=j+1;k<=n;k++){
                pika=max(pika,a[i]^a[j]^a[k]);
                //cout<<(a[i]^a[j]^a[k])<<endl;
            }
    return pika;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        ans=0;
        sort(a+1,a+n+1);
        if(n<=100){ // 这个去掉会Wa?真尼玛奇葩，还是说代码写的有问题？
            printf("%d\n",brute());
            continue;
        }
        tree=new Tree;
        solve();
        printf("%d\n",ans);
        dest(tree);
    }
    return 0;
}
