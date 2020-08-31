#include <bits/stdc++.h>
using namespace std;

int	main(void)
{
	int n, k;
	cin >> n >> k;
	vector<bool> sunuke(n, false);
	for (int i = 0; i < k; i++)
	{
		int d;
		cin >> d;
		int candy;
		for (int j = 0; j < d; j++)
		{
			cin >> candy; candy--;
			sunuke[candy] = true;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) ans += (1 - sunuke[i]);
	cout << ans << endl;
}
