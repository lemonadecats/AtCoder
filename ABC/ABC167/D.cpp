#include <bits/stdc++.h>
using namespace std;

/*
絶対どこかでループになる
しかもループは一つ
だから行ったかどうかのflagを作って、flagが立ってるのにまた来たらvectorにつっこむ
*/

int	main(void)
{
	vector<int> normal;
	vector<int> loop;
	long long n, k;
	cin >> n >> k;
	int a;
	vector<int> next(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a; a--;
		next[i] = a;
	}
	vector<bool> is_visit(n, false);
	vector<bool> is_double_visit(n, false);
	int now = 0;
	while (1)
	{
		if (is_double_visit[now]) break;
		if (is_visit[now]) 
		{
			loop.push_back(now);
			is_double_visit[now] = true;
		}
		else normal.push_back(now);
		is_visit[now] = true;
		now = next[now];
	}
	if (k < normal.size()) cout << normal[k] + 1 << endl;
	else cout << loop[(k - normal.size()) % loop.size()] + 1 << endl;
	return (0);
}
