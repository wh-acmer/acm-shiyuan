#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;
#define maxn 35
int m[maxn][maxn];
int a[4][2];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int row,col;
        scanf("%d%d",&row,&col);
        for(int i=1;i<=row;i++){
            for(int j=1;j<=col;j++)
                scanf("%d",&m[i][j]);
        }
        int q;
        scanf("%d",&q);
        int x,y;
        int ans=0;
        int sb[4][2];
        while(q--){
            scanf("%d%d",&x,&y);
            if(m[x][y]==0){
                sb[0][0]=x;
                sb[0][1]=y-1;
                sb[2][0]=x;
                sb[2][1]=y+1;
                sb[3][0]=x-1;
                sb[3][1]=y;
                sb[1][0]=x+1;
                sb[1][1]=y;
                while(m[sb[0][0]][sb[0][1]]==0 && sb[0][1]>=0)
                    sb[0][1]--;
                while(m[sb[2][0]][sb[2][1]]==0 && sb[2][1]<=col)
                    sb[2][1]++;
                while(m[sb[3][0]][sb[3][1]]==0 && sb[3][0]>=0)
                    sb[3][0]--;
                while(m[sb[1][0]][sb[1][1]]==0 && sb[1][0]<=row)
                    sb[1][0]++;
                /*for(int i=0;i<4;i++)
                    cout<<sb[i][0]<<":"<<sb[i][1]<<endl;*/
                bool ok[4];
                bool l[4];
                memset(ok,false,sizeof(ok));
                memset(l,false,sizeof(l));
                if(sb[0][1]>=1)   l[0]=true;
                if(sb[2][1]<=col)  l[2]=true;
                if(sb[3][0]>=1)    l[3]=true;
                if(sb[1][0]<=row)  l[1]=true;
                for(int i=0;i<4;i++){
                    if(l[i]){
                        for(int j=0;j<4;j++){
                            if(i==j || l[j]==0)    continue;
                            if(m[sb[i][0]][sb[i][1]]==m[sb[j][0]][sb[j][1]])
                                ok[i]=true,ok[j]=true;
                        }
                    }
                }
                for(int i=0;i<4;i++){
                    if(ok[i]){
                        m[sb[i][0]][sb[i][1]]=0;
                        ans++;
                    }
                }
                /*for(int i=1;i<=row;i++){
                    for(int j=1;j<=col;j++)
                        cout<<m[i][j]<<" ";
                    cout<<endl;
                }*/

            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
