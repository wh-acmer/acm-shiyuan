/*
	water
	��n*n*n�������е�n^3������ѡ�����������ڶ��㲻����2�Ķ���
	�ܵķ�����C(n^3,2),��ȥ���ڶ���Ϊ4��pair,����Ϊ4��pairΪ3������*(n-1)����*n^2
*/
#include <cstdio>
using namespace std;
int main(){
	int n;
	while (scanf("%d", &n) != EOF){
		printf("%d\n", n*n*n*(n*n*n - 1) / 2 - 3 * (n - 1)*n*n);
	}
	return 0;
}
