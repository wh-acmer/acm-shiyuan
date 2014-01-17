/*
	water
	求x的最大值,满足x!<=2^(2^((n-1960)/2+2))
	预处理+二分
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;
vector<double >v;
int main(){
	int n;
	double ans = 0;
	v.clear();
	v.push_back(0);
	for (int i = 1;; i++){
		v.push_back(v[i - 1] + log10(i + 0.0));
		if (v[i] > pow(2.0, 22.0)*log10(2.0)) break;
	}
	while (scanf("%d", &n) != EOF){
		if (n == 0) break;
		n -= 1960, n /= 10, n += 2;
		vector<double>::iterator it = lower_bound(v.begin(), v.end(), pow(2.0, n + 0.0)*log10(2.0));
		printf("%d\n", it - v.begin() - 1);
	}
	//system("pause");
	return 0;
}
