#include<bits/stdc++.h>
using namespace std;
int main()
{
	int tc; cin >> tc;
	while (tc--)
	{
		vector<int> cnt(26, 0);
		int n, k, pair = 0; cin >> n >> k;
		string s; cin >> s;
		for (char c : s)
			++cnt[c - 'a'];
		for (int i = 0; i < 26; ++i)
			pair += cnt[i] / 2;
		//group characters into pairs and use that to determine max-min
		//basically, pretend as if all partitions has same max amount of pair, and use leftover to increase everyone
		//if there's enough character leftover >= x, length increase by 1

		//(pair % k) * 2 is leftover from unused pair. n - 2*pair is the number of single character 
		//i.e char with odd frequency that didn't form a pair
		cout << (pair / k) * 2 + ((pair % k) * 2 + n - 2 * pair >= k ? 1 : 0) << endl;

	}
}