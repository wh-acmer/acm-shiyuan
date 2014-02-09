/*
    Ä£Äâ
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;
int dir[8][2]={1,0,1,1,0,1,-1,1,-1,0,-1,-1,0,-1,1,-1};
int move[8][2]={2,1,1,2,-1,2,-2,1,-1,-2,-2,-1,1,-2,2,-1};
char s[9][9];
int cas=0;
int main()
{
    while(1)
    {
        int ans=0;
        for(int i=0;i<8;i++)
        {
            gets(s[i]);
            for(int j=0;j<8;j++)
                if(s[i][j]=='.')
                    ans++;
        }
        if(ans==64)
            break;
        int ctag=0;
        for(int i=0;i<8;i++)
            for(int j=0;j<8;j++)
            {
                if(s[i][j]=='.')
                    ;
                else if(s[i][j]=='b')
                {
                    bool t_left=1,t_right=1;
                    // down
                    for(int k=1;;k++)
                    {
                        if(i+k<8)
                        {
                            if(t_left&&j-k>=0)
                            {
                                if(s[i+k][j-k]=='K')
                                {
                                    ctag=1;/// black win
                                    break;
                                }
                                else if(s[i+k][j-k]!='.')
                                {
                                    t_left=0;
                                }
                            }
                        }
                        else
                            break;
                    }
                    for(int k=1;;k++)
                    {
                        if(i+k<8)
                        {
                            if(t_right&&j+k<8)
                            {
                                if(s[i+k][j+k]=='K')
                                {
                                    ctag=1; /// black win
                                    break;
                                }
                                else if(s[i+k][j+k]!='.')
                                {
                                    t_right=0;
                                }
                            }
                        }
                        else
                            break;
                    }
                    // up
                    t_right=1,t_left=1;
                    for(int k=1;;k++)
                    {
                        if(i-k>=0)
                        {
                            if(t_left&&j-k>=0)
                            {
                                if(s[i-k][j-k]=='K')
                                {
                                    ctag=1;/// black win
                                    break;
                                }
                                else if(s[i-k][j-k]!='.')
                                {
                                    t_left=0;
                                }
                            }
                        }
                        else
                            break;
                    }
                    for(int k=1;;k++)
                    {
                        if(i-k>=0)
                        {
                            if(t_right&&j+k<8)
                            {
                                if(s[i-k][j+k]=='K')
                                {
                                    ctag=1; /// black win
                                    break;
                                }
                                else if(s[i-k][j+k]!='.')
                                {
                                    t_right=0;
                                }
                            }
                        }
                        else
                            break;
                    }
                }
                else if(s[i][j]=='B')
                {
                    bool t_left=1,t_right=1;
                    // down
                    for(int k=1;;k++)
                    {
                        if(i+k<8)
                        {
                            if(t_left&&j-k>=0)
                            {
                                if(s[i+k][j-k]=='k')
                                {
                                    ctag=-1;/// white win
                                    break;
                                }
                                else if(s[i+k][j-k]!='.')
                                {
                                    t_left=0;
                                }
                            }
                        }
                        else
                            break;
                    }
                    for(int k=1;;k++)
                    {
                        if(i+k<8)
                        {
                            if(t_right&&j+k<8)
                            {
                                if(s[i+k][j+k]=='k')
                                {
                                    ctag=-1; /// white win
                                    break;
                                }
                                else if(s[i+k][j+k]!='.')
                                {
                                    t_right=0;
                                }
                            }
                        }
                        else
                            break;
                    }
                    // up
                    t_right=1,t_left=1;
                    for(int k=1;;k++)
                    {
                        if(i-k>=0)
                        {
                            if(t_left&&j-k>=0)
                            {
                                if(s[i-k][j-k]=='k')
                                {
                                    ctag=-1;/// white win
                                    break;
                                }
                                else if(s[i-k][j-k]!='.')
                                {
                                    t_left=0;
                                }
                            }
                        }
                        else
                            break;
                    }
                    for(int k=1;;k++)
                    {
                        if(i-k>=0)
                        {
                            if(t_right&&j+k<8)
                            {
                                if(s[i-k][j+k]=='k')
                                {
                                    ctag=-1; /// white win
                                    break;
                                }
                                else if(s[i-k][j+k]!='.')
                                {
                                    t_right=0;
                                }
                            }
                        }
                        else
                            break;
                    }
                }
                else if(s[i][j]=='R')
                {
                    bool right=1,up=1,down=1,left=1;
                    for(int k=1;;k++)
                    {
                        if(right&&j+k<8)
                        {
                            if(s[i][j+k]=='k')
                            {
                                ctag=-1;
                                break;
                            }
                            else if(s[i][j+k]!='.')
                            {
                                right=0;
                            }
                        }
                        else
                            break;
                    }
                    for(int k=1;;k++)
                    {
                        if(left&&j-k>=0)
                        {
                            if(s[i][j-k]=='k')
                            {
                                ctag=-1;
                                break;
                            }
                            else if(s[i][j-k]!='.')
                            {
                                left=0;
                            }
                        }
                        else
                            break;
                    }
                    for(int k=1;;k++)
                    {
                        if(up&&i-k>=0)
                        {
                            if(s[i-k][j]=='k')
                            {
                                ctag=-1;
                                break;
                            }
                            else if(s[i-k][j]!='.')
                            {
                                up=0;
                            }
                        }
                        else
                            break;
                    }
                    for(int k=1;;k++)
                    {
                        if(down&&i+k<8)
                        {
                            if(s[i+k][j]=='k')
                            {
                                ctag=-1;
                                break;
                            }
                            else if(s[i+k][j]!='.')
                            {
                                down=0;
                            }
                        }
                        else
                            break;
                    }
                }
                else if(s[i][j]=='r')
                {
                    bool right=1,up=1,down=1,left=1;
                    for(int k=1;;k++)
                    {
                        if(right&&j+k<8)
                        {
                            if(s[i][j+k]=='K')
                            {
                                ctag=1;
                                break;
                            }
                            else if(s[i][j+k]!='.')
                            {
                                right=0;
                            }
                        }
                        else
                            break;
                    }
                    for(int k=1;;k++)
                    {
                        if(left&&j-k>=0)
                        {
                            if(s[i][j-k]=='K')
                            {
                                ctag=1;
                                break;
                            }
                            else if(s[i][j-k]!='.')
                            {
                                left=0;
                            }
                        }
                        else
                            break;
                    }
                    for(int k=1;;k++)
                    {
                        if(up&&i-k>=0)
                        {
                            if(s[i-k][j]=='K')
                            {
                                ctag=1;
                                break;
                            }
                            else if(s[i-k][j]!='.')
                            {
                                up=0;
                            }
                        }
                        else
                            break;
                    }
                    for(int k=1;;k++)
                    {
                        if(down&&i+k<8)
                        {
                            if(s[i+k][j]=='K')
                            {
                                ctag=1;
                                break;
                            }
                            else if(s[i+k][j]!='.')
                            {
                                down=0;
                            }
                        }
                        else
                            break;
                    }
                }
                else if(s[i][j]=='p')
                {
                    if(i+1<8)
                    {
                        if(j+1<8)
                        {
                            if(s[i+1][j+1]=='K')
                            {
                                ctag=1;
                            }
                        }
                        if(j-1>=0)
                        {
                            if(s[i+1][j-1]=='K')
                            {
                                ctag=1;
                            }
                        }
                    }
                }
                else if(s[i][j]=='P')
                {
                    if(i-1>=0)
                    {
                        if(j+1<8)
                        {
                            if(s[i-1][j+1]=='k')
                            {
                                ctag=-1;
                            }
                        }
                        if(j-1>=0)
                        {
                            if(s[i-1][j-1]=='k')
                            {
                                ctag=-1;
                            }
                        }
                    }
                }
                else if(s[i][j]=='k')
                {
                    for(int c=0;c<8;c++)
                    {
                        int xx=i+dir[c][0];
                        int yy=j+dir[c][1];
                        if(xx>=0&&xx<8&&yy>=0&&yy<8)
                        {
                            if(s[xx][yy]=='K')
                            {
                                ctag=1;
                            }
                        }
                    }
                }
                else if(s[i][j]=='K')
                {
                    for(int c=0;c<8;c++)
                    {
                        int xx=i+dir[c][0];
                        int yy=j+dir[c][0];
                        if(xx>=0&&xx<8&&yy>=0&&yy<8)
                        {
                            if(s[xx][yy]=='k')
                            {
                                ctag=-1;
                            }
                        }
                    }
                }
                else if(s[i][j]=='N')
                {
                    for(int c=0;c<8;c++)
                    {
                        int xx=i+move[c][0];
                        int yy=j+move[c][1];
                        if(xx>=0&&xx<8&&yy>=0&&yy<8)
                        {
                            if(s[xx][yy]=='k')
                            {
                                ctag=-1;
                            }
                        }
                    }
                }
                else if(s[i][j]=='n')
                {
                    for(int c=0;c<8;c++)
                    {
                        int xx=i+move[c][0];
                        int yy=j+move[c][1];
                        if(xx>=0&&xx<8&&yy>=0&&yy<8)
                        {
                            if(s[xx][yy]=='K')
                            {
                                ctag=1;
                            }
                        }
                    }
                }
                else if(s[i][j]=='q')
                {
                    for(int c=0;c<8;c++)
                    {
                        for(int k=1;;k++)
                        {
                            int xx=i+dir[c][0]*k;
                            int yy=j+dir[c][1]*k;
                            if(xx>=0&&xx<8&&yy>=0&&yy<8)
                            {
                                if(s[xx][yy]=='K')
                                {
                                    ctag=1;
                                    break;
                                }
                                else if(s[xx][yy]!='.')
                                    break;
                            }
                            else
                                break;
                        }
                    }
                }
                else if(s[i][j]=='Q')
                {
                    for(int c=0;c<8;c++)
                    {
                        for(int k=1;;k++)
                        {
                            int xx=i+dir[c][0]*k;
                            int yy=j+dir[c][1]*k;
                            if(xx>=0&&xx<8&&yy>=0&&yy<8)
                            {
                                if(s[xx][yy]=='k')
                                {
                                    ctag=-1;
                                    break;
                                }
                                else if(s[xx][yy]!='.')
                                    break;
                            }
                            else
                                break;
                        }
                    }
                }
                //printf("%c",s[i][j]);
            }

        printf("Game #%d: ",++cas);
        if(ctag==-1)
            printf("black king is in check.\n");
        else if(ctag==1)
            printf("white king is in check.\n");
        else
            printf("no king is in check.\n");
        getchar();
    }
    return 0;
}
