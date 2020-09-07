#include <bits/stdc++.h>
using namespace std;

/*
提出前に確認!
- setとmultisetを間違えない
*/

int	main(void)
{
	int n;
	cin >> n;
	cout << (1000 - n % 1000) % 1000 << endl;
	return (0);
}
