#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
#define maxn 80010
vector<long long>prime;
int add[maxn];
int multi[maxn];
bool vis[maxn];
bool sq(int x)
{
    int sqr=(int)sqrt(x+0.0);
    return sqr*sqr==x ;
}
void init()
{
    memset(add,0,sizeof(add));
    memset(multi,0,sizeof(multi));
    prime.clear();
    memset(vis,true,sizeof(vis));
    vis[0]=vis[1];
    for(int i=2;i<maxn;i++)
        if(vis[i])
        {
            prime.push_back(i);
            for(int j=2*i;j<maxn;j+=i)
                vis[j]=false;
        }
    //printf("%d %d\n",prime.size(),prime[prime.size()-1]);
    for(int i=0;i<prime.size();i++)
        for(int j=i;j<prime.size()&&prime[i]+prime[j]<maxn;j++)
        {
            add[prime[i]+prime[j]]++;
            if(prime[i]*prime[j]<maxn)
                multi[prime[i]*prime[j]]++;
        }
}
int main()
{
    init();
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int ans=0;
        if(vis[n]) // ��һ���������
            ans++;
        ans+=add[n];
        ans+=multi[n];
        int tmp=0;
        for(int i=0;i<prime.size()&&prime[i]<n;i++)
        {
            ans+=multi[n-prime[i]];//�������Ψһ
            tmp+=add[n-prime[i]]; // ������3��
            if(prime[i]*3==n)
                tmp+=2; //������ͬ�����ĺͣ�����ֻ����һ�Σ�+2
            else if(!((n-prime[i])&1) && vis[(n-prime[i])/2] )
                tmp++; // ������ͬ�����ĺͼ�һ����ͬ��������������2��
            if(n%prime[i]==0)
            {
                int cnt=n/prime[i];
                tmp+=multi[n/prime[i]]; // ͬ��
                if(prime[i]*prime[i]*prime[i]==n)
                    tmp+=2;
                else if(sq(cnt) && vis[int(sqrt(cnt+0.0))])
                    tmp++;
            }
        }
        ans+=tmp/3;
        printf("%d\n",ans);
    }
    return 0;
}
