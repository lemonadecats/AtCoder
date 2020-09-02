#include <bits/stdc++.h>
using namespace std;

int	main(void)
{
	int n, m, x;
	cin >> n >> m >> x;
	vector<int> c(n);
	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		cin >> c[i];
		for (int j = 0; j < m; j++) cin >> a[i][j];
	}
	int ans = 1e9;
	for (int i = 0; i < (1 << n); i++)
	{
		int payment = 0;
		vector<int> tmp(m, 0);
		for (int j = 0; j < n; j++)
		{
			if ((i >> j) & 1)
			{
				for (int k = 0; k < m; k++) tmp[k] += a[j][k];
				payment += c[j];
			}
		}
		bool flag = true;
		for (int j = 0; j < m; j++)
		{
			if (tmp[j] < x) flag = false;
		}
		if (flag) ans = min(ans, payment);
	}
	if (ans == 1e9) cout << "-1" << endl;
	else cout << ans << endl;
	return (0);
}
