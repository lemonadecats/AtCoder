#include <bits/stdc++.h>
using namespace std;

/*
提出前に確認!
- setとmultisetを間違えない
*/

/*
親切さが大きい人から入っていく
最初が最大 -> +0
次の人の隣は最大しかいないので -> +An
その次の人は最大と次の最大の人の間なので、次の最大 -> +An-1
その次はもう一回最大と次の最大の人の間に挟まれる -> +An-1
以下同様
*/

int	main(void)
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	long long ans = a[n - 1];
	for (int i = 2; i < n; i++)
	{
		ans += a[n - i / 2 - 1];
	}
	cout << ans << endl;
	return (0);
}
