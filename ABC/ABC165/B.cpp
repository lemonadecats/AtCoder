#include <bits/stdc++.h>
using namespace std;

int	main(void)
{
	long long x;
	cin >> x;
	int ans = 0;
	long long value = 100;
	while (1)
	{
		if (value >= x)
		{
			cout << ans << endl;
			return (0);
		}
		value += (value / 100);
		ans++;
	}
	return (0);
}
