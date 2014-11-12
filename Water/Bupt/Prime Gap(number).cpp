/// 输出某个数字，处于(p,p+n)之中求n
/// http://coder.buct.edu.cn/JudgeOnline/problem.php?cid=1021&pid=0
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
#define maxn 1299710
int num[maxn];
int prime[100001];
int n_prime=0;
void Prime()
{
    memset(num,1,sizeof(num));
    num[0]=num[1]=0;
    for(int i=2;i<maxn;i++)
    {
        if(num[i])
        {
            prime[++n_prime]=i;
            for(int j=2*i;j<maxn;j+=i)
                num[j]=0;
        }
    }
}
int main()
{
    Prime();
    int n;
    while(scanf("%d",&n)!=EOF,n)
    {
        int i;
        int tag=0;
        for(i=1;i<=100000;i++)
        {
            if(prime[i]==n)
            {
                tag=1;
                break;
            }
            if(prime[i]>n)
                break;
        }
        if(!tag)
            printf("%d\n",prime[i]-prime[i-1]);
        else
            printf("0\n");
    }
    return 0;
}
