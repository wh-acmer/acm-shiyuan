/*
    greedy water
*/
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
using namespace std;
vector<int>v;
int main()
{
    string s;
    int t;
    scanf("%d", &t);
    while (t--)
    {
        v.clear();
        cin >> s;
        int l, r;
        int mx = 10,index=-1;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] - '0' != 0 && s[i] - '0' <= mx)
            {
                mx = s[i] - '0';
                index = i;
            }
        }
        for (int i = 0; i < index; i++)
        {
            if (v.empty())
                v.push_back(s[i] - '0');
            else if (s[i] - '0' <= v[0])
                v.insert(v.begin(), s[i] - '0');
            else
                v.push_back(s[i] - '0');
        }
        v.insert(v.begin(), s[index] - '0');
        for (int i = index + 1; i < s.size(); i++)
            v.push_back(s[i] - '0');
        for (int i = 0; i < v.size(); i++)
            cout << v[i];
        cout << endl;
    }
    //system("pause");
    return 0;
}
