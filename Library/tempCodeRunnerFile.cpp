#include<bits/stdc++.h>
using namespace std;

int b = 1'000'000'007;
int h1 = 1'100'023'409;
int h2 = 1'200'017'417;
int h3 = 1'500'026'741;

long long modpow(long long x, long long y, long long p){
    if (y == 0) return 1;
    if (y % 2) return x * modpow(x, y - 1, p) % p;
    return modpow(x, y / 2, p) * modpow(x, y / 2, p) % p;
}


//sのhash値をhashに格納する
//hashはsのsize+1であることに注意
void set_hash(string s, vector<vector<long long>> &hash){
    for (int i = 0; i < 3; i++) hash[i][0] = 0;
    for (int i = 0; i < s.size(); i++) hash[0][i + 1] = (hash[0][i] * b + s[i]) % h1;
    for (int i = 0; i < s.size(); i++) hash[1][i + 1] = (hash[1][i] * b + s[i]) % h2;
    for (int i = 0; i < s.size(); i++) hash[2][i + 1] = (hash[2][i] * b + s[i]) % h3;
}

//hashのx番目(0-indexed)からx_length文字のhash値をhash_tmpに格納して返す
//何度も使うときはmodpowが重いかもしれない
vector<long long> hash_tmp(3);
//vector<vector<long long>> modp(x_lengthの取りうる最大値, vector<long long>(3));
void get_hash(vector<vector<long long>> &hash, int &x, int &x_length){
    //long long p1, p2, p3;
    //p1 = modp[x_length][0];みたいにすると計算量落ちる
    hash_tmp[0] = (hash[0][x + x_length] - hash[0][x] * modpow(b, x_length, h1) % h1 + h1) % h1;
    hash_tmp[1] = (hash[1][x + x_length] - hash[1][x] * modpow(b, x_length, h2) % h2 + h2) % h2;
    hash_tmp[2] = (hash[2][x + x_length] - hash[2][x] * modpow(b, x_length, h3) % h3 + h3) % h3;
}

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<long long>> hash(3, vector<long long>(n + 1));
    set_hash(s, hash);
    map<vector<long long>, int> mp;
    int ok = 0;
    int ng = n + 1;
    while (abs(ok - ng) > 1){
        int mid = (ok + ng) / 2;
        bool flag = false;
        int id = 1;
        mp.erase(mp.begin(), mp.end());
        for (int i = 0; i < n; i++){
            if (mid + i > n) break;
            get_hash(hash, i, mid);
            if (mp[hash_tmp]) {
                if (mp[hash_tmp] + mid <= i) flag = true;
            }
            else {
                mp[hash_tmp] = id;
                id++;
            }
        }
        if (flag) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
}