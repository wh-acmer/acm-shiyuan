/*
    ���⣺����Ϊn�������г�m�Σ�����С�ε�����
    ˼·��ö����С��Ϊ1��n/m��������ø��巨��ʣ�µ�����
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        double ans=0;
        for(int i=1;i<=(n/m);i++){
            double tmp=1;
            for(int j=1;j<=m-1;j++){
                tmp*=(n-i*m+m-j)/(n-j+0.0);
            }
            ans+=tmp;
        }
        printf("%.5lf\n",ans);
    }
    return 0;
}
