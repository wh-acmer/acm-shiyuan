// Garage
// http://codeforces.com/gym/100269/attachments/download/1978/20132014-acmicpc-neerc-nothern-subregional-contest-en.pdf
// water

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
typedef long long LL;
#define eps 1e-9
int main(){
    freopen("garage.in","r",stdin);
    freopen("garage.out","w",stdout);
    LL W,H,w,h;
    while(cin>>W>>H>>w>>h){
        LL x=(LL)floor(W/(2*w-0.00001)+eps);
        LL y=(LL)floor(H/(2*h-0.00001))+eps;
        double rx=W-x*(2*w-0.00001);
        double ry=H-y*(2*h-0.00001);
        if(rx>=w) x++;
        if(ry>=h) y++;
        LL ans=(LL)x*y;
        cout<<ans<<endl;
    }
    return 0;
}
