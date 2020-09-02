#include <bits/stdc++.h>
using namespace std;

int	main(void)
{
	int a, b, c, k;
	cin >> a >> b >> c >> k;
	int ans = 0;
	ans = min(a, k);
	if (a + b < k) ans -= k - (a + b);
	cout << ans << endl;
	return (0);
}
