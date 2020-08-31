#include <bits/stdc++.h>
using namespace std;

int		cnt;
bool	flag;
char	ans[100'001];
string	s[100'001];

void apply(int *a, int *b, string s, int index)
{
	(*a)++; (*b)--;
	ans[cnt++] = s[index];
}

bool solve(int *X, int *Y, string s)
{
	if (!(*X) && !(*Y)) return (false);
	if ((*X) > (*Y)) apply(Y, X, s, 1);
	else apply(X, Y, s, 0);
	return (true);
}

int	main(void)
{
	int n, A, B, C;
	cin >> n >> A >> B >> C;
	for (int i = 0; i < n; i++) cin >> s[i];
	s[n] = "AA";
	for (int i = 0; i < n; i++)
	{
		if (s[i] == "AB") flag = (s[i + 1] == "BC") ? solve(&B, &A, "BA") : solve(&A, &B, "AB");
		if (s[i] == "BC") flag = (s[i + 1] == "AC") ? solve(&C, &B, "CB") : solve(&B, &C, "BC");
		if (s[i] == "AC") flag = (s[i + 1] == "AB") ? solve(&A, &C, "AC") : solve(&C, &A, "CA");
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