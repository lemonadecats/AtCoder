#include <bits/stdc++.h>
using namespace std;

/*
提出前に確認!
- setとmultisetを間違えない
*/

/*
positive
negative
zero
に分ける

k == 1のとき
	最大値を出力
k == 2のとき
	positiveの上二つ、もしくはnegativeの上二つ
	どちらも二つ以上ない場合、0があるなら0を出力、ないならpositive * negative
k == 3のとき

*/

int mod = 1e9 + 7;

long long modpow(long long x, long long y){
    if (y == 0) return 1;
    if (y % 2) return x * modpow(x, y - 1) % mod;
    long long res = modpow(x, y / 2);
    return res * res % mod;
}

long long solve_inverse(vector<int> &positive, vector<int>&negative, int k)
{
	vector<int> all;
	for (int i = 0; i < positive.size(); i++) all.push_back(positive[i]);
	for (int i = 0; i < negative.size(); i++) all.push_back(negative[i]);
	sort(all.begin(), all.end());
	long long res = 1;
	for (int i = 0; i < k; i++)
	{
		res *= all[i];
		res %= mod;
	}
	res %= mod;
	res = (mod - res) % mod;
	return (res);
}

int	main(void)
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	if (n == 1) //このとき絶対k=1
	{
		cout << a[0] << endl;
		return (0);
	}
	vector<int> positive;
	vector<int> negative;
	int zero_cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0) positive.push_back(a[i]);
		else if (a[i] < 0) negative.push_back(abs(a[i]));
		else zero_cnt++;
	}
	if (zero_cnt + k > n)
	{
		cout << 0 << endl;
		return (0);
	}
	sort(positive.begin(), positive.end());
	sort(negative.begin(), negative.end());
	int positive_index = (int)positive.size() - 1;
	int negative_index = (int)negative.size() - 1;
	long long ans = 1;
	int cnt = 0;
	while (1)
	{
		if (cnt == k) break ;
		long long positive_max = -1e9;
		long long negative_max = -1e9;
		if (positive_index > 0)
		{
			positive_max = (long long)positive[positive_index] * positive[positive_index - 1];
		}
		if (negative_index > 0)
		{
			negative_max = (long long)negative[negative_index] * negative[negative_index - 1];
		}
		if (positive_max > negative_max)
		{
			ans *= positive[positive_index];
			ans %= mod;
			positive_index -= 1;
			cnt++;
		}
		else if (positive_max < negative_max || negative_max > 0)
		{
			if (cnt + 2 > k) break ;
			ans *= negative_max % mod;
			ans %= mod;
			negative_index -= 2;
			cnt += 2;
		}
		else
		{
			if (cnt + 2 > k) break ;
			/*
			ありうるのは
			pos: 1 nega: 1
			pos: 1 nega: 0
			pos: 0 nega: 1
			pos: 0 nega: 0
			pos: 1 nega: 0
			どの場合もzeroを使うのが最善
			*/
			if (zero_cnt > 0)
			{
				cout << 0 << endl;
				return (0);
			}
			ans *= positive[positive_index];
			ans %= mod;
			ans *= (mod - negative[negative_index]) % mod;
			ans %= mod;
			positive_index = -1;
			negative_index = -1;
			cnt += 2;
		}
	}
	if (cnt != k)
	{
		if (positive_index >= 0)
		{
			ans *= positive[positive_index];
			ans %= mod;
		}
		else if (negative_index > 0 && positive.size() >= 2)
		{
			ans *= negative[negative_index];
			ans %= mod;
			ans *= negative[negative_index - 1];
			ans %= mod;
			ans *= modpow(positive[0], mod - 2) % mod;
			ans %= mod;
		}
		else if (zero_cnt)
		{
			cout << 0 << endl;
			return (0);
		}
		else
		{
			ans = solve_inverse(positive, negative, k) % mod;
		}
	}
	cout << ans << endl;
	return (0);
}