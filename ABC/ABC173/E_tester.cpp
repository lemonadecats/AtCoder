#include <bits/stdc++.h>
using namespace std;

/*
-357 -681 588 69 799 
194250483

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    cout << 357 * 681 << endl;
    cout << 588 * 799 << endl;
}
*/

int mod = 1e9 + 7;

long long modpow(long long x, long long y){
    if (y == 0) return 1;
    if (y % 2) return x * modpow(x, y - 1) % mod;
    long long res = modpow(x, y / 2);
    return res * res % mod;
}

long long solve_inverse(vector<int> &positive, vector<int>&negative, int k)
{
	vector<int> all;
	for (int i = 0; i < positive.size(); i++) all.push_back(positive[i]);
	for (int i = 0; i < negative.size(); i++) all.push_back(negative[i]);
	sort(all.begin(), all.end());
	long long res = 1;
	for (int i = 0; i < k; i++)
	{
		res *= all[i];
		res %= mod;
	}
	res = (mod - res) % mod;
	return (res);
}

int	tester(int n, int k, vector<int> &a)
{
	vector<int> positive;
	vector<int> negative;
	int zero_cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0) positive.push_back(a[i]);
		else if (a[i] < 0) negative.push_back(abs(a[i]));
		else zero_cnt++;
	}
	if (zero_cnt + k > n)
	{
		//cout << 0 << endl;
		return (0);
	}
	sort(positive.begin(), positive.end());
	sort(negative.begin(), negative.end());
	int positive_index = (int)positive.size() - 1;
	int negative_index = (int)negative.size() - 1;
	long long ans = 1;
	for (int i = 1; i * 2 <= k; i++)
	{
		long long positive_max = -1e9;
		long long negative_max = -1e9;
		if (positive_index > 0)
		{
			positive_max = (long long)positive[positive_index] * positive[positive_index - 1];
		}
		if (negative_index > 0)
		{
			negative_max = (long long)negative[negative_index] * negative[negative_index - 1];
		}
		if (positive_max > negative_max)
		{
			ans *= positive_max % mod;
			ans %= mod;
			positive_index -= 2;
		}
		else if (positive_max < negative_max || negative_max > 0)
		{
			ans *= negative_max % mod;
			ans %= mod;
			negative_index -= 2;
		}
		else
		{
			/*
			ありうるのは
			pos: 1 nega: 1
			pos: 1 nega: 0
			pos: 0 nega: 1
			pos: 0 nega: 0
			pos: 1 nega: 0
			どの場合もzeroを使うのが最善
			*/
			if (zero_cnt > 0)
			{
				//cout << 0 << endl;
				return (0);
			}
			ans *= positive[0];
			ans %= mod;
			ans *= mod - negative[0];
			ans %= mod;
			positive_index = -1;
			negative_index = -1;
		}
	}
	if (k % 2)
	{
		if (positive_index >= 0)
		{
			ans *= positive[positive_index];
			ans %= mod;
		}
		else if (negative_index > 0 && positive.size() >= 2)
		{
			ans *= negative[negative_index--];
			ans %= mod;
			ans *= negative[negative_index--];
			ans %= mod;
			ans *= modpow(positive[0], mod - 2);
			ans %= mod;
		}
		else if (zero_cnt)
		{
			//cout << 0 << endl;
			return (0);
		}
		else
		{
			ans = solve_inverse(positive, negative, k);
		}
	}
	//cout << ans << endl;
	return (ans);
}


int main(void)
{
    int cnt = 0;
    random_device rnd;
    while (1)
    {
        vector<int> a(5);
        for (int i = 0; i < 5; i++)
        {
            a[i] = (rnd() % (int)1e3) * (1 - 2 * (rnd() % 2));
        }
        long long ans = -4e18;
        for (int i = 0; i < (1 << 5); i++)
        {
            int cnt = 0;
            for (int j = 0; j < 5; j++) cnt += ((i >> j) & 1);
            if (cnt != 3) continue;
            long long tmp = 1;
            for (int j = 0; j < 5; j++)
            {
                if ((i >> j) & 1) tmp *= a[j];
            }
            ans = max(ans, tmp);
        }
        while (ans < 0) ans += mod;
        ans %= mod;
        long long ans2;
        if (ans != (ans2 = tester(5, 3, a)))
        {
            for (int i = 0; i < 5; i++) cout << a[i] << " ";
            cout << endl;
            cout << ans % mod << endl;
            break;
        }
        cout << cnt << " " << ans << endl;
    }
}