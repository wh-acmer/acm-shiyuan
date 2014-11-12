// 分成两部分加中间的一根线
// 对于每部分就是求一个欧拉值的累积和，不过这个里面euler[1]=1;
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn=1001;
bool isprime[maxn];
int prime[maxn/3];
int euler[maxn];
void solve()
{
    int cnt=0;
    memset(isprime,1,sizeof(prime));
    for(int i=2;i<maxn;i++)
    {
        if(isprime[i])
        {
            prime[++cnt]=i;
            euler[i]=i-1;
        }
        for(int j=1;j<=cnt&&prime[j]*i<maxn;j++)
        {
            isprime[prime[j]*i]=0;
            if(i%prime[j])
                euler[prime[j]*i]=euler[i]*euler[prime[j]];
            else
            {
                euler[prime[j]*i]=euler[i]*prime[j];
                break;
            }
        }
    }
    euler[1]=1;
    for(int i=2;i<=maxn;i++)
        euler[i]+=euler[i-1];
}
int main()
{
    int t;
    scanf("%d",&t);
    solve();
    for(int i=1;i<=t;i++)
    {
        int a;
        scanf("%d",&a);
        printf("%d %d %d\n",i,a,2*euler[a]+1);
    }
    return 0;
}
