/*
	water
	求n*n*n的立方中的n^3个立方选出两个，相邻顶点不超过2的对数
	总的方案数C(n^3,2),减去相邻顶点为4的pair,顶点为4的pair为3个方向*(n-1)个面*n^2
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
