#include <bits/stdc++.h>
using namespace std;

/*
[構築]
参加者がN人(N <= 2 * 10^5)
対戦場がM個

対戦場に2つの相異なる1〜Nの番号を割り振る
一ラウンドが終わると全員が(i + 1) % N + 1に番号が変わる
N回試合を行って、同じ対戦の組が発生しないようにする方法

o  o 1 11
o  o 2 10
o  o 3 9
x  x 4 8
x  x 5 7
x    6

  x   6
o o 1 5  6 4  5 3  4 2
o o 2 4  1 3  6 2  5 1
x   3

    1 2  6 1  5 6  4 5  3 4  2 3 -> 0 or 4
	3 5  2 4  1 3  6 2  5 1  4 6 -> 1 or 3
    4 6
1 2 | 3 4 5 | 6
[1 2] 3 | [4 (5) 6]
多分ダメだけど一回出す
結構通っているので、特別なケースが存在しそう
上図の左上の人に注目すると、戦うのは右上の人、右上から3番目の人...というようになっていくので順番に全員と戦える
ただし、Nが偶数の時はその限りではない
Nが奇数ならば: 11->9->7->(5)->(3)->(10)->8->6...
Nが偶数ならば: 7->5->(3)->(8)->5...でいけない
*/

int	main(void)
{
	int n, m;
	cin >> n >> m;
	n -= (n % 2 == 0);
	int start = 1;
	int end = n / 2;
	int cnt = 0;
	while (1)
	{
		if (start >= end - start + 1 || cnt == m) break;
		cout << start << " " << end - start + 1 << endl;
		start++; cnt++;
	}
	start = n / 2 + 1;
	end = n;
	while (1)
	{
		if (start >= end - start + (n / 2 + 1) || cnt == m) break;
		cout << start << " " << end - start + (n / 2 + 1) << endl;
		start++; cnt++;
	}
	return (0);
}
