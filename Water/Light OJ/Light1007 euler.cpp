// ��֮ǰ��ģ�岻��TLE������MLE
// Ȼ����һ�����Ե�������WA��
// Ȼ����forum��������� 2 500W ��long long��
// Ȼ����չ��һ�������Ӽ���MLE��
// then��
// long long �ĳ� unsigned long long ����
//
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=5000005;
bool isprime[maxn];
int prime[maxn/3];
unsigned long long euler[maxn];
void solve()
{
    int cnt=0;
    memset(isprime,1,sizeof(isprime));
    for(int i=2;i<maxn;i++)
    {
        if(isprime[i])
        {
            prime[++cnt]=i;
            euler[i]=i-1;
        }
        for(int j=1;j<=cnt&&prime[j]*i<maxn;j++)
        {
            isprime[i*prime[j]]=0;
            if(i%prime[j]!=0)
                euler[i*prime[j]]=euler[i]*euler[prime[j]];
            else
            {
                euler[i*prime[j]]=euler[i]*prime[j];
                break;
            }
        }
    }
    euler[1]=0;
    for(int i=2;i<maxn;i++)
        euler[i]=euler[i]*euler[i]+euler[i-1];
}
int main()
{
    int t;
    scanf("%d",&t);
    solve();
    for(int cases=1;cases<=t;cases++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        printf("Case %d: %llu\n",cases,euler[b]-euler[a-1]);
    }
}
