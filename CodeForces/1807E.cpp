#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

void solve() {
	int n; cin >> n;
	vector<int> a(n+1), prefix(n+1, 0);
	for(int i = 1; i <= n; ++i) cin >> a[i], prefix[i] = prefix[i-1] + a[i];

	int left = 1, right = n;
	while(left < right) {
		int mid = (left + right) / 2;
		int stones = prefix[mid] - prefix[left-1], weight;

		cout << "? " << (mid-left+1) << " ";
		for(int i = left; i <= mid; ++i) cout << i << " ";
		cout << endl;
		cin >> weight;

		if(stones == weight)
			left = mid+1;
		else
			right = mid;
	}
	cout << "! " << left << endl;
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

