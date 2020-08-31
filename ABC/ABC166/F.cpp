#include <bits/stdc++.h>
using namespace std;

int cnt;
char ans[100'001];

void apply2(int *a, int *b, string s, int index)
{
	(*a)++;
	(*b)--;
	ans[cnt++] = s[index];
}

bool solve2(int *X, int *Y, string s)
{
	if (!(*X) && !(*Y))
		return (false);
	if ((*X) > (*Y)) apply2(Y, X, s, 1);
	else apply2(X, Y, s, 0);
	return (true);
}

int	main(void)
{
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	vector<string> s(n + 1);
	int A, B, C;
	A = a;
	B = b;
	C = c;
	for (int i = 0; i < n; i++) cin >> s[i];
	s[n] = "ZZ";
	bool flag;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == "AB" && s[i + 1] == "BC") flag = solve2(&B, &A, "BA");
		else if (s[i] == "AB") flag = solve2(&A, &B, "AB");
		else if (s[i] == "BC" && s[i + 1] == "AC") flag = solve2(&C, &B, "CB");
		else if (s[i] == "BC") flag = solve2(&B, &C, "BC");
		else if (s[i] == "AC" && s[i + 1] == "AB") flag = solve2(&A, &C, "AC");
		else flag = solve2(&C, &A, "CA");
		if (flag == false)
		{
			cout << "No" << endl;
			return (0);
		}
	}
	cout << "Yes" << endl;
	for (int i = 0; i < n; i++) cout << ans[i] << endl;
	return (0);
}
