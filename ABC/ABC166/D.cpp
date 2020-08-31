#include <bits/stdc++.h>
using namespace std;

/*
A^5 - B^5 = X

i)   A < 0, B < 0
このとき|B| > |A|で |B|^5 - |A|^5であるが、|B|が120をこえるとXが10^9を超えるので120 * 120でおわり
ii)  A < 0, B >= 0
これはありえない
iii) A >= 0, B < 0
|A|^5 + |B|^5 なので 64 * 64でおわり
iv)  A >= 0, B >= 0
|A|^5 - |B|^5
*/


int	main(void)
{
	int x;
	cin >> x;
	for (int i = -120; i <= 120; i++)
	{
		for (int j = -120; j <= 120; j++)
		{
			if ((long long)pow(i, 5) - (long long)pow(j, 5) == x)
			{
				cout << i << " " << j << endl;
				return (0);
			}
		}
	}
}
