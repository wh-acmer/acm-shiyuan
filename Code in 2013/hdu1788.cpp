//��Ŀ��˼�������й�ʣ�ඨ��Ĺ��̣����վ�����ֻ�ǹ���N%Mi=Mi-k
// �������ϵʽ���Եõ�N+k=0��mod Mi��
// �����������ת��Ϊ��n��������С��������
#include <cstdio>
#include <iostream>
using namespace std;
long long gcd(long long a,long long b)
{
    return !b?a:gcd(b,a%b);
}
long long lcm(long long a,long long b)
{
    return a/gcd(a,b)*b;
}
int main()
{
    long long n,m;
    while(scanf("%I64d%I64d",&n,&m),m||n)
    {
        long long a;
        long long ans=1;
        for(int i=1;i<=n;i++)
        {
            scanf("%I64d",&a);
            ans=lcm(ans,a);
        }
        printf("%I64d\n",ans-m);
    }
    return 0;
}
