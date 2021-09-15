#include<bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 2;
int res[MAX], cnt[MAX];
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		vector<pair<int, int>> idx;
		for (int i = 0; i < n; ++i)
		{
			int x; cin >> x; ++cnt[x];
			if (cnt[x] <= k)idx.push_back({ x,i });
		}
		sort(idx.begin(), idx.end());
		int sz = idx.size() - idx.size() % k;
		for (int i = 0; i < sz; ++i)
			res[idx[i].second] = i % k + 1, cnt[idx[i].first] = 0;
		for (int i = sz; i < idx.size(); ++i) cnt[idx[i].first] = 0;
		for (int i = 0; i < n; ++i) cout << res[i] << ' ', res[i] = 0;
		cout << endl;
	}
}
