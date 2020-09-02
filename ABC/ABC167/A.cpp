#include <bits/stdc++.h>
using namespace std;

int	main(void)
{
	string s, t;
	cin >> s >> t;
	if (s.size() + 1 != t.size())
	{
		cout << "No" << endl;
		return (0);
	}
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != t[i])
		{
			cout << "No" << endl;
			return (0);
		}
	}
	cout << "Yes" << endl;
	return (0);
}
