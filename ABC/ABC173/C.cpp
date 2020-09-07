#include <bits/stdc++.h>
using namespace std;

/*
提出前に確認!
- setとmultisetを間違えない
*/

int	main(void)
{
	int h, w, k;
	cin >> h >> w >> k;
	int ans = 0;
	vector<vector<bool>> grid(h, vector<bool>(w));
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			char c;
			cin >> c;
			grid[i][j] = (c == '#');
		}
	}
	for (int i = 0; i < (1 << h); i++)
	{
		for (int j = 0; j < (1 << w); j++)
		{
			vector<vector<bool>> copy_grid = grid;
			for (int i2 = 0; i2 < h; i2++)
			{
				if ((i >> i2) & 1)
				{
					for (int k2 = 0; k2 < w; k2++) copy_grid[i2][k2] = false;
				}
			}
			for (int j2 = 0; j2 < w; j2++)
			{
				if ((j >> j2) & 1)
				{
					for (int k2 = 0; k2 < h; k2++) copy_grid[k2][j2] = false;
				}
			}
			int tmp = 0;
			for (int i2 = 0; i2 < h; i2++)
			{
				for (int j2 = 0; j2 < w; j2++) tmp += copy_grid[i2][j2];
			}
			if (tmp == k)
			{
				ans++;
			}
		}
	}
	cout << ans << endl;
	return (0);
}
