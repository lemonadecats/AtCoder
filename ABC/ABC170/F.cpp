#include <bits/stdc++.h>
using namespace std;

/*
H * W <= 1e6なのでbfsすれば良い？
Kが10^6なので分岐が多すぎる
O(4 * 1e6)
*/

int	main(void)
{
	int h, w, k;
	cin >> h >> w >> k;
	int from_x, from_y, to_x, to_y;
	cin >> from_x >> from_y >> to_x >> to_y;
	from_x--; from_y--; to_x--; to_y--;
	vector<vector<bool>> grid(h, vector<bool>(w));
	vector<vector<int>> dfs(h, vector<int>(w, 1e9));
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			char c;
			cin >> c;
			grid[i][j] = (c == '.');
		}
	}
	queue<pair<int, int>> q;
	q.push({from_x, from_y});
	dfs[from_x][from_y] = 0;
	int depth = 0;
	int x, y;
	vector<int> dx = {1, -1, 0, 0};
	vector<int> dy = {0, 0, 1, -1};
	while (q.size())
	{
		depth++;
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			x = q.front().first;
			y = q.front().second;
			q.pop();
			if (x == to_x && y == to_y)
			{
				cout << depth - 1 << endl;
				return (0);
			}
			for (int j = 0; j < 4; j++)
			{
				for (int z = 1; z <= k; z++)
				{
					if (x + dx[j] * z < 0 || x + dx[j] * z >= h) break ;
					if (y + dy[j] * z < 0 || y + dy[j] * z >= w) break ;
					if (!grid[x + dx[j] * z][y + dy[j] * z]) break ;
					if (dfs[x + dx[j] * z][y + dy[j] * z] < depth) break ;
					if (dfs[x + dx[j] * z][y + dy[j] * z] == depth) continue ;
					dfs[x + dx[j] * z][y + dy[j] * z] = depth;
					q.push({x + dx[j] * z, y + dy[j] * z});
				}
			}
		}
	}
	cout << -1 << endl;
	return (0);
}
