#include <bits/stdc++.h>
using namespace std;
/*
1...................100000000
   10..............10000
        100..100

n = 2のときは ((b0 - a0 + 1) * (b1 - a1 + 1)) - (同じ区間の個数)

n >= 3のとき
一番小さな値と一番大きな値は無視できる
10.............10000
10.............10000
      100.100

なんか二分探索な気がする
中央値を二倍すれば整数
2 <= ans <= 2e9
で、たぶん連続

あるansが答えになりうるかを判定する

いや、もっと単純かも
連続ならば、最小値と最大値を求めるだけでいけるのでは
*/

int	main(void)
{
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	if (n % 2) cout << b[n / 2] - a[n / 2] + 1 << endl;
	else cout << (b[n / 2] + b[n / 2 - 1]) - (a[n / 2] + a[n / 2 - 1]) + 1 << endl;
	return (0);
}
