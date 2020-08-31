#include <bits/stdc++.h>
using namespace std;

/*
2人の持つ番号の差の絶対値が、2人の身長の和に等しい
0番から左の人だけを見て行くと、差は必ずpositiveになる
よって身長の和だけが分かれば良い
A[i] + A[j] == j - iになればよいので、A[i] + i == j - A[j]になればよい
よってA[i] + iを保存しつつ見ていけば良さそう
*/

int	main(void)
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	map<int, int> mp;
	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans += mp[i - a[i]];
		mp[a[i] + i]++;
	}
	cout << ans << endl;
	return (0);
}
