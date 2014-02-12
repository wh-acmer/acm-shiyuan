/*
    water
*/
#include cstring
#include cstdio
#include iostream
#include cmath
#include algorithm
using namespace std;
int n;
const int maxn = 1010;
int v1[maxn][maxn],v2[maxn][maxn];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int main()
{
    while(scanf(%d,&n)!=EOF,n)
    {
        memset(v1,0,sizeof(v1));
        memset(v2,0,sizeof(v2));
        int dx,dy,tx,ty,did,dit;
        scanf(%d%d%d,&dx,&dy,&did);
        v1[dx][dy]=1;
        scanf(%d%d%d,&tx,&ty,&dit);
        v2[tx][ty]=1;
        bool dd=true,tt=true;
        if(dx==tx && dy==ty)
        {
            printf(%d %dn,dx,dy);
            continue;
        }
        while(1)
        {
            int check=0;
            if(dd)
            {
                while(v1[dx+dir[did][0]][dy+dir[did][1]]==1  dx+dir[did][0]0  dx+dir[did][0]=n  dy+dir[did][1]=n  dy+dir[did][1]0)
                {
                    did=(did+1)%4;
                    check++;
                    if(check=2)
                        break;
                }
                if(check=2)
                {
                    dd=0;
                }
                else
                {
                    dx+=dir[did][0];
                    dy+=dir[did][1];
                    v1[dx][dy]=1;
                }
            }
            if(tt)
            {
                check=0;
                while(v2[tx+dir[dit][0]][ty+dir[dit][1]]==1  tx+dir[dit][0]0  tx+dir[dit][0]=n  ty+dir[dit][1]=n  ty+dir[dit][1]0)
                {
                    dit=(dit+3)%4;
                    check++;
                    if(check=2)
                        break;
                }
                if(check=2)
                {
                    tt=0;
                }
                else
                {
                    tx+=dir[dit][0];
                    ty+=dir[dit][1];
                    v2[tx][ty]=1;
                }
            }
            if(dx==tx && dy==ty)
                break;
            if(tt==0 && dd==0)
                break;
        }
        if(dx==tx && dy==ty)
            printf(%d %dn,dx,dy);
        else
            printf(-1n);
    }
    return 0;
}
