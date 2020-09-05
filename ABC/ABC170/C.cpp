#include <bits/stdc++.h>
using namespace std;

int	main(void)
{
	int x, n;
	cin >> x >> n;
	vector<bool> can_use(220, true);
	int p;
	for (int i = 0; i < n; i++)
	{
		cin >> p;
		can_use[p + 110] = false;
	}
	int ans = -1;
	int diff = 1e9;
	for (int i = 0; i < 220; i++)
	{
		if (!can_use[i]) continue ;
		if (abs(x - (i - 110)) < diff)
		{
			ans = i - 110;
			diff = abs(x - (i - 110));
		}
	}
	cout << ans << endl;
	return (0);
}
