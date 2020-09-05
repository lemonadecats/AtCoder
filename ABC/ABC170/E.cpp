#include <bits/stdc++.h>
using namespace std;

/*
[平等さ]を求める
幼稚園それぞれの最も高いレートの最小値
幼稚園が2e5個あるので、毎回求めているわけには行かない
multisetで最小値を保存しておく

一回の移動で変化するのは、最大二つの値
すなわち、転園前の値と、転園後の値
まず、番兵としてすべての幼稚園に-1を入れておく
i) 転園前
削除前の値を保存
その幼稚園のmultisetから値を削除
削除後の値が変化したら、全体のmultisetの値を変更
ii) 転園後
追加前の値を保存
その幼稚園のmultisetに値を追加
追加後の値が変化したら、全体のmultisetの値を変更

問題は2e5個もmultisetを使って大丈夫なのかというところ
計算量的には2e5 * 7 * log(2e5) ぐらいで大丈夫そう
*/

int	main(void)
{
	multiset<int> highest_rate;
	vector<multiset<int>> kindergarden(2e5 + 1);
	for (int i = 0; i <= 2e5; i++) kindergarden[i].insert(-1);
	int n, q;
	cin >> n >> q;
	vector<pair<int, int>> infants(n + 1);
	for (int i = 1; i <= n; i++)
	{
		int a, b;
		cin >> a >> b;
		infants[i].first = a;
		infants[i].second = b;
		kindergarden[b].insert(a);
	}
	for (int i = 0; i <= 2e5; i++)
	{
		if (kindergarden[i].size() > 1) highest_rate.insert(*(--kindergarden[i].end())); //1より大きいからオッケーなはず
	}
	int a, b, c, d;
	int pre_c, pre_d;
	int after_c, after_d;
	for (int i = 0; i < q; i++)
	{
		cin >> c >> d;
		a = infants[c].first;
		b = infants[c].second;
		infants[c].second = d;
		pre_c = *(--kindergarden[b].end());
		pre_d = *(--kindergarden[d].end());
		kindergarden[b].erase(kindergarden[b].find(a));
		kindergarden[d].insert(a);
		after_c = *(--kindergarden[b].end());
		after_d = *(--kindergarden[d].end());
		if (pre_c != after_c)
		{
			highest_rate.erase(highest_rate.find(pre_c));
			if (after_c != -1) highest_rate.insert(after_c);
		}
		if (pre_d != after_d)
		{
			if (pre_d != -1) highest_rate.erase(highest_rate.find(pre_d));
			highest_rate.insert(after_d);
		}
		cout << *highest_rate.begin() << endl;
	}
	return (0);
}
