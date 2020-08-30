#include <bits/stdc++.h>

/*
最大のケースはN=10,M=10の時
1,1,1,1,1,1,1,1,1,1から
1,2,3,4,5,6,7,8,9,10まで
これが計算可能な個数に収まればよい -> 92378らしいのでOK
*/

typedef struct 	s_data
{
	int a;
	int b;
	int c;
	int d;
}				t_data;

int A[10];
t_data data[51];
int ans;

void dfs(int A[10], int num, int end, int max, t_data data[51], int q)
{
	if (num == end)
	{
		int tmp = 0;
		for (int i = 0; i <= q; i++)
		{
			if (A[data[i].b] - A[data[i].a] == data[i].c) tmp += data[i].d;
		}
		ans = std::max(ans, tmp);
		return ;
	}
	int pre;
	if (num == 0) pre = 1;
	else pre = A[num - 1];
	for (int i = pre; i <= max; i++)
	{
		A[num] = i;
		dfs(A, num + 1, end, max, data, q);
	}
}

int	main(void)
{
	int n, m, q;
	std::cin >> n >> m >> q;
	for (int i = 0; i < q; i++)
	{
		std::cin >> data[i].a >> data[i].b >> data[i].c >> data[i].d;
		data[i].a--; data[i].b--;
	}
	dfs(A, 0, n, m, data, q);
	std::cout << ans << std::endl;
	return (0);
}
