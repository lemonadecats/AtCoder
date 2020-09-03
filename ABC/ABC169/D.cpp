#include <bits/stdc++.h>
using namespace std;

/*
素数のe乗で、Nを割り切れるもの
のuniqueは最大で何個か

素因数分解する
各要素に対して1個以上とるから
1 2 3 4 5 6...
1 3 6 10 15 みたいな感じで三角数できまる
*/

int	main(void)
{
	long long n;
	cin >> n;
	vector<int> max_num(60, 0);
	max_num[1] = 1;
	int add = 1;
	for (int i = 1; i < 60; i += add)
	{
		max_num[i] = add;
		add++;
	}
	for (int i = 2; i < 60; i++)
	{
		if (max_num[i] == 0) max_num[i] = max_num[i - 1];
	}
	long long ans = 0;
	long long num = n;
	for (int i = 2; (long long)i * i < n; i++)
	{
		if (num % i == 0)
		{
			int tmp = 0;
			while (num % i == 0)
			{
				num /= i;
				tmp++;
			}
			ans += max_num[tmp];
		}
	}
	if (num != 1) ans++;
	cout << ans << endl;
	return (0);
}
