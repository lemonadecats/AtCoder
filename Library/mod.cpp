#include <bits/stdc++.h>
using namespace std;

int mod = 998244353;

//modpowの計算
map<pair<long long, long long>, long long> mp;
long long modpow(long long x, long long y){
    if (mp[{x, y}]) return mp[{x, y}];
    if (y == 0) return 1;
    if (y % 2) {
        long long res = x * modpow(x, y - 1) % mod;
        mp[{x, y}] = res;
        return res;
    }
    long long res = modpow(x, y / 2) * modpow(x, y / 2) % mod;
    mp[{x, y}] = res;
    return res;
}

long long modpow(long long x, long long y){
    if (y == 0) return 1;
    if (y % 2) return x * modpow(x, y - 1) % mod;
    long long res = modpow(x, y / 2);
    return res * res % mod;
}

long long calc_cmb(int n, int a){
    vector<long long> inv(a + 1, 1);
    for (int i = 2; i <= a; i++) inv[i] = (mod - (mod / i) * inv[mod % i] % mod) % mod;
    vector<long long> cmb(a + 1, 1);
    for (int i = 1; i <= a; i++) cmb[i] = (cmb[i - 1] * (n - i + 1) % mod) * inv[i] % mod;
    return (cmb[a]);
}

//逆元の計算
vector<long long> inv(4001, 1);
void calc_inv(){
    for (int i = 2; i <= 4000; i++) inv[i] = (mod - (mod / i) * inv[mod % i] % mod) % mod;
}

//Combinationの計算
vector<long long> cmb(4001, 1);
void calc_cmb(){
    for (int i = 1; i <= 4000; i++) cmb[i] = (cmb[i - 1] * (4000 - i + 1) % mod) * inv[i] % mod;
}

vector<long long> fac(2e6 + 2, 1);
for (int i = 2; i < 2e6 + 2; i++) fac[i] = fac[i - 1] * i % mod;
vector<long long> inv(1e6 + 2, 1);
for (int i = 2; i < 1e6 + 2; i++) inv[i] = (mod - (mod / i) * inv[mod % i] % mod) % mod;


vector<long long> inv(2e5 + 1, 1);
for (int i = 2; i < 2e5 + 1; i++) inv[i] = (mod - (mod / i) * inv[mod % i] % mod) % mod;
vector<long long> cmb(n + 1, 1);
for (int i = 1; i <= n; i++) cmb[i] = (cmb[i - 1] * (n - i + 1) % mod) * inv[i] % mod;
vector<long long> cmb2(n, 1);
for (int i = 1; i < n; i++) cmb2[i] = (cmb2[i - 1] * (n - 1 - i + 1) % mod) * inv[i] % mod;