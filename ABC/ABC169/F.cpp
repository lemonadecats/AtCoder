#include <bits/stdc++.h>
using namespace std;

/*
1~Nの部分集合のうち、その和がSになるものの個数をかぞえあげる
ただし、部分集合の部分集合みたいになるので、ある集合が複数回数えられる
ただ、数えられる回数は要素数に依存するだろう
例えば1だったら、+他の要素の選び方2^(n - 1)回

つまり持っている要素数とその和の情報さえわかればいい
ただし、和の情報を更新するのがネックになる
要素を追加するたびにS * K回の更新が必要？
O(N * S * K)だと間に合わない

Aが1以上であることに注目する？
冪乗で持っておけばO(N * S * log(K))?

全体から引く？
dp[S][K]???

要素数の情報を減らす
最初は全部使うと考える -> * 1
減らしていく
dp[S][A_all] = 1
dp[S - 1][A_all - Ak] -> 1 * 2みたいにすればよいのでは？

むしろ割るか
*/

int mod = 998244353;
long long dp[3001][3001];

long long modpow(long long x, long long y){
    if (y == 0) return 1;
    if (y % 2) return x * modpow(x, y - 1) % mod;
    long long res = modpow(x, y / 2);
    return res * res % mod;
}

int	main(void)
{
	int n, s;
	cin >> n >> s;
	vector<bool> is_visit(s + 1, false);
	dp[0][0] = modpow(2, n);
	is_visit[0] = true;
	long long div_two = modpow(2, mod - 2);
	long long a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		for (int j = 0; j <= s; j++)
		{
			dp[i + 1][j] += dp[i][j];
			dp[i + 1][j] %= mod;
			if (!is_visit[j]) continue ;
			if (j + a > s) continue ;
			is_visit[j + a] = true;
			dp[i + 1][j + a] += (dp[i][j] * div_two) % mod;
			dp[i + 1][j + a] %= mod;
		}
	}
	cout << dp[n][s] % mod << endl;
	return (0);
}
