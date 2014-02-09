/*
    water
�������ֽ⣬Ȼ��ʽ��n1+n2+n3+....��! /  (n1!  * n2! * ... )
��ʼ��ʱ����Ϊ����Ĳ��ֻᳬ long long ���Ըĳɶ���Щ���ֽ�����һ�ηֽ⡣������ʾ��ȫû��Ҫ������
ע����������Ӵ���1000����������ʱ�����õ�һ��������Ӱ��
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
#define maxn 1010
int prime[maxn];
int cnt[maxn];
int pnt[maxn];
bool vis[maxn];
int n_prime=0;
void Prime()
{
    memset(vis,true,sizeof(vis));
    vis[0]=vis[1]=0;
    for(int i=2;i<maxn;i++)
    {
        if(vis[i])
        {
            prime[++n_prime]=i;
            for(int j=2*i;j<maxn;j+=i)
                vis[j]=0;
        }
    }
}
int get(int n,int p)
{
    int tmp=p;
    int sum=0;
    while(tmp<=n)
    {
        sum+=n/tmp;
        tmp*=p;
    }
    return sum;
}
int main()
{
    Prime();
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n_prime;i++)
        {
            if(n<prime[i])
                break;
            if(n%prime[i]==0)
            {
                while(n%prime[i]==0)
                {
                    n/=prime[i];
                    cnt[i]++;
                }
            }
        }
        int ccnt=0;
        if(n!=1) // ���ڴ���1000��������
        {
            cnt[0]=1;
            ccnt=n;
        }
        int ans=0;
        for(int i=0;i<=n_prime;i++)
            ans+=cnt[i];
        printf("%d ",ans);
        memset(pnt,0,sizeof(pnt));
        for(int i=1;i<=n_prime;i++)
        {
            if(ans<prime[i])
                break;
            pnt[i]+=get(ans,prime[i]);
        }
        for(int i=1;i<=n_prime;i++)
        {
            for(int j=1;j<=n_prime;j++)
            {
                if(cnt[i]<prime[j])
                    break;
                pnt[j]-=get(cnt[i],prime[j]);
            }
        }
        long long answer=1;
        for(int i=1;i<=n_prime;i++)
        {
            if(pnt[i])
            {
                for(int j=1;j<=pnt[i];j++)
                    answer*=prime[i];
            }
        }
        printf("%I64d\n",answer);
    }
    return 0;
}
