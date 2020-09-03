#include <bits/stdc++.h>
using namespace std;

int	main(void)
{
	int n;
	cin >> n;
	vector<long long> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	bool is_zero = false;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 0) is_zero = true;
	}
	if (is_zero)
	{
		cout << 0 << endl;
		return (0);
	}
	long long ans = 1;
	for (int i = 0; i < n; i++)
	{
		if (a[i] * ans > (long long)1e18 || (double)a[i] * ans > (double)(2e18))
		{
			cout << -1  << endl;
			return (0);
		}
		ans *= a[i];
	}
	cout << ans << endl;
	return (0);
}
