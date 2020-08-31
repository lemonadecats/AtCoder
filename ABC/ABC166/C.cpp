#include <bits/stdc++.h>
using namespace std;

/*
一本の道を通ってたどり着けるどの展望台よりも高いとき+1
それぞれの頂点から全部見るとO(2 * M)ぐらいになりそう
*/

int	main(void)
{
	int n, m;
    cin >> n >> m;
	vector<int> h(n);
	for (int i = 0; i < n; i++) cin >> h[i];
	vector<vector<int>> edge(n);
	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b; a--; b--;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (edge[i].size() == 0) ans++;
		else
		{
			bool flag = true;
			for (int j = 0; j < edge[i].size(); j++)
			{
				if (h[i] <= h[edge[i][j]]) flag = false;
			}
			ans += flag;
		}
	}
	cout << ans << endl;
}
