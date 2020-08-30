#include <bits/stdc++.h>
using namespace std;

/*
floor(t): 実数t以下の最大の整数
floor(A * x / B) - A * floor(x / B)の最大値を求める
U = floor(A * x / B), V = A * floor(x / B)とすると、どちらも単調増加する
三分探索が使えそう?
x = 0, x = Nを両端とする
*/

long long calc(long long x, long long a, long long b)
{
	return (floor((double)a * x / b) - a * floor((double)x / b));
}

int	main(void)
{
	long long a, b, n;
	cin >> a >> b >> n;
	long long left = 0;
	long long right = n;
	while (abs(right - left) > 2)
	{
		long long left_middle = left + (abs(right - left) / 3);
		long long right_middle = right - (abs(right - left) / 3);
		//cout << left << " " << left_middle << " " << right_middle << " " << right << endl;
		if (calc(left_middle, a, b) > calc(right_middle, a, b)) right = right_middle;
		else left = left_middle;
	}
	long long ans = 0;
	for (long long value = left; value <= right; value++) ans = max(ans, calc(value, a, b));
	cout << ans << endl;
	return (0);
}
