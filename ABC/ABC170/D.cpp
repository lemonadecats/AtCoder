#include <bits/stdc++.h>
using namespace std;

/*
Aiは
任意のAjで割り切れない
sortすれば自分より小さいものだけ見ればよい
小さい方からみて、エラトステネスの篩をする
*/

int	main(void)
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	vector<bool> is_prime(1e6 + 1, true);
	vector<bool> is_used(1e6 + 1, false);
	for (int i = 0; i < n; i++)
	{
		if (is_used[a[i]]) is_prime[a[i]] = false;
		else
		{
			is_used[a[i]] = true;
			for (int j = 2; a[i] * j <= 1e6; j++) is_prime[a[i] * j] = false;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) ans += is_prime[a[i]];
	cout << ans << endl;
	return (0);
}
