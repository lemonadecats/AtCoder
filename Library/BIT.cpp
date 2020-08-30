#include<bits/stdc++.h>
using namespace std;

int N;

void add(int a, int w, vector<int> &bit) 
{
    for (int x = a; x <= N; x += x & -x) bit[x] += w;
}
int sum(int a, vector<int> &bit) {
    int ret = 0;
    for (int x = a; x > 0; x -= x & -x) ret += bit[x];
    return ret;
}