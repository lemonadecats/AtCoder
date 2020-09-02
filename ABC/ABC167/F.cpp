#include <bits/stdc++.h>
using namespace std;

/*
括弧を形成できていない数をそれぞれカウントしておく
括弧を形成できていないのは...))...((...のような形式になるはず
つまり{left, right}の組を作れる
あとは、left = 0のものと、right = 0のものが存在し、leftとrightが同数ならできる
-> leftとrightが同数でも場合によってはできない

leftが効果を及ぼすのは自分より右だけ、rightが効果を及ぼすのは自分より左だけ
順番においていって、leftより大きいrightがきたら無理
途中でマイナスになったらダメ
- right + leftの順番でやっていくので、rightがある値以下のもので、left - rightが最大のものを選びたい(最大とは限らないかも)

4
(
)
)))(     
)))(((((
とか

とれるものは現在のall_leftよりrightが小さいものしかない
方針としては2つ
i)rightがもっとも大きいものをとる
	これによってall_leftが小さくなってしまう可能性あり、最善じゃなさそう
ii)left - rightがもっとも大きいものをとる
	次にとれるrightの最大を最大化してくれそう、でもそれをとったことで次のrightで該当するものがなくなるかも
	3 -> {3, 2}, {2, 0}, {1, 0}
	どちらにせよ、いずれとるので、今とったことで取れなくなるならとれない？？？

BITでできそうだけど、値の削除ができないので難しいかも
遅延評価セグ木でやる？
sortして、pairとindexを対応させれば、値の削除もできそう

[解説よんで]
left = 0, right = 0は無視
right = 0のものを連結
left >= rightとなるものをrightが小さい順にたす(もし途中で連結できない場合は、順番を入れ替えてもそのrightをとることはできないことからNo)
right < leftとなるものをleftが大きい順にたす(もし途中で連結できなければ、順番を入れ替えてもrightに対処できない)
left = 0のものを連結
*/

int	main(void)
{
	int n;
	cin >> n;
	vector<string> s(n);
	for (int i = 0; i < n; i++) cin >> s[i];
	vector<pair<int, int>> positive;
	vector<pair<int, int>> negative;
	int left_cnt = 0;
	int right_cnt = 0;
	for (int i = 0; i < n; i++)
	{
		int left = 0;
		int right = 0;
		for (int j = 0; j < s[i].size(); j++)
		{
			if (s[i][j] == '(') left++;
			else
			{
				if (left > 0) left--;
				else right++;
			}
		}
		if (left == 0 && right == 0) continue;
		if (left == 0) right_cnt += right;
		else if (right == 0) left_cnt += left;
		else if (left >= right) positive.push_back({right, left});
		else negative.push_back({left, right});
	}
	sort(positive.begin(), positive.end());
	sort(negative.begin(), negative.end(), greater<pair<int, int>>());
	for (int i = 0; i < positive.size(); i++)
	{
		left_cnt -= positive[i].first;
		if (left_cnt < 0)
		{
			cout << "No" << endl;
			return (0);
		}
		left_cnt += positive[i].second;
	}
	for (int i = 0; i < negative.size(); i++)
	{
		left_cnt -= negative[i].second;
		if (left_cnt < 0)
		{
			cout << "No" << endl;
			return (0);
		}
		left_cnt += negative[i].first;
	}
	if (left_cnt != right_cnt) cout << "No" << endl;
	else cout << "Yes" << endl;
	return (0);
}