#include <bits/stdc++.h>
using namespace std;

/*
各ブロックをM色で塗る
隣り合うブロックで同じ色で塗られているのがK組以下
各遷移では、
i) 現在の色と同じ色で塗る
ii) 違う色で塗る
の二通りしかない

dp[N][K]みたいのができるけどO(N * K)だと計算量が大きい
後ろから見ると
dp[N]->[K, K]
dp[N-1]->[K-1, K]
...
となるけど結局O(K ^ 2)なので根本的な解決にはならない

for (int i = 0; i <= k; i++)
{
	dp[next][i] += dp[now][i] * (M - 1);
	dp[next][i + 1] += dp[now][i];
}
みたいな感じになる
つまり、漸化式で書くと dp[x][y] = (M - 1) * dp[x - 1][y] + dp[x - 1][y - 1];
dp[x][y] = (M - 1) * ((M - 1) * dp[x - 2][y] + dp[x - 2][y - 1]) + (M - 1) * dp[x - 2][y - 1] + dp[x - 2][y - 2];
dp[x][y] = (M - 1) ^ 2 * dp[x - 2][y] + 2 * (M - 1) * dp[x - 2][y - 1] + dp[x - 2][y - 2];
なんか二項定理でいけそう？
x = 0とすればy = 0しか値存在しないので、掛ける項はたかだか一つ
nCk * (M - 1)^(n - k) な気がする
*/

int mod = 998244353;

long long modpow(long long x, long long y){
    if (y == 0) return 1;
    if (y % 2) return x * modpow(x, y - 1) % mod;
    long long res = modpow(x, y / 2);
    return res * res % mod;
}

int	main(void)
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<long long> inv(n + 1, 1);
	for (int i = 2; i <= n; i++) inv[i] = (mod - (mod / i) * inv[mod % i] % mod) % mod;
	vector<long long> cmb(n + 1, 1);
	for (int i = 1; i < n; i++) cmb[i] = (cmb[i - 1] * (n - i) % mod) * inv[i] % mod;
	long long ans = 0;
	for (int i = 0; i <= k; i++)
	{
		//cout << i << " " << cmb[i] << " " << modpow(m - 1, n - i - 1) << " " << ((m * modpow(m - 1, n - i - 1)) % mod) * cmb[i] % mod << endl;
		ans += ((m * modpow(m - 1, n - i - 1)) % mod) * cmb[i] % mod;
		ans %= mod;
	}
	cout << ans << endl;
	return (0);
}
