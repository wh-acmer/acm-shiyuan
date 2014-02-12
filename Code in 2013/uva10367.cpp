/*
    模拟
*/
#include <cstdio>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int x,y,c;
long long gcd(long long a,long long b)
{
    if(a<0)
        a*=(-1);
    if(b<0)
        b*=(-1);
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
void solve()
{
    char s[100000];
    bool vis[100000];
    int tag=1;///从左边读入，左边为正
    gets(s);
    int l=strlen(s);
    x=0,y=0,c=0;///分别表示x,y的系数和常量
    for(int i=0;i<l;i++)
        if(s[i]==' ')
            vis[i]=1;
        else
            vis[i]=0;
    int flag=0;
    for(int i=0;i<l;i++)
    {
        if(i==0||vis[i])
        {
            if(i!=0) /// 开始的时候从s[0]开始,不然从空格的下一位开始
                i++;
            if(s[i]=='+')
            {
                if(flag==0)
                    tag=1;
                else
                    tag=-1;
            }
            else if(s[i]=='-'&&i!=0&&s[i+1]==' ')
            {
                if(flag==0)
                    tag=-1;
                else
                    tag=1;
            }
            else if(s[i]=='x')
                x+=tag;
            else if(s[i]=='y')
            {
                y+=tag;
            }
            else if(s[i]=='=')
            {
                flag=1;
                tag=-1;
            }
            else
            {
                int num=0;
                int pnt=1;
                int tnt=1;
                if(s[i]=='-')
                {
                    tnt=-1;
                    if(s[i+1]=='x')
                        x+=tag*tnt;
                    else if(s[i+1]=='y')
                        y+=tag*tnt;
                    else if(s[i+1]-'0'>=0&&s[i+1]-'0'<=9)
                    {
                        int num=0;
                        int pnt=10;
                        int miao;
                        for(int now=i+1;;now++)
                        {
                            if(s[now]=='x')
                            {
                                miao=1;
                                break;
                            }
                            else if(s[now]=='y')
                            {
                                miao=2;
                                break;
                            }
                            else if(s[now]==' ')
                            {
                                miao=0;
                                break;
                            }
                            num=num*pnt+s[now]-'0';
                            if(now==l-1)
                            {
                                miao=0;
                                break;
                            }
                        }
                        if(miao==1)
                            x+=tag*tnt*num;
                        else if(miao==2)
                            y+=tag*tnt*num;
                        else if(miao==0)
                            c+=tag*tnt*num;
                    }
                }
                else
                {
                    tnt=1;
                    if(s[i]=='x')
                        x+=tag*tnt;
                    else if(s[i]=='y')
                        y+=tag*tnt;
                    else if(s[i]-'0'>=0&&s[i]-'0'<=9)
                    {
                        int num=0;
                        int pnt=10;
                        int miao;
                        for(int now=i;;now++)
                        {
                            if(s[now]=='x')
                            {
                                miao=1;
                                break;
                            }
                            if(s[now]=='y')
                            {
                                miao=2;
                                break;
                            }
                            if(s[now]==' ')
                            {
                                miao=0;
                                break;
                            }
                            //printf("num=%d...s[now]=%c...pnt=%d\n",num,s[now],pnt);
                            num=num*pnt+s[now]-'0';
                            if(now==l-1)
                            {
                                miao=0;
                                break;
                            }
                        }
                        //printf("%d=======\n",num);
                        if(miao==1)
                            x+=tag*tnt*num;
                        else if(miao==2)
                            y+=tag*tnt*num;
                        else if(miao==0)
                            c+=tag*tnt*num;
                    }
                }
            }
        }
        else ;
    }
    //printf("fun : %d.....%d......%d\n",x,y,c);
}
int main()
{
    int T,flag=1;
    scanf("%d",&T);
    getchar();
    while(T--)
    {
        if(flag)
            flag=0;
        else
            getchar();
        long long a1,a2,b1,b2,c1,c2;
        solve();
        a1=x;
        b1=y;
        c1=c;
        solve();
        a2=x;
        b2=y;
        c2=c;
        //printf("%lld..%lld..%lld..%lld..%lld..%lld\n",a1,b1,c1,a2,b2,c2);
        int ok=1;
        if(a1==0&&b1==0&&c1!=0)
            ok=0;
        if(a2==0&&b2==0&&c2!=0)
            ok=0;
        if(ok==0)///方程组中存在不等式
        {
            //printf("没有意义\n");
            printf("don't know\n");
            printf("don't know\n");
            if(T)
                printf("\n");
            continue;
        }
        ///等式要么为一元可解，要么为二元联立可解
        long long ansx1=0,ansx2=0xfffffff,ansy1=0,ansy2=0xfffffff;
        long long x1=0,x2,y1=0,y2;
        int miao=0;
        /// miao=1 一个x可解
        /// miao=2 一个y可解
        /// miao=3 两个都有
        if(a1==0&&b1!=0)
        {
            y1=b1;///分母
            y2=-c1;///分子
            miao=2;
        }
        else if(b1==0&&a1!=0)
        {
            x1=a1;
            x2=-c1;
            miao=1;
        }
        else if(b1!=0&&a1!=0)
        {
            miao=3;
        }
        int wu=0;
        ///意义同 miao
        long long x3=0,x4,y3=0,y4;
        if(a2==0&&b2!=0)
        {
            y3=b2;///分母
            y4=-c2;///分子
            wu=2;
        }
        else if(b2==0&&a2!=0)
        {
            x3=a2;
            x4=-c2;
            wu=1;
        }
        else if(b2!=0&&a2!=0)
        {
            wu=3;
        }
        //printf("%d.....%d\n",miao,wu);
        //printf("=======================\n");

        int tagx,tagy;
        if(miao==1&&wu==1)
        {
            long long tmp=gcd(x1,x2);
            x1/=tmp;
            x2/=tmp;
            tmp=gcd(x3,x4);
            x3/=tmp;
            x4/=tmp;
            if(x1*x4==x2*x3)
            {
                ansx1=x1;
                ansx2=x2;
                tagx=1;
            }
            else
                tagx=0;
        }
        else if(miao==2&&wu==2)
        {
            long long tmp=gcd(y1,y2);
            y1/=tmp;
            y2/=tmp;
            tmp=gcd(y3,y4);
            y3/=tmp;
            y4/=tmp;
            //printf("%lld %lld %lld %lld \n",y1,y2,y3,y4);
            if(y1*y4==y2*y3)
            {
                ansy1=y1;
                ansy2=y2;
                tagy=1;
            }
            else
                tagy=0;
        }
        else if(miao==1&&wu==2)
        {
            long long tmp=gcd(x1,x2);
            ansx1=x1/tmp;
            ansx2=x2/tmp;
            tmp=gcd(y3,y4);
            ansy1=y3/tmp;
            ansy2=y4/tmp;
            tagx=1;
            tagy=1;
        }
        else if(miao==2&&wu==1)
        {
            long long tmp=gcd(y1,y2);
            ansy1=y1/tmp;
            ansy2=y2/tmp;
            tmp=gcd(x3,x4);
            ansx1=x3/tmp;
            ansx2=x4/tmp;
            tagx=1;
            tagy=1;
        }
        else if(miao==3&&wu==3)
        {
            if(a2*b1==a1*b2)
            {
                tagx=0;
                tagy=0;
            }
            else
            {
                long long tmp=a1*b2-a2*b1;
                ansx1=tmp;
                ansy1=tmp;
                ansx2=b1*c2-c1*b2;
                ansy2=a2*c1-a1*c2;
                //printf("ansx1=%lld ansx2=%lld\n",ansx1,ansx2);
                //printf("ansy1=%lld ansy2=%lld\n",ansy1,ansy2);
                tagx=1;
                tagy=1;
            }
        }
        else if(miao==3)
        {
            if(wu==1)
            {
                long long tmp=gcd(x3,x4);
                ansx1=x3/tmp;
                ansx2=x4/tmp;
                ansy1=-b1*ansx1;
                ansy2=a1*ansx2+c1*ansx1;
                tagx=tagy=1;
                //printf("%lld %lld %lld %lld \n",ansx1,ansx2,ansy1,ansy2);
            }
            if(wu==2)
            {
                long long tmp=gcd(y3,y4);
                ansy1=y3/tmp;
                ansy2=y4/tmp;
                ansx1=-a1*ansy1;
                ansx2=b1*ansy2+c1*ansy1;
                tagx=tagy=1;
            }
        }
        else if(wu==3)
        {
            if(miao==1)
            {
                long long tmp=gcd(x1,x2);
                ansx1=x1/tmp;
                ansx2=x2/tmp;
                ansy1=-b2*ansx1;
                ansy2=a2*ansx2+c2*ansx1;
                tagx=tagy=1;
            }
            else if(miao==2)
            {
                long long tmp=gcd(y1,y2);
                ansy1=y1/tmp;
                ansy2=y2/tmp;
                ansx1=-a2*ansy1;
                ansx2=b2*ansy2+c2*ansy1;
                tagx=tagy=1;
            }
        }
        if(miao==0)
        {
            if(wu==1)
            {
                long long tmp=gcd(x3,x4);
                ansx1=x3/tmp;
                ansx2=x4/tmp;
            }
            if(wu==2)
            {
                long long tmp=gcd(y3,y4);
                ansy1=y3/tmp;
                ansy2=y4/tmp;
            }
        }
        if(wu==0)
        {
            if(miao==1)
            {
                long long tmp=gcd(x1,x2);
                ansx1=x1/tmp;
                ansx2=x2/tmp;
            }
            if(miao==2)
            {
                long long tmp=gcd(y1,y2);
                ansy1=y1/tmp;
                ansy2=y2/tmp;
            }
        }
        if(tagx)
        {
            if(ansx1==0||ansx2==0xfffffff)
                printf("don't know\n");
            else
            {
                int pp=1;
                if(ansx1<0)
                    pp*=(-1);
                if(ansx2<0)
                    pp*=(-1);
                ansx1=(ansx1>0)?ansx1:(-ansx1);
                ansx2=(ansx2>0)?ansx2:(-ansx2);
                long long ggcd=gcd(ansx1,ansx2);
                ansx1/=ggcd;
                ansx2/=ggcd;
                if(ansx2%ansx1==0)
                    printf("%lld\n",ansx2/ansx1*pp);
                else
                    printf("%lld/%lld\n",ansx2*pp,ansx1);
            }
        }
        else
            printf("don't know\n");
        if(tagy)
        {
            if(ansy1==0||ansy2==0xfffffff)
                printf("don't know\n");
            else
            {
                int pp=1;
                if(ansy1<0)
                    pp*=(-1);
                if(ansy2<0)
                    pp*=(-1);
                ansy1=(ansy1>0)?ansy1:(-ansy1);
                ansy2=(ansy2>0)?ansy2:(-ansy2);
                long long ggcd=gcd(ansy1,ansy2);
                ansy1/=ggcd;
                ansy2/=ggcd;
                if(ansy2%ansy1==0)
                    printf("%lld\n",ansy2/ansy1*pp);
                else
                    printf("%lld/%lld\n",ansy2*pp,ansy1);
            }
        }
        else
            printf("don't know\n");
        if(T)
            printf("\n");
    }
    return 0;
}

/*
    网上的代码
*/
/*
// 大牛的AC代码
// 吾等只能膜拜
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

typedef long long num;

typedef struct {
    num p, q;
} frac;

frac A[2][4];

num gcd(num x, num y)
{
    if (x < 0) x = -x;
    if (y < 0) y = -y;
    return (y == 0) ? x : gcd(y, x % y);
}

char *fmt(frac f)
{
    static char s[1024];
    num d;
    if (f.q < 0) f.q = -f.q, f.p = -f.p;
    d = gcd(f.p, f.q);
    f.p /= d;
    f.q /= d;
    sprintf(s, (f.q == 1) ? "%lld" : "%lld/%lld", f.p, f.q);
    return s;
}

frac sub(frac a, frac b, frac c)
{
    frac r;
    r.p = a.p * b.q * c.q - a.q * b.p * c.p;
    r.q = a.q * b.q * c.q;
    return r;
}

void solve()
{
    int i, j, r, c;
    frac t;

    for (r = c = 0; c < 2; c++) {
        for (i = r; i < 2 && A[i][c].p == 0; i++);
        if (i == 2) continue;

        for (j = 0; j < 3; j++)
            t = A[i][j], A[i][j] = A[r][j], A[r][j] = t;

        t = A[r][c];
        for (i = c + 1; i < 3; i++)
            A[r][i].p *= t.q, A[r][i].q *= t.p;
        A[r][c].p = A[r][c].q = 1;

        for (i = 0; i < 2; i++) {
            if (i == r) continue;

            t = A[i][c];
            for (j = c + 1; j < 3; j++)
                A[i][j] = sub(A[i][j], t, A[r][j]);
            A[i][c].p = 0;
            A[i][c].q = 1;
        }

        r++;
    }

    for (i = 0; i < 2; i++)
        if (A[i][0].p == 0 && A[i][1].p == 0 && A[i][2].p != 0) break;

    if (i < 2) {
        printf("don't know\n");
        printf("don't know\n");
        return;
    }

    if (A[0][0].p == 1 && A[0][1].p == 0)
        printf("%s\n", fmt(A[0][2]));
    else
        printf("don't know\n");

    if (A[0][0].p == 1 && A[1][1].p == 1)
        printf("%s\n", fmt(A[1][2]));
    else if (A[0][0].p == 0 && A[0][1].p == 1)
        printf("%s\n", fmt(A[0][2]));
    else
        printf("don't know\n");
}

void parse(char *s, frac x[])
{
    num c, side, sign;
    int i, j;

    for (i = j = 0; s[i]; i++)
        if (strchr("+-=0123456789xy", s[i]) != NULL) s[j++] = s[i];
    s[j] = '\0';

    x[0].p = x[1].p = x[2].p = 0;
    x[0].q = x[1].q = x[2].q = 1;

    for (side = 1; *s;) {
        if (*s == '=') {
            s++;
            side = -side;
            continue;
        }

        for (sign = 1; *s == '+' || *s == '-'; s++)
            if (*s == '-') sign = -sign;

        assert(*s != '\0');

        if (isdigit(*s)) {
            for (c = 0; *s && isdigit(*s); s++)
                c = c * 10 + (*s - '0');
            c *= sign;

            if (*s != 'x' && *s != 'y') {
                x[2].p -= side * c;
                continue;
            }
        } else {
            c = sign;
        }

        assert(*s == 'x' || *s == 'y');

        if (*s == 'x')
            x[0].p += side * c;
        else if (*s == 'y')
            x[1].p += side * c;
        s++;
    }
}

int main()
{
    char s[1024];
    int t;

    while (gets(s) && sscanf(s, "%d", &t) != 1);

    while (t-- > 0) {
        gets(s);
        parse(s, A[0]);

        gets(s);
        parse(s, A[1]);

        gets(s);

        solve();

        if (t) printf("\n");
    }

    return 0;
}
*/
