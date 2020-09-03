#include <bits/stdc++.h>
using namespace std;

int	main(void)
{
	long long a;
	cin >> a;
	string s;
	cin >> s;
	int b = 0;
	b += (s[0] - '0') * 100;
	b += (s[2] - '0') * 10;
	b += (s[3] - '0');
	a *= b;
	a /= 100;
	cout << a << endl;
}
